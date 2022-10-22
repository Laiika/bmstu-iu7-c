#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "element.h"

#define ARGC_ERROR 1
#define ARGV_ERROR 2
#define FILE_ERROR 3
#define MEMORY_ERROR 4
#define LIB_ERROR 5

#define WITHOUT_F 3
#define WITH_F 4

typedef int (__cdecl *fn_calc_elements_t)(FILE *, size_t *);
typedef int (__cdecl *fn_read_elements_t)(FILE *, int *, const size_t, int **);
typedef int (__cdecl *fn_key_t)(int *, int *, int **, int **);
typedef int (__cdecl *fn_mysort_t)(void *, size_t, size_t, int (*)(const void*, const void*));
typedef int (__cdecl *fn_print_elements_t)(FILE *, const int *, const int *);

int main(int argc, char **argv)
{
    HMODULE hlib;

    fn_calc_elements_t calc_elements;
    fn_read_elements_t read_elements;
    fn_key_t key;
    fn_mysort_t mysort;
    fn_print_elements_t print_elements;

    hlib = LoadLibrary("arr.dll");

    if (!hlib)
        return LIB_ERROR;

    calc_elements = (fn_calc_elements_t) GetProcAddress(hlib, "calc_elements");

    if (!calc_elements)
    {
        FreeLibrary(hlib);
        return LIB_ERROR;
    }

    read_elements = (fn_read_elements_t) GetProcAddress(hlib, "read_elements");

    if (!read_elements)
    {
        FreeLibrary(hlib);
        return LIB_ERROR;
    }

    key = (fn_key_t) GetProcAddress(hlib, "key");

    if (!key)
    {
        FreeLibrary(hlib);
        return LIB_ERROR;
    }

    mysort = (fn_mysort_t) GetProcAddress(hlib, "mysort");

    if (!mysort)
    {
        FreeLibrary(hlib);
        return LIB_ERROR;
    }

    print_elements = (fn_print_elements_t) GetProcAddress(hlib, "print_elements");

    if (!print_elements)
    {
        FreeLibrary(hlib);
        return LIB_ERROR;
    }

    FILE *in, *out;

    if (WITHOUT_F != argc && WITH_F != argc)
    {
        FreeLibrary(hlib);
        return ARGC_ERROR;
    }

    if (WITH_F == argc && (1 != strlen(argv[3]) || argv[3][0] != 'f'))
    {
        FreeLibrary(hlib);
        return ARGV_ERROR;
    }

    if (NULL == (in = fopen(argv[1], "r")))
    {
        FreeLibrary(hlib);
        return FILE_ERROR;
    }

    if (NULL == (out = fopen(argv[2], "w")))
    {
        FreeLibrary(hlib);
        fclose(in);
        return FILE_ERROR;
    }

    size_t size = 0;
    int rc = calc_elements(in, &size);
    // при подсчете элементов в файле произошла ошибка
    if (EXIT_SUCCESS != rc)
    {
        FreeLibrary(hlib);
        fclose(in);
        fclose(out);
        return rc;
    }

    int *arr = NULL;

    arr = malloc(size * sizeof(int));
    // Проверка успешности выделения
    if (arr == NULL)
    {
        FreeLibrary(hlib);
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

    FreeLibrary(hlib);
    // Освобождение памяти
    free(arr);
    fclose(in);
    fclose(out);
    return rc; 
}
