#include "transform.h"

void rotateVectorX(PointArrayInfo *v, TransformInfo transformInfo)
{
    for(int i = 0; i < v->count; i++)
    {
        rotatePointX(v->vector+i, transformInfo.delta);
    }
}
void rotateVectorY(PointArrayInfo *v, TransformInfo transformInfo)
{
    for(int i = 0; i < v->count; i++)
    {
        rotatePointY(v->vector+i, transformInfo.delta);
    }
}
void rotateVectorZ(PointArrayInfo *v, TransformInfo transformInfo)
{
    for(int i = 0; i < v->count; i++)
    {
        rotatePointZ(v->vector+i, transformInfo.delta);
    }
}
void scaleVector(PointArrayInfo *v, TransformInfo transformInfo)
{
    for(int i = 0; i < v->count; i++)
    {
        scalePoint(v->vector+i, transformInfo.delta);
    }
}

void transformPointVector(PointArrayInfo *pointVectorInfo, TransformInfo transformInfo)
{
    switch(transformInfo.type)
    {
        case(TRANSFORM_ROTATE_X):
        {
            rotateVectorX(pointVectorInfo, transformInfo);
            break;
        }
        case(TRANSFORM_ROTATE_Y):
        {
            rotateVectorY(pointVectorInfo, transformInfo);
            break;
        }
        case(TRANSFORM_ROTATE_Z):
        {
            rotateVectorZ(pointVectorInfo, transformInfo);
            break;
        }
        case(TRANSFORM_SCALE):
        {
            scaleVector(pointVectorInfo, transformInfo);
            break;
        }
    }
}
