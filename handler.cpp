#include "handler.h"
#include "model.h"

ErrorInfo handler(ActionInfo action, ArgumentInfo argument)
{
    static Model model = modeInit();

    ErrorInfo error = ERROR_OK;

    switch(action)
    {
        case ACTION_CHANGE:
        {
            error = modelTransform(&model, &argument.modification);
            break;
        }

        case ACTION_LOAD:
        {
            error = modelLoad(&model, argument.stream);
            break;
        }

        case ACTION_DRAW:
        {
            error = modelDraw(&model, argument.scene);
            break;
        }

        case ACTION_QUIT:
        {
            modelDealloc(&model);
            break;
        }
    }

    return error;
}
