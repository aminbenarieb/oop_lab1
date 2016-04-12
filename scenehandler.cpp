#include "scenehandler.h"
#include "converthandler.h"

void scene_clean_canvas(CanvasInfo canvasInfo)
{
    canvas_clear(canvasInfo);
}
void scene_draw_line(PointInfo *pointVector, CanvasInfo canvasInfo,  EdgeInfo *edge)
{
    canvas_draw_line(canvasInfo, pointVector[edge->from], pointVector[edge->to]);
}
void scene_draw_lines(CanvasInfo canvasInfo, PointVectorInfo *pointVectorInfo, EdgeVectorInfo *edgeVectorInfo)
{
    for (int i = 0; i < edgeVectorInfo->count; i++)
    {
        scene_draw_line(pointVectorInfo->vector, canvasInfo, &(edgeVectorInfo->vector[i]) );
    }
}

ErrorInfo scene_draw_model(ModelInfo modelInfo, CanvasInfo canvasInfo, TransformInfo transformInfo)
{
    ErrorInfo error = eOk;
    PointVectorInfo pointVectorInfo;

    error = convert_alloc_points(&pointVectorInfo, modelInfo.points.count);
    if (error == eOk)
    {
        convert_model_to_points(&pointVectorInfo, modelInfo, transformInfo);
        scene_draw_lines(canvasInfo, &pointVectorInfo, &(modelInfo.edges) );
        convert_dealloc_points(&pointVectorInfo);
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
