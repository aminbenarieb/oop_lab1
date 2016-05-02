#ifndef MEMORY_H
#define MEMORY_H

#include "model.h"

PointInfo* new_vertexes(int);
Line* new_lines(int);
void delete_vertexes(PointArrayInfo*);
void delete_lines(Lines*);
void delete_model(Model*);

#endif // MEMORY_H
