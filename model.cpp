/* Реализация функций работы с моделью*/

#include "model.h"
#include "file.h"
#include "memory.h"

/* Инициализация модели*/
Model init_model(void)
{
    Model model;
    model.field_l.lines = NULL;
    model.field_l.count = 0;
    model.field_v.vector = NULL;
    model.field_v.count = 0;
    return model;
}

/* Проверка существования модели */
bool model_exist(const Model *model)
{
    if(model->field_l.lines && model->field_v.vector)
        return true;
    return false;
}

/* Изменение модели */
ErrorInfo change_model(Model *model, ArgumentInfo argument)
{
    if(!model_exist(model))
    {
        return ERROR_NOT_INIT;
    }

    transformPointVector(&model->field_v,argument.modification);
    return ERROR_OK;
}

/* Рисование модели */
ErrorInfo draw_model(Model *model, ArgumentInfo argument)
{
    if(!model_exist(model))
    {
        return ERROR_NOT_INIT;
    }

    draw_lines(argument,&model->field_v,&model->field_l);
    return ERROR_OK;
}

/* Загрузка модели из файла */
ErrorInfo load_from_file(Model *model,const char *name)
{
    ErrorInfo e = ERROR_OK;

    FileInfo *st = NULL;
    if((st = source_open(name)) == NULL)
    {
        return ERROR_FILE_EXIST;
    }

    Model cur_model = init_model();

    if((e = set_model(&cur_model,st)) == ERROR_OK)
    {
        delete_model(model);
        *model = cur_model;
    }
    source_close(st);
    return e;
}

/* Загрузка модели */
ErrorInfo load_model(Model *model, ArgumentInfo argument)
{
    ErrorInfo e = ERROR_OK;

    StreamInfo *stream = argument.stream;

    switch(stream->source)
    {
        case SOURCE_FILE:
        {
            e = load_from_file(model,stream->sourceName);
            break;
        }
    }

    return e;
}

