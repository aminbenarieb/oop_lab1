#include "edge.h"
int take_first_index(const EdgeArrayInfo* L, int i)
{
    return L->lines[i].points[0]-1;
}

int take_second_index(const EdgeArrayInfo* L, int i)
{
    return L->lines[i].points[1]-1;
}

const Edge* get_line(const EdgeArrayInfo *L, int index)
{
    return L->lines+index;
}

void draw_line(ArgumentInfo argument, const PointInfo *v1, const PointInfo *v2)
{
    argument.scene.instance->addLine(v1->x,v1->y,v2->x,v2->y);
}

void draw_lines(ArgumentInfo argument, const PointArrayInfo *vertexes, const EdgeArrayInfo *lines)
{
    const PointInfo *v1 = NULL,
                 *v2 = NULL;
    int st, fn;
    for(int i = 0; i < lines->count; i++)
    {
        st = take_first_index(lines,i);
        fn = take_second_index(lines,i);
        v1 = &vertexes->vector[st];
        v2 = &vertexes->vector[fn];
        draw_line(argument,v1,v2);
    }
}
