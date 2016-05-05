#import "point.h"
#include <iostream>
#include "math.h"


void rotatePointX(PointInfo *v, double teta)
{
    double y = v->y;

    v->y = (v->y)*cos(teta) - (v->z)*sin(teta);
    v->z = (v->z)*cos(teta) + (y)*sin(teta);
}
void rotatePointY(PointInfo *v, double teta)
{
    double z = v->z;

    v->z = (v->z)*cos(teta) - (v->x)*sin(teta);
    v->x = (v->x)*cos(teta) + (z)*sin(teta);

}
void rotatePointZ(PointInfo *v, double teta)
{
    double x = v->x;

    v->x = (v->x)*cos(teta) - (v->y)*sin(teta);
    v->y = (v->y)*cos(teta) + (x)*sin(teta);

}
void scalePoint(PointInfo *v, double scale)
{
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;
}


PointInfo* allocPoints(int count)
{
    return new PointInfo[count];
}
void deallocPoints(PointArrayInfo *pointVectorInfo)
{
    delete [] pointVectorInfo->vector;
    pointVectorInfo->vector = NULL;
    pointVectorInfo->count = 0;
}
