#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "errorinfo.h"
#include "fileloader.h"

struct PointArrayInfo
{
    int count;
    PointInfo *vector;
};

struct EdgeArrayInfo
{
    int count;
    EdgeInfo *vector;
};


ErrorInfo file_points_alloc(PointArrayInfo *);
ErrorInfo file_edges_alloc(EdgeArrayInfo *);

void file_points_dealloc(PointArrayInfo *);
void file_edges_dealloc(EdgeArrayInfo *);

ErrorInfo file_handle_points(FILE *, PointArrayInfo *);
ErrorInfo file_handle_edges(FILE *, EdgeArrayInfo *);

#endif // FILEHANDLER_H
