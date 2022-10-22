#include <string.h>
#include "funcs.h"

#define ARG_LEN 2
#define SORT 1
#define PRINT 2
#define ADD 3

int parse(int argc, char **argv)
{
    if (argc == 4)
    {
        if (strlen(argv[1]) == ARG_LEN && !(strncmp(argv[1], "sb", ARG_LEN)))
            return SORT;
        
        if (strlen(argv[1]) == ARG_LEN && !(strncmp(argv[1], "fb", ARG_LEN)))
            return PRINT;
    }
    else if (argc == 3 && strlen(argv[1]) == ARG_LEN && !(strncmp(argv[1], "ab", ARG_LEN)))
        return ADD;
    
    return ARGS_ERROR;
}

int main(int argc, char **argv)
{
    if ((argc < 3) || (NULL == argv) || (NULL == argv[1]))
        return ARGS_ERROR;

    int func = parse(argc, argv), rc = OK;

    if (func == SORT)
        rc = sort_products(argv[2], argv[3]);
    else if (func == PRINT)
        rc = print_spec_products(argv[2], argv[3]);
    else if (func == ADD)
        rc = add_product(argv[2]);
    else
        rc = ARGS_ERROR;

    return rc;
}
