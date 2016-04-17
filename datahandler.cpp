#include "datahandler.h"
#include <iostream>

// MARK: Allocation data

ErrorInfo datahandler_points_alloc(PointVectorInfo &pointsArrayInfo)
{
    ErrorInfo error = eOk;
    pointsArrayInfo.vector = new PointInfo[pointsArrayInfo.count];

    if (!pointsArrayInfo.vector)
    {
        error = eOutOfMemory;
    }

    return error;
}
ErrorInfo datahandler_edges_alloc(EdgeVectorInfo &edgesArrayInfo)
{
    ErrorInfo error = eOk;
    edgesArrayInfo.vector = new EdgeInfo[edgesArrayInfo.count];

    if (!edgesArrayInfo.vector)
    {
        error = eOutOfMemory;
    }

    return error;
}

// MARK: Deallocation data

void  datahandler_points_dealloc(PointVectorInfo &pointsArrayInfo)
{

    delete pointsArrayInfo.vector;
    pointsArrayInfo.vector = NULL;
    pointsArrayInfo.count = 0;


}
void  datahandler_edges_dealloc(EdgeVectorInfo &edgesArrayInfo)
{

    delete edgesArrayInfo.vector;
    edgesArrayInfo.vector = NULL;
    edgesArrayInfo.count = 0;

}
