#include "fileloader.h"

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
