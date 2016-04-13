#include "steamhandler.h"
#include "filehandler.h"

#include <QDebug>

ErrorInfo stream_load_model(ModelInfo *&model, StreamInfo* streamInfo)
{
    ErrorInfo error = eOk;

    //open file
    error = stream_open_model(streamInfo);
    if (error == eOk){

        // processing file
        error = stream_handle_model(model, *streamInfo);

        // closing file
        stream_close_model(streamInfo);
    }

    return error;
}

// MARK: Stream load parts

ErrorInfo stream_handle_model(ModelInfo *&model, StreamInfo streamInfo)
{
    ErrorInfo error = eOk;
    ModelInfo *bufferModelInfo = modelinfo_alloc();

    if (bufferModelInfo)
    {
        error = file_handle_points(streamInfo.file, bufferModelInfo->points);
        if (error == eOk)
        {
            error = file_handle_edges(streamInfo.file, bufferModelInfo->edges);
            if (error == eOk)
            {
                modelinfo_dealloc( model );
                model = bufferModelInfo;
                /* model->next =  bufferModelInfo; */
            }
            else
            {
                modelinfo_dealloc( bufferModelInfo );
            }
        }
        else
        {
            modelinfo_dealloc( bufferModelInfo );
        }
    }
    else
    {
        error = eOutOfMemory;
    }

    return error;
}

ErrorInfo stream_open_model(StreamInfo *streamInfo)
{
    ErrorInfo error = eOk;
    streamInfo->file = fopen(streamInfo->filename, "r");

    if (!streamInfo->file)
    {
        error = eFileNotFound;
    }

    return error;
}

void stream_close_model(StreamInfo* streamInfo)
{
    fclose(streamInfo->file);
}
