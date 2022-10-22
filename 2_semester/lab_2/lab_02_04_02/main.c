#include <stdio.h>

#define MAX_SIZE 10
#define OK 0
#define INPUT_ERROR -1
#define ARRAY_OVERFLOW 100

int input_array(int *const arr)
{
    int number, size = 0, rc = scanf("%d", &number);

    while ((rc == 1) && (size < MAX_SIZE))
    {
        arr[size++] = number;
        rc = scanf("%d", &number);
    }

    if ((rc == 1) && (size == MAX_SIZE))
        size++;

    return size;
}

void selection_sort(int *const arr, const int size)
{
    int min_index, temp;

    for (int i = 0; i < size; i++)
    {
        min_index = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void print_array(const int *const arr, const int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main(void)
{
    int arr[MAX_SIZE], size = input_array(arr);

    if (size == 0)
    {
        printf("Input error");
        return INPUT_ERROR;
    }

    int rc = OK;

    if (size > MAX_SIZE)
    {
        rc = ARRAY_OVERFLOW;
        size = MAX_SIZE;
    }

    selection_sort(arr, size);
    print_array(arr, size);

    return rc;
}
