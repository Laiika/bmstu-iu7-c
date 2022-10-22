#include "funcs.h"

#define MAX_SIZE 10

int write_nums(FILE *file)
{
    if (NULL == file)
        return FILE_ERROR;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int cur = rand() % 9;

        if (1 != fwrite(&cur, sizeof(int), 1, file))
        {
            fclose(file);
            return FILE_ERROR;
        }
    }

    return OK;
}

int fill_file(char *const f)
{
    FILE *file = fopen(f, "w+b");
    size_t size;

    if (NULL == file)
        return ARGS_ERROR;

    if (OK != file_size(file, &size) || (0 != size % sizeof(int)))
    {
        fclose(file);
        return FILE_ERROR;
    }

    if (OK != write_nums(file))
        return FILE_ERROR;

    fclose(file);
    return OK;
}
