#ifndef STREAM_H
#define STREAM_H

enum SourceType
{
    SOURCE_FILE
};
struct StreamInfo
{
    SourceType sourceType;
    const char *sourceName;
};


#endif // STREAM_H
