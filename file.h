#ifndef FILE_H
#define FILE_H

#include "model.h"

ErrorInfo set_model(Model *, const FileInfo*);

FileInfo* fileOpen(const char *);
void fileClose(FileInfo*);

#endif // FILE_H
