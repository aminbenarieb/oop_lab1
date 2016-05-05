#ifndef FILE_H
#define FILE_H

#include "model.h"
#include <iostream>

struct FileInfo
{
    FILE *instance;
};


ErrorInfo fileOpen(FileInfo *&, const char *);
ErrorInfo fileLoadModel(Model *, const FileInfo*);
void      fileClose(FileInfo*);

#endif // FILE_H
