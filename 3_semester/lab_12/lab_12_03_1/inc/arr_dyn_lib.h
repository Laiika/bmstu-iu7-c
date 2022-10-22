#ifndef _ARR_DYN_LIB_H_
#define _ARR_DYN_LIB_H_

#include <stdio.h>
#include <stdlib.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#define EMPTY_FILE -1
#define READ_ERROR -2
#define FILTER_ERROR -3
#define INVALID_PARAM_ERROR -4

ARR_DLL int ARR_DECL calc_elements(FILE *in, size_t *cnt);
ARR_DLL int ARR_DECL read_elements(FILE *in, int *arr, const size_t cnt, int **pe);
ARR_DLL int ARR_DECL key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);
ARR_DLL int ARR_DECL mysort(void *arr, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
ARR_DLL int ARR_DECL print_elements(FILE *out, const int *pb, const int *pe);

#endif
