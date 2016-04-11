#ifndef MODELHANDLER_H
#define MODELHANDLER_H

#include "modeldata.h"

struct MoveInfo
{
    double dx;
    double dy;
    double dz;
};
struct ScaleInfo
{
    double value;
};

struct ModelInfo
{
    PointVectorInfo points;
    EdgeVectorInfo  edges;
};

ModelInfo* modelinfo_alloc();
void modelinfo_dealloc(ModelInfo *);


#endif // MODELHANDLER_H
