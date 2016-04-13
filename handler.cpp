#include "handler.h"

#include "QDebug"

ErrorInfo handle(ActionInfo action, ParamInfo param)
{
    ErrorInfo error = eOk;
    static ModelInfo *model = modelinfo_alloc();

    switch (action)
    {
        case aLoad:
        {
            error = stream_load_model(model, &(param.stream) );
            break;
        }
        case aDraw:
        {
            error = scene_draw(param.canvasInfo, model, param.transformInfo);
            break;
        }
        case aMove:
        {
            break;
        }
        case aRotate:
        {
            break;
        }
        case aScale:
        {
            break;
        }
        default:
        {
            error = eInvalidAction;
            break;
        }
    }

    return error;
}
