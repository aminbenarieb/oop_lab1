#include "converthandler.h"


//MARK: Memory managment

void convert_dealloc_lines(LineVectorInfo * lineVectorInfo)
{
    delete lineVectorInfo->vector;
    delete lineVectorInfo;
}
ErrorInfo convert_alloc_lines(LineVectorInfo * lineVectorInfo, int count)
{

    ErrorInfo error = eOk;
    lineVectorInfo = new LineVectorInfo;
    if (lineVectorInfo)
    {
        LineInfo *vector = new LineInfo [count];
        if (vector)
        {
            lineVectorInfo->count = count;
            lineVectorInfo->vector = vector;
        }
        else
        {
            convert_dealloc_lines(lineVectorInfo);
        }
    }

    if (!lineVectorInfo)
    {
        error = eOutOfMemory;
    }

    return error;
}

//MARK:

void convert_model_to_lines(LineVectorInfo *lineVectorInfo, ModelInfo modelInfo)
{


}
