#include <stdio.h>

#define N 10
#define INPUT_ERROR -1
#define OK 0
#define TRUE 1
#define FALSE 2

int is_prime(int n)
{
    for (int i = 0; i < (n / 2); i++)
        if ((n % i) == 0)
            return FALSE;

    return TRUE;
}

int main(void)
{
    int a[N] = { 0 };
    int *pb = a, *pe = a;
    int number = scanf("%d", &number);

    while (number > 0)
    {
        *pe = number % 10;
        number = number / 10;
        pe++;
    }

    int *copypb = pb, *copype = pe;

    while (copypb < copype)
    {
        int temp = *copype;
        *copype = *copypb;
        *copypb = temp;

        copype--;
        copypb++;
    }

    while ((pb + 1) < pe)
    {
        if (is_prime((*pb) * 10 + (*(pb + 1))) == TRUE)
            printf("%d ", ((*pb) * 10 + (*(pb + 1))));
        pb++;
    }

    return OK;
}