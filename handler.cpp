#include "handler.h"

ErrorInfo handle(ActionInfo action, ParamInfo param)
{
    ErrorInfo error = eOk;
    static ModelInfo model;

    switch (action)
    {
        case aLoad:
        {
            error = stream_load_model(&model, &(param.stream) );
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

    scene_draw_model(param.canvasInfo, model);

    return error;
}
