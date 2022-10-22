#ifndef _NODE_H_
#define _NODE_H_

struct node
{
    int val;
    struct node *prev;
};
typedef struct node node_t;

node_t *node_create(int num);
void node_free(node_t *node);

#endif
