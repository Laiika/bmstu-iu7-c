#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2
#define TRUE 1
#define FALSE 0

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

int check_column(int (*mtr)[MAX_COLUMNS], const int rows, const int j)
{
    if (rows == 1) 
        return FALSE;

    for (int i = 0; i < (rows - 1); i++)
        if (mtr[i][j] <= mtr[i + 1][j])
            return FALSE;

    return TRUE;
}

void fill_array(int (*mtr)[MAX_COLUMNS], int *const arr, const int rows, const int columns)
{
    for (int i = 0; i < columns; i++)
        arr[i] = check_column(mtr, rows, i);
}

void print_array(const int *const arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void print_error(const int rc)
{
    if (rc == INPUT_ERROR)
        printf("Input error");
    else if (rc == RANGE_ERROR)
        printf("Range error");
}

int main(void)
{
    int mtr[MAX_ROWS][MAX_COLUMNS], rows, columns;
    int rc = input_mtr(mtr, &rows, &columns);

    if (rc == OK)
    {
        int arr[MAX_COLUMNS];

        fill_array(mtr, arr, rows, columns);

        print_array(arr, columns);
    }

    print_error(rc);

    return rc;
}
