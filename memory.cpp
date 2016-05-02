/* Реализация функций работы с памятью */

#include "memory.h"

PointInfo* new_vertexes(int count)
{
    return new PointInfo[count];
}

Line* new_lines(int count)
{
    return new Line[count];
}

void delete_vertexes(PointArrayInfo *v)
{
    if(v->vector)
    {
        delete [] v->vector;
        v->vector = NULL;
    }
    v->count = 0;
}

void delete_lines(Lines *l)
{
    if(l->lines)
    {
        delete [] l->lines;
        l->lines = NULL;
    }
    l->count = 0;
}

void delete_model(Model *m)
{
    delete_lines(&m->field_l);
    delete_vertexes(&m->field_v);
}
