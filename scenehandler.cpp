#include "scenehandler.h"
#include "converthandler.h"

#include <QDebug>

void scene_clean_canvas(CanvasInfo canvasInfo)
{
    canvas_clear(canvasInfo);
}
void scene_draw_lines(CanvasInfo canvasInfo, PointInfo *pointVector, EdgeInfo *edgeVector, int edge_count)
{
    for (int i = 0; i < edge_count; i++)
    {
        canvas_draw_line(canvasInfo, pointVector[edgeVector[i].from], pointVector[edgeVector[i].to]);
    }
}

ErrorInfo scene_draw_model(ModelInfo *modelInfo, CanvasInfo canvasInfo, TransformInfo transformInfo)
{
    ErrorInfo error = eOk;
    PointVectorInfo *pointVectorInfo = NULL;

    error = convert_alloc_points(pointVectorInfo, modelInfo->edges.count);

    if (error == eOk)
    {
        convert_model_to_points(pointVectorInfo, modelInfo, transformInfo);
        scene_draw_lines(canvasInfo, pointVectorInfo->vector, modelInfo->edges.vector, modelInfo->edges.count );
        convert_dealloc_points(pointVectorInfo);
    }

    return error;
}
ErrorInfo scene_draw(CanvasInfo canvasInfo, ModelInfo *modelInfo, TransformInfo transformInfo)
{
    ErrorInfo error = eOk;

    scene_clean_canvas(canvasInfo);
    error = scene_draw_model(modelInfo, canvasInfo, transformInfo);

    return error;
}
