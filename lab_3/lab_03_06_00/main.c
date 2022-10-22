#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2

int input_sizes(int *const rows, int *const columns)
{
    if (scanf("%d %d", rows, columns) != 2)
        return INPUT_ERROR;
    
    if (!(0 < *rows && *rows <= MAX_ROWS))
        return RANGE_ERROR;

    if (!(0 < *columns && *columns <= MAX_COLUMNS))
        return RANGE_ERROR;

    return OK;
}

void fill_mtr_bull_move(int (*mtr)[MAX_COLUMNS], const int rows, const int columns)
{
    int cnt = 1;

    for (int j = 0; j < columns; j ++)
    {
        for (int i = 0; i < rows; i++)
        {
            mtr[i][j] = cnt;

            if (!(j % 2))
                cnt++;
            else 
                cnt--;
        }

        if (!(j % 2))
            cnt += rows - 1;
        else 
            cnt += rows + 1;
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
}

int main(void)
{
    int mtr[MAX_ROWS][MAX_COLUMNS], rows, columns;
    int rc = input_sizes(&rows, &columns);

    if (rc == OK)
    {
        fill_mtr_bull_move(mtr, rows, columns);
        print_mtr(mtr, rows, columns);
    }

    print_error(rc);

    return rc;
}
