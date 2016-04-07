#ifndef HANDLER_H
#define HANDLER_H

#include "config.h"

#include "errorinfo.h"

#include "canvashandler.h"
#include "steamhandler.h"
#include "scenehandler.h"
#include "modelhandler.h"


enum ActionInfo
{
    aInit,
    aLoad,
    aMove,
    aRotate,
    aScale,
    aDraw
};


union ParamInfo
{
    ScaleInfo  scale;    // scaling
    MoveInfo   move;     // moving (shifting, rotating)
    StreamInfo stream;   // input data stream
    CanvasInfo canvas;   // containter with canvas
};


ErrorInfo handle(ActionInfo action, ParamInfo *param);


#endif // HANDLER_H
