#include "memory.h"

PointInfo* allocPoints(int count)
{
    return new PointInfo[count];
}
Edge* allocEdges(int count)
{
    return new Edge[count];
}
Model allocModel(void)
{
    Model model;
    model.edgeArrayInfo.lines = NULL;
    model.edgeArrayInfo.count = 0;
    model.pointArrayInfo.vector = NULL;
    model.pointArrayInfo.count = 0;
    return model;
}

void deallocPoints(PointArrayInfo *pointVectorInfo)
{
    if(pointVectorInfo->vector)
    {
        delete [] pointVectorInfo->vector;
        pointVectorInfo->vector = NULL;
    }
    pointVectorInfo->count = 0;
}
void deallocEdges(EdgeArrayInfo *edgeArrayInfo)
{
    if(edgeArrayInfo->lines)
    {
        delete [] edgeArrayInfo->lines;
        edgeArrayInfo->lines = NULL;
    }
    edgeArrayInfo->count = 0;
}
void deallocModel(Model *model)
{
    deallocEdges(&model->edgeArrayInfo);
    deallocPoints(&model->pointArrayInfo);
}
