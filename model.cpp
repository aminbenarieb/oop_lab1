#include "model.h"
#include "file.h"
#include "memory.h"

bool modelExist(const Model *model)
{
    return (model->edgeArrayInfo.lines && model->pointArrayInfo.vector);
}
ErrorInfo modelFromFile(Model *model, const char *fileName)
{
    ErrorInfo error = ERROR_OK;
    FileInfo *fileStream = NULL;

    if( (fileStream = fileOpen(fileName)) != NULL)
    {
        Model bufferModel = allocModel();

        error = set_model(&bufferModel, fileStream);
        if( error == ERROR_OK)
        {
            deallocModel(model);
            *model = bufferModel;
        }
        fileClose(fileStream);
    }
    else
    {
        error = ERROR_FILE_NOT_EXIST;
    }

    return error;
}

ErrorInfo modelLoad(Model *model, ArgumentInfo argument)
{
    ErrorInfo error = ERROR_OK;
    StreamInfo *stream = argument.stream;

    switch(stream->sourceType)
    {
        case SOURCE_FILE:
        {
            error = modelFromFile(model, stream->sourceName);
            break;
        }
    }

    return error;
}
ErrorInfo modelTransform(Model *model, ArgumentInfo argument)
{
    ErrorInfo error = ERROR_OK;

    if(modelExist(model))
    {
        transformPointVector(&model->pointArrayInfo,argument.modification);
    }
    else
    {
        error =  ERROR_NOT_INIT;
    }

    return error;
}
ErrorInfo modelDraw(Model *model, ArgumentInfo argument)
{
    ErrorInfo error = ERROR_OK;

    if(modelExist(model))
    {
        draw_lines(argument,&model->pointArrayInfo,&model->edgeArrayInfo);
    }
    else
    {
        error =  ERROR_NOT_INIT;
    }

    return error;
}

