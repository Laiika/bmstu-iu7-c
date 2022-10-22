#include <stdio.h>
#include <string.h>
#include "form_new_string.h"
#include "get_words.h"
#include "read_string.h"

#define NUMBER_WORDS_ERROR -2
#define EMPTY_RESULT_STRING -4
#define WORDS_NUM 128

int main()
{
    char str[STR_LEN + 1], words[WORDS_NUM][WORD_LEN + 1], new_str[STR_LEN + 1];

    if (read_string(str, sizeof(str)) != OK)
        return STRING_INPUT_ERROR;

    int size = get_words(str, words);

    if (size == 0)
        return NUMBER_WORDS_ERROR;

    if (size < 0)
        return size;

    int result = form_new_string(new_str, words, size);

    if (result != OK)
        return result;

    if (strlen(new_str) == 0)
        return EMPTY_RESULT_STRING;

    printf("Result: %s\n", new_str);
    return OK;
}
