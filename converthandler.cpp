#include "converthandler.h"
#include "matrixhandler.h"
#include <iostream>

//MARK: Memory managment

void convert_dealloc_points(PointVectorInfo  *&pointVectorInfo)
{
    if (pointVectorInfo)
        delete pointVectorInfo->vector;
    delete pointVectorInfo;
}
ErrorInfo convert_alloc_points(PointVectorInfo  *&pointVectorInfo, int count)
{
    ErrorInfo error = eOk;
    pointVectorInfo = new PointVectorInfo;
    if (pointVectorInfo)
    {
        PointInfo *vector = new PointInfo [count];
        if (vector)
        {
            pointVectorInfo->count = count;
            pointVectorInfo->vector = vector;
        }
        else
        {
            convert_dealloc_points(pointVectorInfo);
        }
    }

    if (!pointVectorInfo)
    {
        error = eOutOfMemory;
    }

    return error;
}

//MARK: Converstation methods

double* convert_get_matrix(TransformInfo transformInfo)
{
    ScaleInfo  *scaleInfo   = &(transformInfo.scaleInfo);
    RotateInfo *rotateInfo  = &(transformInfo.rotateInfo);
    ShiftInfo  *shiftInfo   = &(transformInfo.shiftInfo);

    double *shiftMatrix = matrix_get_shift(shiftInfo->dx, shiftInfo->dy, shiftInfo->dz);
    if (!shiftMatrix)
    {
        return NULL;
    }

    double *rotateZMatrix = matrix_get_rotation_z(rotateInfo->fz);
    if (!rotateZMatrix)
    {
        delete shiftMatrix;
        return NULL;
    }
    double *rotateYMatrix = matrix_get_rotation_y(rotateInfo->fy);
    if (!rotateYMatrix)
    {
        delete rotateZMatrix;
        delete shiftMatrix;
        return NULL;
    }
    double *rotateXMatrix = matrix_get_rotation_x(rotateInfo->fx);
    if (!rotateXMatrix)
    {
        delete shiftMatrix;
        delete rotateYMatrix;
        delete rotateZMatrix;
        return NULL;
    }

    double *scaleMatrix = matrix_get_scale(scaleInfo->value);
    if (!scaleMatrix)
    {
        delete shiftMatrix;
        delete rotateZMatrix;
        delete rotateYMatrix;
        delete rotateXMatrix;
        return NULL;
    }

    double *matr1 = matrix_mult_matrix(shiftMatrix, rotateZMatrix, 3);
    if (!matr1)
    {
        delete shiftMatrix;
        delete rotateZMatrix;
        delete rotateYMatrix;
        delete rotateXMatrix;
        delete scaleMatrix;
        return NULL;
    }
    double *matr2 = matrix_mult_matrix(matr1, rotateYMatrix, 3);
    if (!matr2)
    {
        delete shiftMatrix;
        delete rotateZMatrix;
        delete rotateYMatrix;
        delete rotateXMatrix;
        delete scaleMatrix;
        delete matr1;
        return NULL;
    }
    double *matr3 = matrix_mult_matrix(matr2, rotateXMatrix, 3);
    if (!matr3)
    {
        delete shiftMatrix;
        delete rotateZMatrix;
        delete rotateYMatrix;
        delete rotateXMatrix;
        delete scaleMatrix;
        delete matr2;
        delete matr1;
        return NULL;
    }

    double *result = matrix_mult_matrix(matr3, scaleMatrix, 3);
    if (!result)
    {
        delete shiftMatrix;
        delete rotateZMatrix;
        delete rotateYMatrix;
        delete rotateXMatrix;
        delete scaleMatrix;
        delete matr1;
        delete matr2;
        delete matr3;
        return NULL;
    }

    delete shiftMatrix;
    delete rotateZMatrix;
    delete rotateYMatrix;
    delete rotateXMatrix;
    delete scaleMatrix;
    delete matr1;
    delete matr2;
    delete matr3;

    return result;
}

ErrorInfo convert_single_point(PointInfo &convertPoint, PointInfo *modelPoint, double *matrix)
{
    ErrorInfo error = eOk;

    double *pointVector = new double[4];
    if (pointVector)
    {
        pointVector[0] = modelPoint->x;
        pointVector[1] = modelPoint->y;
        pointVector[2] = modelPoint->z;
        pointVector[3] = 1;

        double *conversion = matrix_mult_left_vector(pointVector, matrix, 3);
        if (conversion)
        {
            convertPoint.x = (int) conversion[0];
            convertPoint.y = (int) conversion[1];
        }
        else
        {
            error = eOutOfMemory;
        }

        delete conversion;
        delete pointVector;
    }
    else
    {
        error = eOutOfMemory;
    }

    return error;

}

ErrorInfo convert_model_to_points(PointVectorInfo *&pointVectorInfo, ModelInfo *modelInfo, TransformInfo transformInfo)
{

    ErrorInfo error = eOk;

    double *matrix = convert_get_matrix(transformInfo);
    if (matrix)
    {
        for (int i = 0; (i < modelInfo->points.count) && (error == eOk); i++)
           error = convert_single_point( pointVectorInfo->vector[i], modelInfo->points.vector + i, matrix );
    }
    else
    {
        error = eOutOfMemory;
    }


    return error;

}
