#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 20
#define MAX_COLUMNS 10
#define MAX_NUMBER 9
#define MIN_NUMBER 0
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2
#define TRUE 1
#define FALSE 2
#define NUM_TO_FILL_ROW 100

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

int find_first_digit(int element)
{
    int digit = 0;

    while (element > 0)
    {
        digit = element % 10;
        element = element / 10;
    }

    return digit;
}

int check_row(const int *arr, const int size, const int number)
{
    int start_num = 0, end_num = 0;

    for (const int *p = arr; p < (arr + size); p++)
    {
        if ((abs(*p) % 10) == number)
            end_num++;

        if (find_first_digit(abs(*p)) == number)
            start_num++;
    }

    if ((start_num == end_num) && (start_num != 0))
        return TRUE;

    return FALSE;
}

void move_rows_1_pos_forward(int (*mtr)[MAX_COLUMNS], const int rows, const int columns, const int row)
{
    for (int i = (rows - 1); i >= row; i--)
        for (int j = 0; j < columns; j++)
            mtr[i + 1][j] = mtr[i][j];
}

void add_row_num(int (*mtr)[MAX_COLUMNS], const int columns, const int row)
{
    for (int j = 0; j < columns; j++)
        mtr[row][j] = NUM_TO_FILL_ROW;
}

int add_rows_num(int (*mtr)[MAX_COLUMNS], int rows, const int columns, const int num)
{
    int i = 0;

    while (i < rows)
    {
        if (check_row(mtr[i], columns, num) == TRUE)
        {
            move_rows_1_pos_forward(mtr, rows, columns, (i + 1));
            add_row_num(mtr, columns, (i + 1));
            rows++;
            i++;
        }

        i++;
    }

    return rows;
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
}

int main(void)
{
    int mtr[MAX_ROWS][MAX_COLUMNS], rows, columns;
    int number, rc = input_mtr(mtr, &rows, &columns);

    if (scanf("%d", &number) != 1)
        rc = INPUT_ERROR;
    else if ((number < MIN_NUMBER) || (number > MAX_NUMBER))
        rc = RANGE_ERROR;

    if (rc == OK)
    {
        rows = add_rows_num(mtr, rows, columns, number);

        print_mtr(mtr, rows, columns);
    }

    print_error(rc);

    return rc;
}
