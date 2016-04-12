#ifndef CONVERTHANDLER_H
#define CONVERTHANDLER_H

#include "errorinfo.h"
#include "modelhandler.h"

ErrorInfo convert_alloc_points(PointVectorInfo  *, int);
void  convert_dealloc_points(PointVectorInfo  *);
ErrorInfo convert_model_to_points(PointVectorInfo * , ModelInfo, TransformInfo);

#endif // CONVERTHANDLER_H
