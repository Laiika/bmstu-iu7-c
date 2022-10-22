#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>
#include "node.h"
#include "return_codes.h"

struct stack
{
    node_t *ps;
    int cnt;
};
typedef struct stack stack_t;

void stack_init(stack_t *stack);
void stack_free(stack_t *stack);
int stack_push(stack_t *stack, int elem);
int stack_pop(stack_t *stack, int *elem);
int stack_peek(stack_t *stack, int *elem);

#endif
