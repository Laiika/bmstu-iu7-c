#include <stdio.h>
#include <stdarg.h>
#include "../inc/queue.h"

void queue_init(queue_t *queue)
{
    stack_init(&(queue->st1));
    stack_init(&(queue->st2));
}

void queue_free(queue_t *queue)
{
    stack_free(&(queue->st1));
    stack_free(&(queue->st2));
}

int queue_push(queue_t *queue, int elem)
{
    return stack_push(&(queue->st1), elem);
}

int queue_push_n(queue_t *queue, size_t n, ...)
{
    int num, rc = EXIT_SUCCESS;
    va_list vl;

    va_start(vl, n);

    for (size_t i = 0; i < n && EXIT_SUCCESS == rc; i++)
    {
        num = va_arg(vl, int);
        rc = stack_push(&(queue->st1), num);
    }

    va_end(vl);
    return rc;
}

int queue_pop(queue_t *queue, int *elem)
{
    int rc = EXIT_SUCCESS;

    if (0 == queue->st2.cnt)
    {
        int num;

        while (EMPTY != stack_peek(&(queue->st1), &num) && EXIT_SUCCESS == rc)
        {
            rc = stack_push(&(queue->st2), num);

            if (EXIT_SUCCESS == rc)
                stack_pop(&(queue->st1), &num);
        }
    }

    if (EXIT_SUCCESS == rc)
        rc = stack_pop(&(queue->st2), elem);

    return rc;
}

int queue_peek(queue_t *queue, int *elem)
{
    int rc = EXIT_SUCCESS;

    if (0 == queue->st2.cnt)
    {
        int num;

        while (EMPTY != stack_peek(&(queue->st1), &num) && EXIT_SUCCESS == rc)
        {
            rc = stack_push(&(queue->st2), num);

            if (EXIT_SUCCESS == rc)
                stack_pop(&(queue->st1), &num);
        }
    }

    if (EXIT_SUCCESS == rc)
        rc = stack_peek(&(queue->st2), elem);

    return rc;
}
