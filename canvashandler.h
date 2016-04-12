#ifndef CANVASHANDLER_H
#define CANVASHANDLER_H

#include "qpaintwidget.h"
#include "converthandler.h"

struct CanvasInfo
{
    QPaintWidget *canvas;
};


void canvas_draw_lines(CanvasInfo, LineVectorInfo );
void canvas_clear(CanvasInfo);


#endif // CANVASHANDLER_H
