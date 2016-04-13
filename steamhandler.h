#ifndef STEAMHANDLER_H
#define STEAMHANDLER_H

#include <iostream>
#include "errorinfo.h"
#include "modelhandler.h"


struct StreamInfo
{
    char *filename;
    FILE *file;
};

ErrorInfo stream_load_model(ModelInfo *&, StreamInfo*);

ErrorInfo stream_handle_model(ModelInfo *&, StreamInfo);
ErrorInfo stream_open_model(StreamInfo*);
void stream_close_model(StreamInfo*);

#endif // STEAMHANDLER_H
