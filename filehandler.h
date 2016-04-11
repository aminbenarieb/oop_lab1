#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "errorinfo.h"
#include "fileloader.h"

ErrorInfo file_handle_points(FILE *, PointVectorInfo *);
ErrorInfo file_handle_edges(FILE *, EdgeVectorInfo *);

#endif // FILEHANDLER_H
