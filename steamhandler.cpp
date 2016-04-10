#include "steamhandler.h"
#include "filehandler.h"

ErrorInfo stream_load_model(ModelInfo *model, StreamInfo streamInfo)
{
    ErrorInfo error = eOk;

    //open file
    error = stream_open_model(streamInfo);
    if (error == eOk){

        // processing file
        error = stream_handle_model(model, streamInfo);

        // closing file
        stream_close_model(streamInfo);
    }

    return error;
}

// MARK: Stream load parts

ErrorInfo stream_handle_model(ModelInfo *model, StreamInfo streamInfo)
{
    ErrorInfo error = eOk;
    ModelInfo bufferModelInfo = /*memory allocation*/ModelInfo();

    if (/*bufferModelInfo*/false)
    {
        error = file_handle_points(streamInfo.file, /*model->pointarray*/ new PointArrayInfo);
        if (error == eOk)
        {
            error = file_handle_edges(streamInfo.file, /*model->edgesarray*/ new EdgeArrayInfo);
            if (error == eOk)
            {
                //append model to modelStack
            }
            else
            {
                //release bufferModelInfo
            }
        }
        else
        {
            //release bufferModelInfo
        }
    }
    else
    {
        error = eOutOfMemory;
    }

    return error;
}

ErrorInfo stream_open_model(StreamInfo streamInfo)
{
    ErrorInfo error = eOk;
    streamInfo.file = fopen(streamInfo.filename, "r");

    if (!streamInfo.file)
    {
        error = eFileNotFound;
    }

    return error;
}

void stream_close_model(StreamInfo streamInfo)
{
    fclose(streamInfo.file);
}
