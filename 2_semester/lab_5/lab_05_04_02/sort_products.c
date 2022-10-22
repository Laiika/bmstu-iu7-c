#include <string.h>
#include "funcs.h"

int swap_prods(FILE *file, int jmax, int i, struct product *max, struct product *cur)
{
    int rc;

    if (NULL == file)
        return FILE_ERROR;

    if (NULL == max || NULL == cur)
        return PARAM_ERROR;

    if (OK != (rc = get_entry_by_pos(file, jmax, max)))
        return rc;

    if (OK != (rc = get_entry_by_pos(file, i, cur)))
        return rc;

    if (OK != (rc = put_entry_by_pos(file, jmax, *cur)))
        return rc;

    if (OK != (rc = put_entry_by_pos(file, i, *max)))
        return rc;

    return OK;
}

int compare_prods(int jmax, int j, struct product *max, struct product *cur)
{
    unsigned int cur_p = cur->price, max_p = max->price;
    unsigned int cur_am = cur->amount, max_am = max->amount;

    if ((cur_p > max_p) || ((cur_p == max_p) && (cur_am > max_am)))
        return j;

    return jmax;
}

int sort_prods_by_price(FILE *file, size_t count)
{
    for (size_t i = 0; i < (count - 1); i++)
    {
        int jmax = i, rc;
        struct product cur, max;
        memset(&cur, 0, sizeof(struct product));
        memset(&max, 0, sizeof(struct product));

        for (size_t j = i + 1; j < count; j++)
        {
            if (OK != (rc = get_entry_by_pos(file, j, &cur)))
                return rc;

            if (OK != (rc = get_entry_by_pos(file, jmax, &max)))
                return rc;

            jmax = compare_prods(jmax, j, &max, &cur);
        }

        if (OK != (rc = swap_prods(file, jmax, i, &max, &cur)))
            return rc;
    }

    return OK;
}

int copy_file(FILE *file_src, FILE *file_dst, size_t count)
{
    if ((NULL == file_src) || (NULL == file_dst))
        return FILE_ERROR;

    struct product cur;
    memset(&cur, 0, sizeof(struct product));

    rewind(file_src);

    for (size_t i = 0; i < count; i++)
    {
        if (1 != fread(&cur, sizeof(struct product), 1, file_src))
            return FILE_ERROR;

        if (1 != fwrite(&cur, sizeof(struct product), 1, file_dst))
            return FILE_ERROR;
    }

    return OK;
}

int sort_to_file(FILE *file_src, FILE *file_dst, size_t count)
{
    if ((NULL == file_src) || (NULL == file_dst))
        return FILE_ERROR;

    int rc;

    if (0 == count || 1 == count)
    {
        rc = copy_file(file_src, file_dst, count);
        fclose(file_src);
        fclose(file_dst);
        return rc;
    }

    rc = sort_prods_by_price(file_src, count);

    if (rc == OK)
        rc = copy_file(file_src, file_dst, count);
    
    fclose(file_src);
    fclose(file_dst);
    return rc;
}

int sort_products(const char *const file1, const char *const file2)
{
    FILE *file_src = fopen(file1, "rb+");
    FILE *file_dst = fopen(file2, "wb");
    size_t size;

    if ((NULL == file_src) || (NULL == file_dst))
        return FILE_ERROR;

    if ((OK != file_size(file_src, &size)) || (0 != size % sizeof(struct product)))
    {
        fclose(file_src);
        fclose(file_dst);
        return FILE_ERROR;
    }

    size_t count = size / sizeof(struct product);

    return sort_to_file(file_src, file_dst, count);
}
