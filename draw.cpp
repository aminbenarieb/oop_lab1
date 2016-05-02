#include "draw.h"

void drawEdge(ArgumentInfo argument, const PointInfo *fromPoint, const PointInfo *toPoint)
{
    argument.scene.instance->addLine(fromPoint->x, fromPoint->y, toPoint->x, toPoint->y);
}

void drawEdges(ArgumentInfo argument, const PointArrayInfo *vertexes, const EdgeArrayInfo *edgeArrayInfo)
{
    const PointInfo *fromPoint, *toPoint;
    int index;

    for(int i = 0; i < edgeArrayInfo->count; i++)
    {
        index = edgeArrayInfo->vector[i].from-1;
        fromPoint = &vertexes->vector[index];

        index = edgeArrayInfo->vector[i].to-1;
        toPoint = &vertexes->vector[index];

        drawEdge(argument, fromPoint, toPoint);
    }
}
