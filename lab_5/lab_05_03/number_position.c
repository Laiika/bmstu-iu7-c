#include "funcs.h"

int get_number_by_pos(FILE *file, size_t pos, int *const number)
{
    if (NULL == file)
        return FILE_ERROR;

    if (NULL == number)
        return PARAM_ERROR;

    long cur_pos = ftell(file);

    if (cur_pos < OK)
        return FILE_ERROR;

    if (OK != fseek(file, pos * sizeof(int), SEEK_SET))
        return FILE_ERROR;

    if (1 != fread(number, sizeof(int), 1, file))
        return FILE_ERROR;

    if (OK != fseek(file, cur_pos, SEEK_SET))
        return FILE_ERROR;

    return OK;
}

int put_number_by_pos(FILE *file, size_t pos, const int number)
{
    if (NULL == file)
        return FILE_ERROR;

    long cur_pos = ftell(file);

    if (cur_pos < OK)
        return FILE_ERROR;

    if (OK != fseek(file, pos * sizeof(int), SEEK_SET))
        return FILE_ERROR;

    if (1 != fwrite(&number, sizeof(int), 1, file))
        return FILE_ERROR;

    if (OK != fseek(file, cur_pos, SEEK_SET))
        return FILE_ERROR;

    return OK;
}
