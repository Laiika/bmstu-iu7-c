#include <stdio.h>
#include <string.h>
#include "form_new_string.h"

int delete_symbol(char *const new_str, const int max_size, char *const str, const char ch)
{
    if (str == NULL)
        return STRING_INPUT_ERROR;

    int len = strlen(str), size = 1;

    new_str[0] = ch;

    for (int i = 1; (size < max_size) && (i < len); i++)
        if (str[i] != ch)
            new_str[size++] = str[i];

    new_str[size] = '\0';

    return OK;
}

int add_new_word(char *const new_str, char *word)
{
    char ch = word[0];
    char new_word[WORD_LEN + 1];

    if (delete_symbol(new_word, WORD_LEN, word, ch) != OK)
        return STRING_INPUT_ERROR;

    if (new_str == NULL)
        return STRING_INPUT_ERROR;

    if (strlen(new_str) > 0)
        strcat(new_str, " ");

    strncat(new_str, new_word, strlen(new_word));

    return OK;
}

int form_new_string(char *const new_str, char (*words)[WORD_LEN + 1], const int size)
{
    new_str[0] = '\0';
    char *last = words[size - 1];
    int len = strlen(last);

    for (int i = (size - 2); i >= 0; i--)
        if (!((len == strlen(words[i])) && !strncmp(words[i], last, len)))
            if (add_new_word(new_str, words[i]) != OK)
                return STRING_INPUT_ERROR;

    return OK;
}
