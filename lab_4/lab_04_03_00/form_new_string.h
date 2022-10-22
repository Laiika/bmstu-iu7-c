#ifndef _FORM_NEW_STRING_H_
#define _FORM_NEW_STRING_H_

#define OK 0
#define STRING_INPUT_ERROR -1
#define WORD_LEN 16

int form_new_string(char *const new_str, char (*words)[WORD_LEN + 1], const int size);

#endif
