#ifndef FILE_H
#define FILE_H

#include "model.h"
ErrorInfo set_model(Model *, const FileInfo*q);

FileInfo* source_open(const char *);
void source_close(FileInfo*);
const char *get_name(void);

#endif // FILE_H
