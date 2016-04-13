#include "matrixhandler.h"
#include <math.h>
#include <iostream>

//MARK: Multiplication on vector & matrix

double *matrix_mult_left_vector(double *vector, double *matrix, int d)
{

    d++;
    double *result = new double[d];
    if (result)
    {
        for (int i = 0; i < d; i++)
        {
            double s = 0;
            for (int j = 0; j < d; j++)
            {
                s += vector[j] * matrix[j*d + i];
            }
            result[i] = s;
        }
    }
    else
    {
        result = NULL;
    }

    return result;

}
double *matrix_mult_matrix(double *matrix1, double *matrix2, int d)
{

    d++;
    double *result = new double[d*d];
    if (result)
    {
        for (int i = 0; i < d; i++)
        {

            for (int j = 0; j < d; j++)
            {
                double s = 0;
                for (int k = 0; k < d; k++)
                {
                    s += matrix1[i*d + k] * matrix2[k*d + j];
                }
                result[i*d + j] = s;
            }
        }
    }
    else
    {
        result = NULL;
    }

    return result;

}

//MARK: Rotation matrix

double *matrix_get_rotation_x(double angle)
{

    double *matrix = new double[16];
    if (matrix)
    {
        matrix[0] = 1;
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = cos(angle);
        matrix[6] = -sin(angle);
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = sin(angle);
        matrix[10] = cos(angle);
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;
    }
    else
    {
        matrix = NULL;
    }

    return matrix;

}
double *matrix_get_rotation_y(double angle)
{

    double *matrix = new double[16];
    if (matrix)
    {
        matrix[0] = cos(angle);
        matrix[1] = 0;
        matrix[2] = sin(angle);
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = 1;
        matrix[6] = 0;
        matrix[7] = 0;

        matrix[8] = -sin(angle);
        matrix[9] = 0;
        matrix[10] = cos(angle);
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;
    }
    else
    {
        matrix = NULL;
    }

    return matrix;

}
double *matrix_get_rotation_z(double angle)
{

    double *matrix = new double[16];
    if (matrix)
    {
        matrix[0] = cos(angle);
        matrix[1] = -sin(angle);
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = sin(angle);
        matrix[5] = cos(angle);
        matrix[6] = 0;
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = 0;
        matrix[10] = 1;
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;
    }
    else
    {
        matrix = NULL;
    }

    return matrix;

}

//MARK: Shift matrix

double *matrix_get_shift(double dx, double dy, double dz)
{
    double *matrix = new double[16];
    if (!matrix)
    {
        matrix[0] = 1;
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = 1;
        matrix[6] = 0;
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = 0;
        matrix[10] = 1;
        matrix[11] = 0;

        matrix[12] = dx;
        matrix[13] = dy;
        matrix[14] = dz;
        matrix[15] = 1;
    }
    else
    {
        matrix = NULL;
    }

    return matrix;


}

//MARK: Scale matrix

double *matrix_get_scale(double scale)
{

    double *matrix = new double[16];
    if (!matrix)
    {
        matrix[0] = scale;
        matrix[1] = 0;
        matrix[2] = 0;
        matrix[3] = 0;

        matrix[4] = 0;
        matrix[5] = scale;
        matrix[6] = 0;
        matrix[7] = 0;

        matrix[8] = 0;
        matrix[9] = 0;
        matrix[10] = scale;
        matrix[11] = 0;

        matrix[12] = 0;
        matrix[13] = 0;
        matrix[14] = 0;
        matrix[15] = 1;
    }
    else
    {
        matrix = NULL;
    }

    return matrix;

}
