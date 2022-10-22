#ifndef _GET_WORDS_H_
#define _GET_WORDS_H_

#define STRING_INPUT_ERROR -1
#define LEN_WORD_ERROR -3
#define WORD_LEN 16
#define DELIMS ",;:-.!? "

int get_words(char *const str, char (*words)[WORD_LEN + 1]);

#endif
