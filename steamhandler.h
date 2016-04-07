#ifndef STEAMHANDLER_H
#define STEAMHANDLER_H
#include "errorinfo.h"
#include "modelhandler.h"

struct StreamInfo
{
    char *filename;
};

ErrorInfo stream_load_model(ModelInfo *model, StreamInfo streamInfo);

ErrorInfo stream_process_model(StreamInfo);
ErrorInfo stream_open_model(StreamInfo);
void stream_close_model(StreamInfo);

#endif // STEAMHANDLER_H
