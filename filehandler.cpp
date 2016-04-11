#include "filehandler.h"
#include <iostream>
#include "datahandler.h"

// MARK: Loading data

ErrorInfo file_load_points(FILE *file, PointVectorInfo *pointArrayInfo)
{
    ErrorInfo error = eOk;

    for (int i = 0;  (i < pointArrayInfo->count) && (error == eOk);  i++)
    {
        error = file_load_point( file, &(pointArrayInfo->vector[i]) );
    }

    return error;
}
ErrorInfo file_load_edges(FILE *file, EdgeVectorInfo *edgesArrayInfo)
{
    ErrorInfo error = eOk;

    for (int i = 0;  (i < edgesArrayInfo->count) && (error == eOk);  i++)
    {
        error = file_load_edge( file, &(edgesArrayInfo->vector[i]) );
    }
    return error;
}

// MARK: Handling data

ErrorInfo file_handle_points(FILE *file, PointVectorInfo *pointArrayInfo){

    ErrorInfo error = file_load_count(file, &(pointArrayInfo->count));
    if (error == eOk)
    {
        error = datahandler_points_alloc(pointArrayInfo);
        if (error == eOk)
        {
            error = file_load_points(file, pointArrayInfo);
        }

        if (error != eOk)
        {
             datahandler_points_dealloc(pointArrayInfo);
        }
    }

    return error;
}
ErrorInfo file_handle_edges(FILE *file, EdgeVectorInfo *edgeArrayInfo){

    ErrorInfo error = file_load_count(file, &(edgeArrayInfo->count) );
    if (error == eOk)
    {
        error = datahandler_edges_alloc(edgeArrayInfo);
        if (error == eOk)
        {
            error = file_load_edges(file, edgeArrayInfo);
        }

        if (error != eOk)
        {
             datahandler_edges_dealloc(edgeArrayInfo);
        }
    }

    return error;
}
