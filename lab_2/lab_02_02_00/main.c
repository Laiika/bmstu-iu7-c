#include <stdio.h>

#define MAX_SIZE 10
#define OK 0
#define SIZE_INPUT_ERROR -1
#define ARRAY_INPUT_ERROR -2
#define NO_MORE_AVERAGE -3

int input_array(int *const arr, int *const size)
{
    if (scanf("%d", size) != 1)
        return SIZE_INPUT_ERROR;

    if (!(0 < *size && *size <= MAX_SIZE))
        return SIZE_INPUT_ERROR;

    for (int i = 0; i < *size; i++)
        if (scanf("%d", &arr[i]) != 1)
            return ARRAY_INPUT_ERROR;

    return OK;
}

int calc_average(const int *const arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += arr[i];

    return (sum / size);
}

int copy_nums_more_average(const int *const arr1, int *const arr2, const int size1)
{
    int size2 = 0, average = calc_average(arr1, size1);

    for (int i = 0; i < size1; i++)
        if (arr1[i] > average)
            arr2[size2++] = arr1[i];

    return size2;
}

void print_array(const int *const arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void print_error(const int rc)
{
    if (rc == SIZE_INPUT_ERROR)
        printf("Size input error");
    else if (rc == ARRAY_INPUT_ERROR)
        printf("Array input error");
    else if (rc == NO_MORE_AVERAGE)
        printf("No elemets more average");
}

int main(void)
{
    int arr1[MAX_SIZE], size1, rc = input_array(arr1, &size1);

    if (rc == OK)
    {
        int arr2[MAX_SIZE], size2 = copy_nums_more_average(arr1, arr2, size1);

        if (size2 == 0)
            rc = NO_MORE_AVERAGE;
        else
            print_array(arr2, size2);
    }

    print_error(rc);
    
    return rc;
}
