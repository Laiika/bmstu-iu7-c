#include "funcs.h"

int get_entry_by_pos(FILE *file, size_t pos, struct product *prod)
{
    if (NULL == file)
        return FILE_ERROR;

    if (NULL == prod)
        return PARAM_ERROR;

    long cur_pos = ftell(file);

    if (cur_pos < OK)
        return FILE_ERROR;

    if (OK != fseek(file, pos * sizeof(struct product), SEEK_SET))
        return FILE_ERROR;

    if (1 != fread(prod, sizeof(struct product), 1, file))
        return FILE_ERROR;

    if (OK != fseek(file, cur_pos, SEEK_SET))
        return FILE_ERROR;

    return OK;
}

int put_entry_by_pos(FILE *file, size_t pos, struct product prod)
{
    if (NULL == file)
        return FILE_ERROR;

    long cur_pos = ftell(file);

    if (cur_pos < OK)
        return FILE_ERROR;
        
    if (OK != fseek(file, pos * sizeof(struct product), SEEK_SET))
        return FILE_ERROR;

    if (1 != fwrite(&prod, sizeof(struct product), 1, file))
        return FILE_ERROR;

    if (OK != fseek(file, cur_pos, SEEK_SET))
        return FILE_ERROR;

    return OK;
}
