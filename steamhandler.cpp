#include "steamhandler.h"

ErrorInfo stream_load_model(ModelInfo *model, StreamInfo streamInfo)
{
    ErrorInfo error;

    //open file
    error = stream_open_model(streamInfo);
    if (error == eOk){

        // processing file
        error = stream_process_model(streamInfo);
        if (error == eOk)
        {
            // adding data to model
        }

        // closing file
        stream_close_model(streamInfo);
    }

    return error;
}

ErrorInfo stream_process_model(StreamInfo streamInfo)
{
    return eOk;
}

ErrorInfo stream_open_model(StreamInfo streamInfo)
{


    return eOk;
}

void stream_close_model(StreamInfo streamInfo)
{
}
