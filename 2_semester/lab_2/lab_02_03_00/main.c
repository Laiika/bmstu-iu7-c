#include <stdio.h>

#define MAX_SIZE 10
#define OK 0
#define SIZE_INPUT_ERROR -1
#define ARRAY_INPUT_ERROR -2
#define EMPTY_ARRAY -3
#define RADIX 10
#define YES 1
#define NO 2

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

int is_palindrome(const int num)
{
    if (num < 0)
        return NO;

    int reverse = 0, copy = num;

    while (copy > 0)
    {
        reverse = reverse * RADIX + (copy % RADIX);
        copy /= RADIX;
    }

    if (num == reverse)
        return YES;

    return NO;
}

void remove_element(int *const arr, const int i, const int size)
{
    for (int j = i; j < (size - 1); j++)
        arr[j] = arr[j + 1];
}

int remove_palindromes(int *const arr, int size)
{
    int i = 0;

    while (i < size)
    {
        if (is_palindrome(arr[i]) == YES)
        {
            remove_element(arr, i, size);
            size--;
        }
        else
            i++;
    }

    return size;
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
    else if (rc == EMPTY_ARRAY)
        printf("Empty array");
}

int main(void)
{
    int arr[MAX_SIZE], size, rc = input_array(arr, &size);

    if (rc == OK)
    {
        size = remove_palindromes(arr, size);

        if (size == 0)
            rc = EMPTY_ARRAY;
        else
            print_array(arr, size);
    }

    print_error(rc);
   
    return rc;
}
