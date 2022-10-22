#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>

#define OK 0
#define ARGC_ERROR -1
#define FILE_ERROR -2
#define READ_ERROR -3
#define EMPTY_FILE -4
#define NO_NUMBERS -5
#define PARAM_ERROR -6

int get_average(FILE *const f, double *const average);
int calc_dispersion(FILE *const f, double *const dispersion, const double average);
void print_error(const int rc);

#endif
