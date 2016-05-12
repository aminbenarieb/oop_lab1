#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "point.h"

enum TransformType
{
    TRANSFORM_ROTATE_X,
    TRANSFORM_ROTATE_Y,
    TRANSFORM_ROTATE_Z,
    TRANSFORM_SCALE
};
struct TransformInfo
{
    TransformType type;
    double delta;
};

void transformPointVector(PointArrayInfo*, TransformInfo);

#endif // TRANSFORM_H
