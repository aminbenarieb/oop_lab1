#include "model.h"


bool modelExist(const Model *model)
{
    return (model->edgeArrayInfo.vector && model->pointArrayInfo.vector);
}

ErrorInfo modelLoad(Model *model, StreamInfo *stream)
{
    ErrorInfo error = ERROR_OK;

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
ErrorInfo modelTransform(Model *model, TransformInfo *modification)
{
    ErrorInfo error = ERROR_OK;

    if(modelExist(model))
    {
        transformPointVector(&model->pointArrayInfo, *modification);
    }
    else
    {
        error =  ERROR_NOT_INIT;
    }

    return error;
}
ErrorInfo modelDraw(Model *model, SceneInfo *scene)
{
    ErrorInfo error = ERROR_OK;

    if(modelExist(model))
    {
        drawEdges(scene, &model->pointArrayInfo, &model->edgeArrayInfo);
    }
    else
    {
        error =  ERROR_NOT_INIT;
    }

    return error;
}

Model modelAlloc(void)
{
    Model model;
    model.edgeArrayInfo.vector = NULL;
    model.edgeArrayInfo.count = 0;
    model.pointArrayInfo.vector = NULL;
    model.pointArrayInfo.count = 0;
    return model;
}
void  modelDealloc(Model *model)
{
    deallocEdges(&model->edgeArrayInfo);
    deallocPoints(&model->pointArrayInfo);
}

