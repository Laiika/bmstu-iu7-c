#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "item.h"

void free_items_array(item_t *arr, const size_t size);
int create_items_array(FILE *file, item_t **arr, size_t *const size);
int sort_items_array(item_t *const arr, const size_t size);
void print_items_array(const item_t *const arr, const size_t size);
void print_items_with_prefix(const item_t *const arr, const size_t size, const char *const prefix);

#endif
