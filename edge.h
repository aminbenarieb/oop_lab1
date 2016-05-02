#ifndef LINE_H
#define LINE_H
#include "arguments.h"
#include "point.h"

typedef struct Line_
{
    int points[2];
}Edge;

typedef struct Lines_
{
    int count;
    Edge* lines;
}EdgeArrayInfo;

const Edge* get_line(const EdgeArrayInfo*, int);
void draw_lines(ArgumentInfo, const PointArrayInfo*, const EdgeArrayInfo*);

#endif // LINE_H
