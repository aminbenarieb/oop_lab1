#include "canvashandler.h"


void canvas_clear(CanvasInfo canvasInfo){
    canvasInfo.canvas->clear();
}

void canvas_draw_line(CanvasInfo canvasInfo, PointInfo startPoint, PointInfo endPoint)
{
    canvasInfo.canvas->drawLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}
