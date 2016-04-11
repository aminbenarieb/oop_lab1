#include "handler.h"

ErrorInfo handle(ActionInfo action, ParamInfo *param)
{
    ErrorInfo error = eOk;
    static ModelInfo model;

    if (!param)
    {
        error = eNoArguments;
    }
    else
    {
        switch (action)
        {
            case aInit:
            {
                break;
            }
            case aLoad:
            {
                error = stream_load_model(&model, &(param->stream) );
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
    }

    return error;
}
