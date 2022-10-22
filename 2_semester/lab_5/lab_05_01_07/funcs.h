#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>

#define OK 0
#define NOT_ENOUGH_NUMBERS -1
#define MIN_SEQ_LEN 3

int process(FILE *const f, int *const result);
void print_error(const int rc);

#endif
