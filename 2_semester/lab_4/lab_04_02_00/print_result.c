#include <stdio.h>
#include <string.h>
#include "print_result.h"

void print_result(char (*words)[WORD_LEN + 1], const int size, char (*words2)[WORD_LEN + 1], const int size2)
{
    printf("Result: \n");

    for (int i = 0; i < size2; i++)
    {
        int count = 0, len = strlen(words2[i]);

        for (int j = 0; j < size; j++)
            if ((len == strlen(words[j])) && !strncmp(words2[i], words[j], len))
                count++;

        printf("%s %d\n", words2[i], count);
    }
}
