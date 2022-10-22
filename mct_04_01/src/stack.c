#include <stdio.h>
#include "../inc/stack.h"

void stack_init(stack_t *stack)
{
    stack->ps = NULL;
    stack->cnt = 0;
}

void stack_free(stack_t *stack)
{
    node_t *cur = stack->ps;

    while (NULL != cur)
    {
        stack->ps = cur->prev;
        node_free(cur);
        cur = stack->ps;
    }

    stack->ps = NULL;
}

int stack_push(stack_t *stack, int elem)
{
    node_t *new_node = node_create(elem);

    if (!new_node)
        return MEMORY_ERROR;

    (stack->cnt)++;
    new_node->prev = stack->ps;
    stack->ps = new_node;

    return EXIT_SUCCESS;
}

int stack_pop(stack_t *stack, int *elem)
{
    if (NULL == stack->ps)
        return EMPTY;

    *elem = stack->ps->val;

    node_t *new_node = stack->ps->prev;

    node_free(stack->ps);
    stack->ps = new_node;
    (stack->cnt)--;

    return EXIT_SUCCESS;
}

int stack_peek(stack_t *stack, int *elem)
{
    if (NULL == stack->ps)
        return EMPTY;

    *elem = stack->ps->val;

    return EXIT_SUCCESS;
}
