#include "funcs.h"

int main(void)
{
    int cnt, rc = process(stdin, &cnt);

    if (rc != OK)
        print_error(rc);
    else 
        printf("%d\n", cnt);

    return rc;
}
