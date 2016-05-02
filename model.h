#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "edge.h"

#include "error.h"
#include "arguments.h"

struct Model
{
    PointArrayInfo pointArrayInfo;
    EdgeArrayInfo  edgeArrayInfo;
};

ErrorInfo modelLoad(Model*, ArgumentInfo);
ErrorInfo modelTransform(Model*, ArgumentInfo);
ErrorInfo modelDraw(Model*, ArgumentInfo);

#endif // MODEL_H
