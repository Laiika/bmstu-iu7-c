#ifndef _NODE_H_
#define _NODE_H_

typedef struct node node_t;
struct node
{
    void *data;
    node_t *next; 
};

node_t *node_create(void *data);
int compare_int(const void *p, const void *q);

#endif
