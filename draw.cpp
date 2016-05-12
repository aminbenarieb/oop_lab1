#include "draw.h"

void drawEdge(SceneInfo *scene, const PointInfo *fromPoint, const PointInfo *toPoint)
{
    scene->instance->addLine(fromPoint->x, fromPoint->y, toPoint->x, toPoint->y);
}

PointInfo *getFromPoint(const PointArrayInfo *vertexes, const EdgeInfo *edge)
{
    return &vertexes->vector[ edge->from-1 ];
}
PointInfo *getToPoint(const PointArrayInfo *vertexes, const EdgeInfo *edge)
{
    return &vertexes->vector[ edge->to-1 ];
}

void drawEdges(SceneInfo *scene, const PointArrayInfo *vertexes, const EdgeArrayInfo *edgeArrayInfo)
{
    const PointInfo *fromPoint, *toPoint;

    for(int i = 0; i < edgeArrayInfo->count; i++)
    {
        fromPoint = getFromPoint(vertexes, &edgeArrayInfo->vector[i]);
        toPoint = getToPoint(vertexes, &edgeArrayInfo->vector[i]);

        drawEdge(scene, fromPoint, toPoint);
    }
}
