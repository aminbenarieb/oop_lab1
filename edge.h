#ifndef LINE_H
#define LINE_H

struct EdgeInfo
{
    int from;
    int to;
};

struct EdgeArrayInfo
{
    int count;
    EdgeInfo* vector;
};


#endif // LINE_H
