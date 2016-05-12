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

void       edgesDealloc(EdgeArrayInfo*);
EdgeInfo*  edgesAlloc(int);

#endif // EDGE_H
