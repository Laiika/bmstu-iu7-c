#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define MIN_ROWS 2
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2
#define NOT_ENOUGH_ROWS -3

int input_mtr(int (*mtr)[MAX_COLUMNS], int *const rows, int *const columns)
{
    if (scanf("%d %d", rows, columns) != 2)
        return INPUT_ERROR;

    if (!(0 < *rows && *rows <= MAX_ROWS))
        return RANGE_ERROR;

    if (!(0 < *columns && *columns <= MAX_COLUMNS))
        return RANGE_ERROR;

    for (int i = 0; i < *rows; i++)
        for (int j = 0; j < *columns; j++)
            if (scanf("%d", &mtr[i][j]) != 1)
                return INPUT_ERROR;

    return OK;
}

int sum_elems(const int *const arr, const int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

void swap_rows(int *const arr1, int *const arr2, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

void sort_rows(int (*mtr)[MAX_COLUMNS], const int rows, const int columns)
{
    for (int i = 0; i < (rows - 1); i++)
    {
        int jmin = i;

        for (int j = (i + 1); j < rows; j++)
            if (sum_elems(mtr[j], columns) < sum_elems(mtr[jmin], columns))
                jmin = j;

        swap_rows(mtr[i], mtr[jmin], columns);
    }
}

void print_mtr(int (*mtr)[MAX_COLUMNS], const int rows, const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", mtr[i][j]);
    
        printf("\n");
    }
}

void print_error(const int rc)
{
    if (rc == INPUT_ERROR)
        printf("Input error");
    else if (rc == RANGE_ERROR)
        printf("Range error");
    else if (rc == NOT_ENOUGH_ROWS)
        printf("Not enough rows");
}

int main(void)
{
    int mtr[MAX_ROWS][MAX_COLUMNS], rows, columns;
    int rc = input_mtr(mtr, &rows, &columns);

    if (rows < MIN_ROWS)
        rc = NOT_ENOUGH_ROWS;

    if (rc == OK)
    {
        sort_rows(mtr, rows, columns);

        print_mtr(mtr, rows, columns);
    }

    print_error(rc);

    return rc;
}
