#ifndef _ARR_LIB_H_
#define _ARR_LIB_H_

#include <stdlib.h>

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#define SIZE_ERROR 1
#define NULL_POINTER 2

ARR_DLL int ARR_DECL arr_fill_fib_nums(int *arr, size_t n);
ARR_DLL int ARR_DECL arr_copy_first(const int *src, size_t src_len, int *dst, size_t *dst_len);

#endif
