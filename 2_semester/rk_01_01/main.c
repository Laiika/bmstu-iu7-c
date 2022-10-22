#include <stdio.h>

#define N 10
#define INPUT_ERROR -1
#define OK 0

void print_array(int *pb, int *pe)
{
    while (pb < pe)
    {
        printf("%d ", *pb);
        pb++;
    }
}


int main(void)
{
    int a[N] = { 0 };
    int b[N] = { 0 };
    int *pb2 = b, *pe2 = b;
    int *pb1 = a, *pe1 = a;
    int n;

    if ((scanf("%d", &n) != 1) || (n <= 0) || (n > N))
    {
        return INPUT_ERROR;
    }

    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", pe1) != 1)
        {
            return INPUT_ERROR;
        }

        pe1++;
    }

    while (pb1 < pe1)
    {
        *pe2 = (*pb1) * (*(pe1 - 1));
        pb1++;
        pe1--;
        pe2++;
    }

    print_array(pb2, pe2);

    return OK;
}