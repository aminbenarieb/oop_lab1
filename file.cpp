/* Работа с файлом модели */

#include "file.h"
#include "memory.h"
#include "arguments.h"

#include <QFileDialog>

FileInfo* source_open(const char *name)
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

void source_close(FileInfo *st)
{
    if(st)
        fclose(st->instance);
}

const char* get_name(void)
{
    const QString fileName(QFileDialog::getOpenFileName(0, "Выберите файл", "", "*.txt"));

    if(fileName.isEmpty())
    {
        return NULL;
    }

    return fileName.toStdString().c_str();
}

int read_count(int *count, const FileInfo *st)
{
    return fscanf(st->instance,"%d",count);
}

int read_vertex(PointInfo *v, const FileInfo *st)
{
    return fscanf(st->instance, "%lf %lf %lf", &v->x, &v->y, &v->z);
}

int read_line(Line *l, const FileInfo *st)
{
    return fscanf(st->instance, "%d %d", &l->points[0], &l->points[1]);
}

ErrorInfo set_count(int *count, const FileInfo *st)
{
    if(read_count(count,st) != 1)
    {
        return ERROR_FILE_VALID;
    }

    return ERROR_OK;
}

ErrorInfo newVertexes(PointArrayInfo *vertexes, int count)
{
    if((vertexes->vector = new_vertexes(count)) == NULL)
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
        delete_vertexes(vertexes);
        e = ERROR_FILE_VALID;
    }

    return e;
}


ErrorInfo newLines(Lines *lines, int count)
{
    if((lines->lines = new_lines(count)) == NULL)
    {
        return ERROR_MEMORY;
    }

    return ERROR_OK;
}

bool correct_line(const Lines *lines, int index, const PointArrayInfo *vertexes)
{
    return ((get_line(lines,index)->points[0]-1 < vertexes->count) && (get_line(lines,index)->points[1]-1  < vertexes->count));
}

/* Функция считывания линий*/
ErrorInfo set_lines(Lines *lines, PointArrayInfo *vertexes, const FileInfo *st)
{
    ErrorInfo e = ERROR_OK;

    if((e = set_count(&lines->count,st)) != ERROR_OK)
        return e;


    if((e = newLines(lines,lines->count)) != ERROR_OK)
    {
        delete_vertexes(vertexes);
        return e;
    }

    int i;
    for(i = 0; i < lines->count && (read_line((lines->lines+i),st) == 2)
                    && correct_line(lines,i,vertexes); i++);
    if(i < lines->count)
    {
        delete_lines(lines);
        delete_vertexes(vertexes);
        e = ERROR_FILE_VALID;
    }

    return e;
}

/* Функция считывания модели */
ErrorInfo set_model(Model *model, const FileInfo *st)
{
    ErrorInfo e = ERROR_OK;
    if((e = set_vertexes(&model->field_v, st)) != ERROR_OK)
        return e;
    if((e = set_lines(&model->field_l, &model->field_v, st)) != ERROR_OK)
        return e;

    return e;
}
