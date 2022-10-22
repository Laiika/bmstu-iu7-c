#ifndef _ARR_STAT_LIB_H_
#define _ARR_STAT_LIB_H_

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_FILE -1
#define READ_ERROR -2
#define FILTER_ERROR -3
#define INVALID_PARAM_ERROR -4

int calc_elements(FILE *in, size_t *cnt);
int read_elements(FILE *in, int *arr, const size_t cnt, int **pe);
int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);
int mysort(void *arr, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
int print_elements(FILE *out, const int *pb, const int *pe);

#endif
