#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include "qpaintwidget.h"
#include "converthandler.h"

struct CanvasInfo
{
    QPaintWidget *canvas;
};


void canvas_draw_line(CanvasInfo canvasInfo, PointInfo, PointInfo);
void canvas_clear(CanvasInfo);


#endif // CANVASHANDLER_H
