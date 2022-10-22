#ifndef _ITEM_H_
#define _ITEM_H_

#include <stdio.h>
#include "errors.h"

// структура, описывающая предмет
struct item
{
    char *name;
    float weight;
    float volume;
};
typedef struct item item_t;

void free_item(item_t *cur);
int read_item(FILE *file, item_t *const cur);
void print_item(const item_t *const cur);
int cmp_items_by_ro(const item_t *const f, const item_t *const s);
int swap_items(item_t *const f, item_t *const s);

#endif
