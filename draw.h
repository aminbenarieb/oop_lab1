#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsScene.h>
#include "point.h"
#include "edge.h"

struct SceneInfo
{
    QGraphicsScene *instance;
};


void drawEdges(QGraphicsScene *scene, const PointArrayInfo*, const EdgeArrayInfo*);

#endif // DRAW_H
