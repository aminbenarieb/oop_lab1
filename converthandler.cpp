#include "converthandler.h"


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


ErrorInfo convert_model_to_points(PointVectorInfo *&pointVectorInfo, ModelInfo *modelInfo, TransformInfo transformInfo)
{

    ErrorInfo error = eOk;

    //try with error: modelInfo.points >> pointVectorInfo using transformInfo;

    return eOk;

}
