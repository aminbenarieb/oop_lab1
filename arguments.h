#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QGraphicsScene>
#include "transform.h"


enum SourceType
{
    SOURCE_FILE
};
struct StreamInfo
{
    SourceType sourceType;
    const char *sourceName;
};


struct SceneInfo
{
    QGraphicsScene *instance;
};


union ArgumentInfo
{
    StreamInfo *stream;
    SceneInfo  *scene;
    TransformInfo modification;
};

#endif // ARGUMENTS_H
