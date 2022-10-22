#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "arr_dyn_lib.h"
#include "element.h"

#define ARGC_ERROR 1
#define ARGV_ERROR 2
#define FILE_ERROR 3
#define MEMORY_ERROR 4

#define WITHOUT_F 3
#define WITH_F 4

int main(int argc, char **argv)
{
    FILE *in, *out;

    if (WITHOUT_F != argc && WITH_F != argc)
        return ARGC_ERROR;

    if (WITH_F == argc && (1 != strlen(argv[3]) || argv[3][0] != 'f'))
        return ARGV_ERROR;

    if (NULL == (in = fopen(argv[1], "r")))
        return FILE_ERROR;

    if (NULL == (out = fopen(argv[2], "w")))
    {
        fclose(in);
        return FILE_ERROR;
    }

    size_t size = 0;
    int rc = calc_elements(in, &size);
    // при подсчете элементов в файле произошла ошибка
    if (EXIT_SUCCESS != rc)
    {
        fclose(in);
        fclose(out);
        return rc;
    }

    int *arr = NULL;

    arr = malloc(size * sizeof(int));
    // Проверка успешности выделения
    if (arr == NULL)
    {
        fclose(in);
        fclose(out);
        return MEMORY_ERROR;
    }

    rewind(in);
    // указатели на начало и конец исходного массива
    int *pb_src = arr, *pe_src;

    if (EXIT_SUCCESS == (rc = read_elements(in, arr, size, &pe_src)))
    {
        // указан параметр f
        if (WITH_F == argc)
        {
            // указатели на начало и конец нового массива
            int *pb_dst = NULL, *pe_dst = NULL, cnt = key(pb_src, pe_src, &pb_dst, &pe_dst);

            if (cnt > 0)
            {
                pb_dst = malloc(cnt * sizeof(int));

                if (pb_dst)
                {
                    key(pb_src, pe_src, &pb_dst, &pe_dst);

                    if (EXIT_SUCCESS == (rc = mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int)))
                        rc = print_elements(out, pb_dst, pe_dst);

                    free(pb_dst);
                }
                else
                    rc = MEMORY_ERROR;
            }
            else
                rc = cnt;
        }
        else
        {
            if (EXIT_SUCCESS == (rc = mysort(pb_src, pe_src - pb_src, sizeof(int), compare_int)))
                rc = print_elements(out, pb_src, pe_src);
        }
    }

    // Освобождение памяти
    free(arr);
    fclose(in);
    fclose(out);
    return rc;
}
