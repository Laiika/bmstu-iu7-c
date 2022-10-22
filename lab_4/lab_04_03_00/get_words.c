#include <stdio.h>
#include <string.h>
#include "get_words.h"

int get_words(char *const str, char (*words)[WORD_LEN + 1])
{
    if (str == NULL)
        return STRING_INPUT_ERROR;
        
    int size = 0;
    char *pword = strtok(str, DELIMS);

    while (pword)
    {
        if (strlen(pword) > WORD_LEN)
            return LEN_WORD_ERROR;

        for (int i = 0; i < strlen(pword); i++)
            words[size][i] = pword[i];

        words[size][strlen(pword)] = '\0';
        size++;
        pword = strtok(NULL, DELIMS);
    }

    return size;
}
