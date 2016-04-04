#ifndef HANDLER_H
#define HANDLER_H

#include "config.h"
#include "qpaintwidget.h"

//TEMP LOCATION
struct sMove
{
    double dx;
    double dy;
    double dz;
};
struct sCanvasContainter
{
    QPaintWidget *canvas;
};
enum fStatus {
    fOk,
    fNotFound,
    fCorrupted,
    fOutOfMemory,
    fUnknownError
};
//
enum hAction
{
    hInit,
    hLoad,
    hMove,
    hRotate,
    hScale
};


union hParam
{
    double scale;               // scaling
    sMove move;                 // moving (shifting, rotating)
    char *filename;             // model file name
    sCanvasContainter canvas;   // containter with canvas
};


fStatus handle(hAction action, hParam *param);


#endif // HANDLER_H
