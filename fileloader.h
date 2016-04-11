#ifndef FILELOADER_H
#define FILELOADER_H

#include "errorinfo.h"
#include "modeldata.h"
#include <iostream>

ErrorInfo file_load_count( FILE *, int *);
ErrorInfo file_load_point( FILE *, PointInfo *);
ErrorInfo file_load_edge(  FILE *, EdgeInfo *);


#endif // FILELOADER_H
