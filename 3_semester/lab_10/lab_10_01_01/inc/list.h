#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "errors.h"

node_t *list_add_end(node_t *head, node_t *elem);
void list_free_all(node_t *head);
node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));
void insert(node_t **head, node_t *elem, node_t *before);
int copy(node_t *head, node_t **new_head);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void*, const void*));
node_t *sort(node_t *head, int (*comparator)(const void*, const void*));
int list_nums_read(FILE *file, node_t **head);
node_t *list_nums_fill(int *arr, const size_t size);
void list_nums_print(FILE *file, node_t *head);

#endif
