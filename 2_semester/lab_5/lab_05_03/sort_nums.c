#include "funcs.h"

int swap_numbers(FILE *file, size_t count, int jmin, int i, int *min, int *cur)
{
    int rc;

    if (NULL == file)
        return FILE_ERROR;

    if (NULL == min || NULL == cur)
        return PARAM_ERROR;

    if (OK != (rc = get_number_by_pos(file, jmin, min)))
        return rc;

    if (OK != (rc = get_number_by_pos(file, i, cur)))
        return rc;

    if (OK != (rc = put_number_by_pos(file, jmin, *cur)))
        return rc;

    if (OK != (rc = put_number_by_pos(file, i, *min)))
        return rc;

    return OK;
}

int sort(FILE *file, size_t count)
{
    if (NULL == file)
        return FILE_ERROR;

    for (size_t i = 0; i < (count - 1); i++)
    {
        int jmin = i, min, cur, rc;

        for (size_t j = i + 1; j < count; j++)
        {
            if (OK != (rc = get_number_by_pos(file, j, &cur)))
                return rc;

            if (OK != (rc = get_number_by_pos(file, jmin, &min)))
                return rc;

            if (cur < min)
                jmin = j;
        }

        if (OK != (rc = swap_numbers(file, count, jmin, i, &min, &cur)))
            return rc;
    }

    return OK;
}

int sort_nums(char *const f)
{
    FILE *file = fopen(f, "r+b");
    size_t size;

    if (NULL == f)
        return ARGS_ERROR;
    
    if ((OK != file_size(file, &size)) || (0 != size % sizeof(int)))
    {
        fclose(file);
        return FILE_ERROR;
    }

    if ((0 == size / sizeof(int)) || (1 == size / sizeof(int)))
    {
        fclose(file);
        return OK;
    }

    int rc = sort(file, size / sizeof(int));

    fclose(file);
    return rc;
}
