#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include "errorinfo.h"
#include "modeldata.h"

ErrorInfo datahandler_points_alloc(PointVectorInfo &);
ErrorInfo datahandler_edges_alloc(EdgeVectorInfo &);

void datahandler_points_dealloc(PointVectorInfo &);
void datahandler_edges_dealloc(EdgeVectorInfo &);


#endif // DATAHANDLER_H
