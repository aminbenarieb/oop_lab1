#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "line.h"
#include "error.h"
#include "arguments.h"

typedef struct Model_
{
    PointArrayInfo field_v;
    Lines field_l;
}Model;

Model init_model(void);
bool model_exist(const Model*);

ErrorInfo load_model(Model*, ArgumentInfo);
ErrorInfo change_model(Model*, ArgumentInfo);
ErrorInfo draw_model(Model*, ArgumentInfo);

#endif // MODEL_H
