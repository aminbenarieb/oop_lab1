#ifndef HANDLER_H
#define HANDLER_H

#include "error.h"
#include "arguments.h"

enum ActionInfo
{
    ACTION_LOAD,
    ACTION_CHANGE,
    ACTION_DRAW,
    ACTION_QUIT
};

ErrorInfo handler(ActionInfo, ArgumentInfo);

#endif // HANDLER_H
