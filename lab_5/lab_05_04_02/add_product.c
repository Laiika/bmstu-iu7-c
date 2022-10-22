#include <string.h>
#include "funcs.h"

#define FOUND 1
#define NOT_FOUND 2

int move_entries(FILE *file, struct product prod, size_t i, int size)
{
    if (NULL == file)
        return FILE_ERROR;

    struct product cur;
    memset(&cur, 0, sizeof(struct product));
    size_t count = size / sizeof(struct product);
    int rc;

    for (size_t j = i; j < count; j++)
    {
        if (OK != (rc = get_entry_by_pos(file, j, &cur)))
            return rc;

        if (OK != (rc = put_entry_by_pos(file, j, prod)))
            return rc;

        prod = cur;
    }

    if (OK != (rc = put_entry_by_pos(file, count, prod)))
        return rc;

    return OK;
}

int check_entry(FILE *file, struct product prod, struct product cur, int *const flag, size_t i, size_t size)
{
    if (NULL == file)
        return FILE_ERROR;

    int rc = OK;
    unsigned int cur_p = cur.price, prod_p = prod.price;
    unsigned int cur_am = cur.amount, prod_am = prod.amount;

    if ((cur_p < prod_p) || (cur_p == prod_p && cur_am <= prod_am))
    {
        if (OK != (rc = put_entry_by_pos(file, i, prod)))
            return rc;

        rc = move_entries(file, cur, i + 1, size);
        *flag = FOUND;
    }

    return rc;
}

int add_to_end(FILE *file, struct product prod, int flag)
{
    if (NULL == file)
        return FILE_ERROR;

    if (flag == NOT_FOUND)
    {
        if (OK != fseek(file, 0L, SEEK_END))
            return FILE_ERROR;

        if (1 != fwrite(&prod, sizeof(struct product), 1, file))
            return FILE_ERROR;
    }

    return OK;
}

int find_position(FILE *file, struct product prod, size_t size)
{
    if (NULL == file)
        return FILE_ERROR;

    struct product cur;
    memset(&cur, 0, sizeof(struct product));
    int flag = NOT_FOUND, rc = OK;
    size_t count = size / sizeof(struct product);

    for (size_t i = 0; (flag == NOT_FOUND) && !rc && i < count; i++)
    {
        if (1 != (fread(&cur, sizeof(struct product), 1, file)))
            return FILE_ERROR;

        rc = check_entry(file, prod, cur, &flag, i, size);
    }

    rc = add_to_end(file, prod, flag);

    return rc;
}

int add_product(char *const f)
{
    FILE *file = fopen(f, "rb+");
    size_t size;

    if (file == NULL)
        return FILE_ERROR;

    if ((OK != file_size(file, &size)) || (0 != size % sizeof(struct product)))
    {
        fclose(file);
        return FILE_ERROR;
    }

    struct product prod;
    memset(&prod, 0, sizeof(struct product));
    int rc = read_entry(&prod);

    if (OK == rc)
        rc = find_position(file, prod, size);

    fclose(file);
    return rc;
}
