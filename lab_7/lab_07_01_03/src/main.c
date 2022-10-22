#include <string.h>
#include "element.h"
#include "elements.h"
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

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

    size_t cnt = 0;
    int rc = calc_elements(in, &cnt);
    // при подсчете элементов в файле произошла ошибка
    if (EXIT_SUCCESS != rc)
    {
        fclose(in);
        fclose(out);
        return rc;
    }

    int *arr = NULL;

    arr = malloc(cnt * sizeof(int));
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

    if (EXIT_SUCCESS == (rc = read_elements(in, arr, cnt, &pe_src)))
    {
        // указан параметр f
        if (WITH_F == argc)
        {
            // указатели на начало и конец нового массива
            int *pb_dst = NULL, *pe_dst = NULL;

            // получилось отфильтровать массив
            if (EXIT_SUCCESS == (rc = key(pb_src, pe_src, &pb_dst, &pe_dst)))
            {
                if (EXIT_SUCCESS == (rc = mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare_int)))
                    rc = print_elements(out, pb_dst, pe_dst);

                free(pb_dst);
            }
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
