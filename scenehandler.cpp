#include "scenehandler.h"
#include "converthandler.h"

void scene_clean_canvas(CanvasInfo canvasInfo)
{
    canvas_clear(canvasInfo);
}

ErrorInfo scene_draw_model(ModelInfo modelInfo, CanvasInfo canvasInfo, TransformInfo transformInfo)
{
    ErrorInfo error = eOk;
    LineVectorInfo lineVectorInfo;

    error = convert_alloc_lines(&lineVectorInfo, modelInfo.edges.count);
    if (error == eOk)
    {
        convert_model_to_lines(&lineVectorInfo, modelInfo);
        canvas_draw_lines(canvasInfo, lineVectorInfo);
        convert_dealloc_lines(&lineVectorInfo);
    }

    return error;
}

ErrorInfo scene_draw(CanvasInfo canvasInfo, ModelInfo modeInfo, TransformInfo transformInfo)
{
    ErrorInfo error = eOk;

    scene_clean_canvas(canvasInfo);
    error = scene_draw_model(modeInfo, canvasInfo, transformInfo);

    return error;
}
