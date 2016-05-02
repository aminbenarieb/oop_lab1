#include "handler.h"
#include "memory.h"

ErrorInfo handler(ActionInfo action, ArgumentInfo argument)
{
    static Model model = allocModel();

    ErrorInfo error = ERROR_OK;

    switch(action)
    {
        case ACTION_CHANGE:
        {
            error = modelTransform(&model, argument);
            break;
        }

        case ACTION_LOAD:
        {
            error = modelLoad(&model,argument);
            break;
        }

        case ACTION_DRAW:
        {
            error = modelDraw(&model, argument);
            break;
        }

        case ACTION_QUIT:
        {
            deallocModel(&model);
            break;
        }
    }

    return error;
}
