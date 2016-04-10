#include "filehandler.h"
#include <iostream>

// MARK: Allocation data

ErrorInfo file_points_alloc(PointArrayInfo *pointsArrayInfo)
{
    ErrorInfo error = eOk;
    pointsArrayInfo->vector = new PointInfo[pointsArrayInfo->count];

    if (!pointsArrayInfo->vector)
    {
        error = eOutOfMemory;
    }

    return error;
}
ErrorInfo file_edges_alloc(EdgeArrayInfo *edgesArrayInfo)
{
    ErrorInfo error = eOk;
    edgesArrayInfo->vector = new EdgeInfo[edgesArrayInfo->count];

    if (!edgesArrayInfo->vector)
    {
        error = eOutOfMemory;
    }

    return error;
}

// MARK: Deallocation data

void file_points_dealloc(PointArrayInfo *pointsArrayInfo)
{
    if (pointsArrayInfo)
    {
        delete pointsArrayInfo->vector;
        pointsArrayInfo->vector = NULL;
        pointsArrayInfo->count = 0;
    }

}
void file_points_dealloc(EdgeArrayInfo *edgesArrayInfo)
{
    if (edgesArrayInfo)
    {
        delete edgesArrayInfo->vector;
        edgesArrayInfo->vector = NULL;
        edgesArrayInfo->count = 0;
    }

}

// MARK: Loading data

ErrorInfo file_load_points(FILE *file, PointArrayInfo *pointArrayInfo)
{
    ErrorInfo error = eOk;

    for (int i = 0;  (i < pointArrayInfo->count) && (error == eOk);  i++)
    {
        error = file_load_point( file, &(pointArrayInfo->vector[i]) );
    }

    return error;
}
ErrorInfo file_load_edges(FILE *file, EdgeArrayInfo *edgesArrayInfo)
{
    ErrorInfo error = eOk;

    for (int i = 0;  (i < edgesArrayInfo->count) && (error == eOk);  i++)
    {
        error = file_load_edge( file, &(edgesArrayInfo->vector[i]) );
    }
    return error;
}

// MARK: Handling data

ErrorInfo file_handle_points(FILE *file, PointArrayInfo *pointArrayInfo){

    ErrorInfo error = file_load_count(file, pointArrayInfo->count);
    if (error == eOk)
    {
        error = file_points_alloc(pointArrayInfo);
        if (error == eOk)
        {
            error = file_load_points(file, pointArrayInfo);
        }

        if (error != eOk)
        {
            file_points_dealloc(pointArrayInfo);
        }
    }

    return error;
}
ErrorInfo file_handle_edges(FILE *file, EdgeArrayInfo *edgeArrayInfo){

    ErrorInfo error = file_load_count(file, edgeArrayInfo->count);
    if (error == eOk)
    {
        error = file_edges_alloc(edgeArrayInfo);
        if (error == eOk)
        {
            error = file_load_edges(file, edgeArrayInfo);
        }

        if (error != eOk)
        {
            file_points_dealloc(edgeArrayInfo);
        }
    }

    return error;
}
