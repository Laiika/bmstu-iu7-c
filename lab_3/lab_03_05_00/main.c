#include <stdio.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define OK 0
#define INPUT_ERROR -1
#define RANGE_ERROR -2
#define NO_PRIMES -3
#define PRIME 1
#define NOT_PRIME 2

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

int is_prime(const int number)
{
    if (number < 2)
        return NOT_PRIME;

    for (int i = 2; i <= (int)sqrt(number); i++)
        if (number % i == 0)
            return NOT_PRIME;

    return PRIME;
}

int collect_primes(int (*mtr)[MAX_COLUMNS], const int rows, const int columns, int *const arr)
{
    int size = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (is_prime(mtr[i][j]) == PRIME)
            {
                arr[size] = mtr[i][j];
                size++;
            }
        }
    }

    return size;
}

void reverse_array(int *const arr, const int size)
{
    for (int i = 0; i < (size / 2); i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void paste_primes(int (*mtr)[MAX_COLUMNS], const int rows, const int columns, const int *const arr)
{
    int index = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (is_prime(mtr[i][j]) == PRIME)
            {
                mtr[i][j] = arr[index];
                index++;
            }
        }
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
    else if (rc == NO_PRIMES)
        printf("No primes");
}

int main(void)
{
    int mtr[MAX_ROWS][MAX_COLUMNS], rows, columns;
    int rc = input_mtr(mtr, &rows, &columns);

    if (rc == OK)
    {
        int primes[MAX_ROWS * MAX_COLUMNS];
        int num_primes = collect_primes(mtr, rows, columns, primes);

        if (num_primes == 0)
            rc = NO_PRIMES;
        else
        {
            reverse_array(primes, num_primes);
            paste_primes(mtr, rows, columns, primes);
            print_mtr(mtr, rows, columns);
        }
    }

    print_error(rc);

    return rc;
}
