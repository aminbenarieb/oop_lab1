#include "file.h"
#include "memory.h"

ErrorInfo loadCount(const FileInfo *fileStream, int *count)
{
    return fscanf(fileStream->instance,"%d",count) == 1 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}
ErrorInfo loadPoint(const FileInfo *fileStream, PointInfo *point)
{
    return fscanf(fileStream->instance, "%lf %lf %lf", &point->x, &point->y, &point->z) == 3 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}
ErrorInfo loadEdge (const FileInfo *fileStream, EdgeInfo *edge)
{
    return fscanf(fileStream->instance, "%d %d", &edge->from, &edge->to) == 2 ? ERROR_OK : ERROR_FILE_NOT_VALID;
}

ErrorInfo loadPoints(const FileInfo *fileStream, PointArrayInfo *pointArrayInfo)
{
    ErrorInfo error = ERROR_OK;

    for (int i = 0;  (i < pointArrayInfo->count) && (error == ERROR_OK);  i++)
    {
        error = loadPoint( fileStream, &pointArrayInfo->vector[i] );
    }

    return error;
}
ErrorInfo loadEdges(const FileInfo *fileStream, EdgeArrayInfo *edgeArrayInfo)
{
    ErrorInfo error = ERROR_OK;

    for (int i = 0;  (i < edgeArrayInfo->count) && (error == ERROR_OK);  i++)
    {
        error = loadEdge( fileStream, &edgeArrayInfo->vector[i] );
    }

    return error;
}

ErrorInfo handlePointArray(const FileInfo *fileStream, PointArrayInfo *pointArrayInfo){

    ErrorInfo error = loadCount(fileStream, &pointArrayInfo->count);
    if (error == ERROR_OK)
    {
        pointArrayInfo->vector = allocPoints(pointArrayInfo->count);
        if (error == ERROR_OK)
        {
            error = loadPoints(fileStream, pointArrayInfo);
        }

        if (error != ERROR_OK)
        {
             deallocPoints(pointArrayInfo);
        }
    }

    return error;
}
ErrorInfo handleEdgeArray(const FileInfo *fileStream, EdgeArrayInfo *edgeArrayInfo){

    ErrorInfo error = loadCount(fileStream, &edgeArrayInfo->count );
    if (error == ERROR_OK)
    {
        edgeArrayInfo->vector = allocEdges(edgeArrayInfo->count);
        if (error == ERROR_OK)
        {
            error = loadEdges(fileStream, edgeArrayInfo);
        }

        if (error != ERROR_OK)
        {
             deallocEdges(edgeArrayInfo);
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
        deallocEdges(edgeArrayInfo);
        deallocPoints(pointArrayInfo);
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

    if((error = handlePointArray(fileStream, &model->pointArrayInfo)) != ERROR_OK)
    {
        return error;
    }

    if((error = handleEdgeArray(fileStream, &model->edgeArrayInfo)) != ERROR_OK)
    {
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
