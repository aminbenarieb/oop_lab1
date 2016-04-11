#include "scenehandler.h"


void scene_clean_canvas(CanvasInfo canvasInfo)
{
    // cleaning canvas
}

void scene_draw_lines(CanvasInfo canvasInfo)
{
    // drawing lines on canvas
}

ErrorInfo scene_draw_model(CanvasInfo canvasInfo, ModelInfo modeInfo)
{

    ErrorInfo error = eOk;

    scene_clean_canvas(canvasInfo);
    scene_draw_lines(canvasInfo);

    return error;
}
