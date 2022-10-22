#include <stdlib.h>
#include "../inc/node.h"

node_t *node_create(int num)
{
    node_t *node = calloc(1, sizeof(node_t));

    if (node)
    {
        node->val = num;
        node->prev = NULL;        
    }
        
    return node;
}

void node_free(node_t *node)
{
    free(node);
}
