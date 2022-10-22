#include "funcs.h"

void print_error(const int rc)
{
    if (NOT_ENOUGH_NUMBERS == rc)
        printf("Not enough numbers\n");
}

int process(FILE *const f, int *const result)
{
    int number, cnt = 0, rc = fscanf(f, "%d", &number);
    int first, second, third;
    *result = 0;

    while (1 == rc)
    {
        first = second; 
        second = third;
        third = number;

        if (MIN_SEQ_LEN <= ++cnt)
            if ((third < second) && (first < second))
                (*result)++;
        
        rc = fscanf(f, "%d", &number);
    }

    if (cnt < MIN_SEQ_LEN)
        return NOT_ENOUGH_NUMBERS;

    return OK;
}
