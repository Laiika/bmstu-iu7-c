#include "arr_lib.h"

#define FOUND 0
#define NOT_FOUND 1

ARR_DLL int ARR_DECL arr_fill_fib_nums(int *arr, size_t n)
{
    if (!n)
        return SIZE_ERROR;

    if (!arr)
        return NULL_POINTER;

    if (n >= 1)
        arr[0] = 0;

    if (n >= 2)
        arr[1] = 1;

    for (size_t i = 2; i < n; i++)
            arr[i] = arr[i - 1] + arr[i - 2];

    return EXIT_SUCCESS;
}

ARR_DLL int ARR_DECL arr_copy_first(const int *src, size_t src_len, int *dst, size_t *dst_len)
{
    if (!src || !dst_len)
        return NULL_POINTER;

    size_t n = 0;

    for (size_t i = 0; i < src_len; i++)
    {
        int f = NOT_FOUND;

        for (size_t j = 0; j < i && NOT_FOUND == f; j++)
            if (src[j] == src[i])
                f = FOUND;

        if (NOT_FOUND == f)
            n++;
    }     
 
    if (n > *dst_len)
    {
        *dst_len = n;
        return SIZE_ERROR;
    } 
 
    n = 0;

    for (size_t i = 0; i < src_len; i++)
    {
        int f = NOT_FOUND;

        for (size_t j = 0; j < i && NOT_FOUND == f; j++)
            if (src[j] == src[i])
                f = FOUND;

        if (NOT_FOUND == f)
        {
            dst[n] = src[i];
            n++;
        }
    }     

    *dst_len = n;
    return EXIT_SUCCESS;
}
