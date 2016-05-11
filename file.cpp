#include "file.h"

ErrorInfo loadCount(int *count, const FileInfo *fileStream)
{
    return fscanf(fileStream->instance,"%d",count) == 1 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}
ErrorInfo loadPoint(PointInfo *point, const FileInfo *fileStream)
{
    return fscanf(fileStream->instance, "%lf %lf %lf", &point->x, &point->y, &point->z) == 3 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}
ErrorInfo loadEdge (EdgeInfo *edge, const FileInfo *fileStream)
{
    return fscanf(fileStream->instance, "%d %d", &edge->from, &edge->to) == 2 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}

ErrorInfo loadPoints( PointArrayInfo *pointArrayInfo, const FileInfo *fileStream)
{
    ErrorInfo error = ERROR_OK;

    for (int i = 0;  (i < pointArrayInfo->count) && (error == ERROR_OK);  i++)
    {
        error = loadPoint( &pointArrayInfo->vector[i], fileStream);
    }

    return error;
}
ErrorInfo loadEdges( EdgeArrayInfo *edgeArrayInfo, const FileInfo *fileStream)
{
    ErrorInfo error = ERROR_OK;

    for (int i = 0;  (i < edgeArrayInfo->count) && (error == ERROR_OK);  i++)
    {
        error = loadEdge( &edgeArrayInfo->vector[i], fileStream);
    }

    return error;
}

ErrorInfo handlePointArray(PointArrayInfo *pointArrayInfo, const FileInfo *fileStream){

    ErrorInfo error = loadCount(&pointArrayInfo->count, fileStream);
    if (error == ERROR_OK)
    {
        pointArrayInfo->vector = pointsAlloc(pointArrayInfo->count);
        if (error == ERROR_OK)
        {
            error = loadPoints(pointArrayInfo, fileStream);
        }

        if (error != ERROR_OK)
        {
             pointsDealloc(pointArrayInfo);
        }
    }

    return error;
}
ErrorInfo handleEdgeArray(EdgeArrayInfo *edgeArrayInfo, const FileInfo *fileStream){

    ErrorInfo error = loadCount(&edgeArrayInfo->count, fileStream);
    if (error == ERROR_OK)
    {
        edgeArrayInfo->vector = edgesAlloc(edgeArrayInfo->count);
        if (error == ERROR_OK)
        {
            error = loadEdges(edgeArrayInfo, fileStream);
        }

        if (error != ERROR_OK)
        {
             edgesDealloc(edgeArrayInfo);
        }
    }

    return error;
}

bool edgeIsValid(const EdgeInfo *edge, const int pointCount)
{
    return (edge->from-1 < pointCount) && (edge->to-1  < pointCount);
}
ErrorInfo comparePointWithEdges( PointArrayInfo *pointArrayInfo, EdgeArrayInfo *edgeArrayInfo)
{
    int i;
    for(i = 0; i < edgeArrayInfo->count && edgeIsValid(edgeArrayInfo->vector+i, pointArrayInfo->count); i++);

    // in case edge index beyond point's count
    if(i < edgeArrayInfo->count)
    {
        edgesDealloc(edgeArrayInfo);
        pointsDealloc(pointArrayInfo);
        return ERROR_FILE_NOT_VALID;
    }

    return ERROR_OK;
}

ErrorInfo fileOpen(FileInfo *&fileStream, const char *fileName)
{
    fileStream = new FileInfo;

    if( fileStream == NULL)
    {
        return ERROR_MEMORY;
    }

    if ( (fileStream->instance = fopen(fileName,"r")) == NULL)
    {
        return ERROR_FILE_NOT_EXIST;
    }

    return ERROR_OK;
}
ErrorInfo fileLoadModel(Model *model, const FileInfo *fileStream)
{
    ErrorInfo error = ERROR_OK;

    if((error = handlePointArray(&model->pointArrayInfo, fileStream)) != ERROR_OK)
    {
        return error;
    }

    if((error = handleEdgeArray(&model->edgeArrayInfo, fileStream)) != ERROR_OK)
    {
        pointsDealloc(&model->pointArrayInfo);
        return error;
    }

    error = comparePointWithEdges(&model->pointArrayInfo, &model->edgeArrayInfo);

    return error;
}
void fileClose(FileInfo *fileStream)
{
    if(fileStream)
    {
        fclose(fileStream->instance);
        delete fileStream;
    }
}
