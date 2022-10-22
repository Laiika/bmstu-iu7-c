#include "funcs.h"

int file_size(FILE *file, size_t *const size)
{
    if (NULL == file)
        return FILE_ERROR;

    long cur_pos = ftell(file);

    if (cur_pos < OK)
        return FILE_ERROR;
        
    if (OK != fseek(file, 0L, SEEK_END))
        return FILE_ERROR;

    long sz = ftell(file);

    if (sz < OK)
        return FILE_ERROR;

    *size = sz;

    if (OK != fseek(file, cur_pos, SEEK_SET))
        return FILE_ERROR;

    return OK;
}
