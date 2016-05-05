#import "edge.h"
#include <iostream>

EdgeInfo* allocEdges(int count)
{
    return new EdgeInfo[count];
}

void deallocEdges(EdgeArrayInfo *edgeArrayInfo)
{
    delete [] edgeArrayInfo->vector;
    edgeArrayInfo->vector = NULL;
    edgeArrayInfo->count = 0;
}
