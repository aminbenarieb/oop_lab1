#ifndef POINT_H
#define POINT_H

struct PointInfo
{
    double x, y, z;
};
struct PointArrayInfo
{
    int count;
    PointInfo *vector;
};

void rotatePointX(PointInfo *v, double angle);
void rotatePointY(PointInfo *v, double angle);
void rotatePointZ(PointInfo *v, double angle);
void scalePoint(PointInfo *v, double scale);

PointInfo* pointsAlloc(int);
void       pointsDealloc(PointArrayInfo*);

#endif // POINT_H
