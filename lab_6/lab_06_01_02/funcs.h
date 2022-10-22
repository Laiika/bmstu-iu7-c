#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <stdlib.h>

#define READ_ERROR -3
#define EMPTY_FILE -4
#define ARRAY_MAX_SIZE 15
#define NAME_LEN 25

// структура, описывающая предмет
struct item
{
    char name[NAME_LEN + 1];
    float weight;
    float volume;
};

int read_items(FILE *file, struct item *const arr, size_t *const size);
void sort_items_array(struct item *const arr, const size_t size);
void print_items_array(struct item *const arr, const size_t size);
void print_items_with_prefix(struct item *const arr, const size_t size, char *const prefix);

#endif
