#include "file.h"
#include "memory.h"
#include "arguments.h"


FileInfo* fileOpen(const char *name)
{
    FileInfo *st = new FileInfo;
    st->instance = fopen(name,"r");
    if(st->instance != NULL)
    {
        return st;
    }
    fclose(st->instance);
    delete st;
    return NULL;
}

void fileClose(FileInfo *st)
{
    if(st)
    {
        fclose(st->instance);
    }
}

int read_count(int *count, const FileInfo *st)
{
    return fscanf(st->instance,"%d",count);
}

int read_vertex(PointInfo *v, const FileInfo *st)
{
    return fscanf(st->instance, "%lf %lf %lf", &v->x, &v->y, &v->z);
}

int read_line(Edge *l, const FileInfo *st)
{
    return fscanf(st->instance, "%d %d", &l->points[0], &l->points[1]);
}

ErrorInfo set_count(int *count, const FileInfo *st)
{
    if(read_count(count,st) != 1)
    {
        return ERROR_FILE_NOT_VALID;
    }

    return ERROR_OK;
}

ErrorInfo newVertexes(PointArrayInfo *vertexes, int count)
{
    if((vertexes->vector = allocPoints(count)) == NULL)
    {
        return ERROR_MEMORY;
    }

    return ERROR_OK;
}

/* Функция считывания вершин */
ErrorInfo set_vertexes(PointArrayInfo *vertexes, const FileInfo *st)
{
    ErrorInfo e = ERROR_OK;

    if((e = set_count(&vertexes->count,st)) != ERROR_OK)
        return e;


    if((e = newVertexes(vertexes,vertexes->count)) != ERROR_OK)
        return e;


    int i;
    for(i = 0; i < vertexes->count && (read_vertex((vertexes->vector+i),st) == 3); i++);
    if(i < vertexes->count)
    {
        deallocPoints(vertexes);
        e = ERROR_FILE_NOT_VALID;
    }

    return e;
}


ErrorInfo newLines(EdgeArrayInfo *lines, int count)
{
    if((lines->lines = allocEdges(count)) == NULL)
    {
        return ERROR_MEMORY;
    }

    return ERROR_OK;
}

bool correct_line(const EdgeArrayInfo *lines, int index, const PointArrayInfo *vertexes)
{
    return ((get_line(lines,index)->points[0]-1 < vertexes->count) && (get_line(lines,index)->points[1]-1  < vertexes->count));
}

/* Функция считывания линий*/
ErrorInfo set_lines(EdgeArrayInfo *lines, PointArrayInfo *vertexes, const FileInfo *st)
{
    ErrorInfo e = ERROR_OK;

    if((e = set_count(&lines->count,st)) != ERROR_OK)
        return e;


    if((e = newLines(lines,lines->count)) != ERROR_OK)
    {
        deallocPoints(vertexes);
        return e;
    }

    int i;
    for(i = 0; i < lines->count && (read_line((lines->lines+i),st) == 2)
                    && correct_line(lines,i,vertexes); i++);
    if(i < lines->count)
    {
        deallocEdges(lines);
        deallocPoints(vertexes);
        e = ERROR_FILE_NOT_VALID;
    }

    return e;
}

/* Функция считывания модели */
ErrorInfo set_model(Model *model, const FileInfo *st)
{
    ErrorInfo e = ERROR_OK;
    if((e = set_vertexes(&model->pointArrayInfo, st)) != ERROR_OK)
        return e;
    if((e = set_lines(&model->edgeArrayInfo, &model->pointArrayInfo, st)) != ERROR_OK)
        return e;

    return e;
}
