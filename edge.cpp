#import "edge.h"
#include <iostream>

EdgeInfo* edgesAlloc(int count)
{
    return new EdgeInfo[count];
}

void edgesDealloc(EdgeArrayInfo *edgeArrayInfo)
{
    delete [] edgeArrayInfo->vector;
    edgeArrayInfo->vector = NULL;
    edgeArrayInfo->count = 0;
}
