#ifndef MODEL_H
#define MODEL_H

#include "error.h"

#include "point.h"
#include "edge.h"

#include "transform.h"
#include "draw.h"
#include "stream.h"


struct Model
{
    PointArrayInfo pointArrayInfo;
    EdgeArrayInfo  edgeArrayInfo;
};

ErrorInfo modelLoad(Model*, StreamInfo *);
ErrorInfo modelTransform(Model*, TransformInfo *);
ErrorInfo modelDraw(Model*, SceneInfo *);

Model     modeInit(void);
void      modelDealloc(Model*);


#endif // MODEL_H
