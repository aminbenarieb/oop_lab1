#include "fileloader.h"

ErrorInfo file_load_count(FILE *file, int &count)
{
    ErrorInfo error = eOk;
    if (fscanf(file, "%d", &count) != 1)
    {
        error = eFileCorrupted;
    }

    return error;
}

ErrorInfo file_load_point(FILE *file, PointInfo *point)
{
    ErrorInfo error = eOk;
    if (fscanf(file, "%lf %lf %lf", &point->x, &point->y, &point->z) != 3)
    {
        error = eFileCorrupted;
    }

    return eOk;
}

ErrorInfo file_load_edge(FILE *file, EdgeInfo *edge)
{
    ErrorInfo error = eOk;
    if (fscanf(file, "%d %d", &edge->from, &edge->to) != 2)
    {
        error = eFileCorrupted;
    }

    return eOk;
}
