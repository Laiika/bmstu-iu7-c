#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdlib.h>
#include "stack.h"
#include "return_codes.h"

struct queue
{
    stack_t st1;
    stack_t st2;
};
typedef struct queue queue_t;

void queue_init(queue_t *queue);
void queue_free(queue_t *queue);
int queue_push(queue_t *queue, int elem);
int queue_push_n(queue_t *queue, size_t n, ...);
int queue_pop(queue_t *queue, int *elem);
int queue_peek(queue_t *queue, int *elem);

#endif
