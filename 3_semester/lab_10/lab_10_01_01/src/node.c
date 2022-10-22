#include <stdio.h>
#include <stdlib.h>
#include "node.h"

// функция для создания элемента списка
node_t *node_create(void *data)
{
    node_t *elem = malloc(sizeof(node_t));

    if (elem)
    {
        elem->data = data;
        elem->next = NULL;        
    }
        
    return elem;
}

// функция для сравнения двух целых чисел
int compare_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    
    return *a - *b;
}
