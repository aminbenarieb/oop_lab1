#ifndef MODELHANDLER_H
#define MODELHANDLER_H

#include "modeldata.h"

struct ShiftInfo
{
    double dx;
    double dy;
    double dz;
};
struct RotateInfo
{
    double fx;
    double fy;
    double fz;
};
struct ScaleInfo
{
    double value;
};

struct TransformInfo
{
    ScaleInfo scaleInfo;
    ShiftInfo  shiftInfo;
    RotateInfo rotateInfo;
};

struct ModelInfo
{
    PointVectorInfo points;
    EdgeVectorInfo  edges;
};

ModelInfo* modelinfo_alloc();
void modelinfo_dealloc(ModelInfo *);


#endif // MODELHANDLER_H
