#include "model.h"

#include "file.h"
#include "memory.h"
#include "draw.h"

bool modelExist(const Model *model)
{
    return (model->edgeArrayInfo.vector && model->pointArrayInfo.vector);
}
ErrorInfo modelFromFile(Model *model, const char *fileName)
{
    ErrorInfo error = ERROR_OK;
    FileInfo *fileStream = NULL;

    if( ( error = fileOpen(fileStream, fileName) ) == ERROR_OK)
    {
        Model bufferModel = allocModel();
        if( ( error = fileLoadModel(&bufferModel, fileStream) ) == ERROR_OK)
        {
            deallocModel(model);
            *model = bufferModel;
        }
        fileClose(fileStream);
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
        drawEdges(argument,&model->pointArrayInfo,&model->edgeArrayInfo);
    }
    else
    {
        error =  ERROR_NOT_INIT;
    }

    return error;
}

