#ifndef FILELOADER_H
#define FILELOADER_H

#include "errorinfo.h"
#include "modeldata.h"
#include <iostream>

ErrorInfo file_load_count( FILE *, int &);
ErrorInfo file_load_points(FILE *, PointVectorInfo &);
ErrorInfo file_load_edges(FILE *, EdgeVectorInfo &);


#endif // FILELOADER_H
