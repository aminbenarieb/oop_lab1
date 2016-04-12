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

void                 convert_model_to_lines(LineVectorInfo * , ModelInfo);
void                 convert_dealloc_lines(LineVectorInfo *);
ErrorInfo            convert_alloc_lines(LineVectorInfo *, int);


#endif // CONVERTHANDLER_H
