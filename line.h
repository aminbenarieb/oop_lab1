#ifndef LINE_H
#define LINE_H
#include "arguments.h"
#include "point.h"

typedef struct Line_
{
    int points[2];
}Line;

typedef struct Lines_
{
    int count;
    Line* lines;
}Lines;

const Line* get_line(const Lines*, int);
void draw_lines(ArgumentInfo, const PointArrayInfo*, const Lines*);

#endif // LINE_H
