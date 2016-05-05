#ifndef EDGE_H
#define EDGE_H

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


#endif // EDGE_H
