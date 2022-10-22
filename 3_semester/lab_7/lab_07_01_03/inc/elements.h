#ifndef _ELEMENTS_H_
#define _ELEMENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

int calc_elements(FILE *in, size_t *cnt);
int read_elements(FILE *in, int *arr, const size_t cnt, int **pe);
int key(int *pb_src, int *pe_src, int **pb_dst, int **pe_dst);
int mysort(void *arr, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
int print_elements(FILE *out, const int *pb, const int *pe);

#endif
