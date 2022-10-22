#include <stdio.h>
#include <string.h>
#include "read_string.h"
#include "get_words.h"
#include "get_words_no_repet.h"
#include "print_result.h"

#define NUMBER_WORDS_ERROR -2
#define WORDS_NUM 128

int main()
{
    char str[STR_LEN + 1];

    if (read_string(str, sizeof(str)) != OK)
        return STRING_INPUT_ERROR;

    char words[WORDS_NUM][WORD_LEN + 1];
    int size = get_words(str, words);

    if (size == 0)
        return NUMBER_WORDS_ERROR;

    if (size < 0)
        return size;

    char words2[WORDS_NUM][WORD_LEN + 1];
    int size2 = get_words_no_repet(words, size, words2);
    
    print_result(words, size, words2, size2);
    return OK;
}
