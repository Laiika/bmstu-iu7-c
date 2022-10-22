#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define OK 0
#define ARGS_ERROR -1
#define FILE_ERROR -2
#define PARAM_ERROR -3

int get_number_by_pos(FILE *file, size_t pos, int *const number);
int put_number_by_pos(FILE *file, size_t pos, const int number);
int file_size(FILE *file, size_t *const size);

int fill_file(char *const f);
int print_nums(char *const f);
int sort_nums(char *const f);

#endif
