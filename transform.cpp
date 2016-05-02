#include "transform.h"
#include "math.h"

double degreeToRadians(double degree)
{
    return (degree * M_PI) / 180.0;
}

void rotatePointX(PointInfo *v, double angle)
{
    double y = v->y;
    double teta = degreeToRadians(angle);

    v->y = (v->y)*cos(teta) - (v->z)*sin(teta);
    v->z = (v->z)*cos(teta) + (y)*sin(teta);
}
void rotatePointY(PointInfo *v, double angle)
{
    double z = v->z;
    double teta = degreeToRadians(angle);

    v->z = (v->z)*cos(teta) - (v->x)*sin(teta);
    v->x = (v->x)*cos(teta) + (z)*sin(teta);

}
void rotatePointZ(PointInfo *v, double angle)
{
    double x = v->x;
    double teta = degreeToRadians(angle);

    v->x = (v->x)*cos(teta) - (v->y)*sin(teta);
    v->y = (v->y)*cos(teta) + (x)*sin(teta);

}
void scalePoint(PointInfo *v, double scale)
{
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}

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
