#ifndef CONVERTHANDLER_H
#define CONVERTHANDLER_H

#include "errorinfo.h"
#include "modelhandler.h"

struct LineInfo
{
    PointInfo startPoint;
    PointInfo endPoint;
};

struct LineVectorInfo
{
    int count;
    LineInfo *vector;
};

ErrorInfo convert_alloc_points(PointVectorInfo  *, int);
void  convert_dealloc_points(PointVectorInfo  *);
ErrorInfo convert_model_to_points(PointVectorInfo * , ModelInfo, TransformInfo);

#endif // CONVERTHANDLER_H
