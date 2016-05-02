#ifndef MEMORY_H
#define MEMORY_H

#include "model.h"

PointInfo* allocPoints(int);
EdgeInfo*  allocEdges(int);
Model      allocModel(void);

void       deallocPoints(PointArrayInfo*);
void       deallocEdges(EdgeArrayInfo*);
void       deallocModel(Model*);

#endif // MEMORY_H
