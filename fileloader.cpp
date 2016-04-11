#include "fileloader.h"

// MARK: Loading discrete data

ErrorInfo file_load_count(FILE *file, int *count)
{
    return fscanf(file, "%d", count) == 1 ? eOk : eFileCorrupted;
}

ErrorInfo file_load_point(FILE *file, PointInfo *point)
{
    return fscanf(file, "%lf %lf %lf", &(point->x), &(point->y), &(point->z)) == 3 ? eOk : eFileCorrupted;
}

ErrorInfo file_load_edge(FILE *file, EdgeInfo *edge)
{
    return fscanf(file, "%d %d", &(edge->from), &(edge->to) ) == 2 ? eOk : eFileCorrupted;
}


// MARK: Loading continuous data

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

