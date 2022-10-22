#include <stdio.h>

#define MAX_SIZE 10
#define MIN_SIZE 2
#define OK 0
#define SIZE_INPUT_ERROR -1
#define ARRAY_INPUT_ERROR -2
#define NOT_ENOUGH_ELEMENTS -3

int input_array(int *const arr, int *const size)
{
    if (scanf("%d", size) != 1)
        return SIZE_INPUT_ERROR;

    if (!(0 < *size && *size <= MAX_SIZE))
        return SIZE_INPUT_ERROR;

    int *pb = arr, *pe = arr;

    for (int i = 0; i < *size; i++)
    {
        if (scanf("%d", pe) != 1)
            return ARRAY_INPUT_ERROR;

        pe++;
    }

    if ((pe - pb) < MIN_SIZE)
        return NOT_ENOUGH_ELEMENTS;

    return OK;
}

int min_prod(const int *const pb, const int *const pe)
{
    int min_prod = (*pb) * (*(pb + 1)), cur_prod;
    const int *cur = pb + 1;

    while (cur < (pe - 1))
    {
        cur_prod = (*cur) * (*(cur + 1));

        if (cur_prod < min_prod)
            min_prod = cur_prod;
         
        cur++;
    }

    return min_prod;
}

void print_error(const int rc)
{
    if (rc == SIZE_INPUT_ERROR)
        printf("Size input error");
    else if (rc == ARRAY_INPUT_ERROR)
        printf("Array input error");
    else if (rc == NOT_ENOUGH_ELEMENTS)
        printf("Not enough elements");
}

int main(void)
{
    int arr[MAX_SIZE];
    int size, rc = input_array(arr, &size);

    if (rc == OK)
        printf("%d", min_prod(arr, arr + size));
    else
        print_error(rc);

    return rc;
}
