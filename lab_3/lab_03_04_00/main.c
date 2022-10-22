#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define MIN_ROWS 2
#define NO_MIN_ELEM 0
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2
#define NOT_ENOUGH_ELEMS -3
#define NO_ODD_UNDER_DIAG -4

int input_mtr(int (*mtr)[MAX_SIZE], int *const rows, int *const columns)
{
    if ((scanf("%d %d", rows, columns) != 2) || (*rows != *columns))
        return INPUT_ERROR;

    if (!(0 < *rows && *rows <= MAX_SIZE))
        return RANGE_ERROR;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &mtr[i][j]) != 1)
                return INPUT_ERROR;

    return OK;
}

int find_min_elem(int (*mtr)[MAX_SIZE], const int size)
{
    int min = NO_MIN_ELEM;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((min == NO_MIN_ELEM) && (abs(mtr[i][j]) % 2)) 
                min = mtr[i][j];

            if ((min > mtr[i][j]) && (abs(mtr[i][j]) % 2))
                min = mtr[i][j];
        }
    }

    return min;
}

void print_error(const int rc)
{
    if (rc == INPUT_ERROR)
        printf("Input error");
    else if (rc == RANGE_ERROR)
        printf("Range error");
    else if (rc == NOT_ENOUGH_ELEMS)
        printf("Not enough elements");
    else if (rc == NO_ODD_UNDER_DIAG)
        printf("No odd under the diagonal");
}

int main(void)
{
    int mtr[MAX_SIZE][MAX_SIZE], rows, columns;
    int rc = input_mtr(mtr, &rows, &columns);

    if (rows < MIN_ROWS)
        rc = NOT_ENOUGH_ELEMS;

    if (rc == OK)
    {
        int min = find_min_elem(mtr, rows);

        if (min == NO_MIN_ELEM)
            rc = NO_ODD_UNDER_DIAG;
        else
            printf("%d", min);
    }

    print_error(rc);

    return rc;
}
