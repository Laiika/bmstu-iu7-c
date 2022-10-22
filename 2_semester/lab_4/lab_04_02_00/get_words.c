#include <stdio.h>
#include <string.h>
#include "get_words.h"

int copy_words(char *const str, char (*words)[WORD_LEN + 1], const int len)
{
    int size = 0;

    for (int i = 0; i < len; i++)
    {
        int word_len = strlen(str + i);

        if (word_len > WORD_LEN)
            return LEN_WORD_ERROR;
            
        if ((i == 0 || str[i - 1] == 0) && (word_len != 0))
        {
            for (int j = 0; j < word_len; j++)
                words[size][j] = *(str + i + j);

            words[size][word_len] = '\0';

            size++;
        }
    }

    return size;
}

int get_words(char *const str, char (*words)[WORD_LEN + 1])
{
    if (str == NULL)
        return STRING_INPUT_ERROR;

    int len = strlen(str);

    for (int i = 0; i < len; i++)
        if (strchr(DELIMS, str[i]))
            str[i] = 0;

    return copy_words(str, words, len);
}
