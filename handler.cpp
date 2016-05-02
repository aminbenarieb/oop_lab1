#include "handler.h"
#include "model.h"
#include "memory.h"

ErrorInfo handler(ActionInfo action, ArgumentInfo argument)
{
    static Model model = init_model();

    ErrorInfo error = ERROR_OK;

    switch(action)
    {
        case ACTION_CHANGE:
        {
            error = change_model(&model, argument);
            break;
        }

        case ACTION_LOAD:
        {
            error = load_model(&model,argument);
            break;
        }

        case ACTION_DRAW:
        {
            error = draw_model(&model, argument);
            break;
        }

        case ACTION_QUIT:
        {
            delete_model(&model);
            break;
        }
    }

    return error;
}
