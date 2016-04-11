#include "modelhandler.h"
#include "datahandler.h"
#include <iostream>

ModelInfo* modelinfo_alloc()
{
    ModelInfo* model = new ModelInfo;
    if (model)
    {
        model->edges.count = 0;
        model->edges.vector = NULL;
        model->points.count = 0;
        model->points.vector = NULL;
    }

    return model;
}

void modelinfo_dealloc(ModelInfo *model)
{
    datahandler_points_dealloc( &(model->points) );
    datahandler_edges_dealloc(  &(model->edges)  );
}
