#include "funcs.h"

int print_number(FILE *file)
{
    if (NULL == file)
        return FILE_ERROR;

    int number;

    if (1 != fread(&number, sizeof(int), 1, file))
    {
        fclose(file);
        return FILE_ERROR;
    }
            
    printf("%d\n", number);

    return OK;
}

int print_nums(char *const f)
{
    FILE *file = fopen(f, "r+b");
    size_t size;

    if (NULL == file)
        return ARGS_ERROR;

    if (OK != file_size(file, &size) || (0 != size % sizeof(int)))
    {
        fclose(file);
        return FILE_ERROR;
    }

    size_t count = size / sizeof(int);

    for (size_t i = 0; i < count; i++)
        if (OK != print_number(file))
            return FILE_ERROR;

    fclose(file);
    return OK;
}
