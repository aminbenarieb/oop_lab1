#ifndef DATAINFO_H
#define DATAINFO_H

struct PointInfo
{
    double x, y, z;
};
struct EdgeInfo
{
    int from, to;
};

struct PointVectorInfo
{
    int count;
    PointInfo *vector;
};

struct EdgeVectorInfo
{
    int count;
    EdgeInfo *vector;
};


#endif // DATAINFO_H
