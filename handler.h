#ifndef HANDLER_H
#define HANDLER_H

#include "error.h"

#include "draw.h"
#include "transform.h"
#include "stream.h"

enum ActionInfo
{
    ACTION_LOAD,
    ACTION_CHANGE,
    ACTION_DRAW,
    ACTION_QUIT
};

union ArgumentInfo
{
    StreamInfo *stream;
    SceneInfo  *scene;
    TransformInfo modification;
};

ErrorInfo handler(ActionInfo, ArgumentInfo);

#endif // HANDLER_H
