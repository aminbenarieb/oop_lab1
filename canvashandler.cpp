#include "canvashandler.h"


void canvas_clear(CanvasInfo canvasInfo){
    canvasInfo.canvas->clear();
}

void canvas_draw_lines(CanvasInfo canvasInfo, LineVectorInfo lineVectorInfo)
{
    for (int i = 0; i <  lineVectorInfo.count; i++)
    {
        LineInfo lineInfo =  lineVectorInfo.vector[i];
        canvasInfo.canvas->drawLine(lineInfo.startPoint.x, lineInfo.startPoint.y, lineInfo.endPoint.x, lineInfo.endPoint.y);
    }
}
