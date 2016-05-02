#include "memory.h"

PointInfo* allocPoints(int count)
{
    return new PointInfo[count];
}
EdgeInfo* allocEdges(int count)
{
    return new EdgeInfo[count];
}
Model allocModel(void)
{
    Model model;
    model.edgeArrayInfo.vector = NULL;
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
    if(edgeArrayInfo->vector)
    {
        delete [] edgeArrayInfo->vector;
        edgeArrayInfo->vector = NULL;
    }
    edgeArrayInfo->count = 0;
}
void deallocModel(Model *model)
{
    deallocEdges(&model->edgeArrayInfo);
    deallocPoints(&model->pointArrayInfo);
}
