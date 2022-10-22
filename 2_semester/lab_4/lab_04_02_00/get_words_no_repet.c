#include <stdio.h>
#include <string.h>
#include "get_words_no_repet.h"

int get_words_no_repet(char (*words)[WORD_LEN + 1], const int size, char (*words2)[WORD_LEN + 1])
{
    int size2 = 0;

    for (int i = 0; i < size; i++)
    {
        int flag = 0, len = strlen(words[i]);

        for (int j = 0; (j < size2 && flag == 0); j++)
            if ((len == strlen(words2[j])) && !strncmp(words[i], words2[j], len))
                flag = 1;

        if (!flag)
        {
            for (int j = 0; j < len; j++)
                words2[size2][j] = words[i][j];

            words2[size2][len] = '\0';
            size2++;
        }
    }

    return size2;
}
