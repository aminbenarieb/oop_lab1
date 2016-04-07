#include "handler.h"
#include "QDebug"

ErrorInfo handle(ActionInfo action, ParamInfo *param)
{
    ErrorInfo error = eOk;
    static ModelInfo model = ModelInfo();

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
                error = stream_load_model(&model, param->stream);
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
                break;
            }
        }
    }

    return error;
}
