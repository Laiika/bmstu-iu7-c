#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>
#include <string.h>

#define OK 0
#define ARGS_ERROR -1
#define FILE_ERROR -2
#define WORDS_NUM 100
#define WORD_LEN  11
#define STR_LEN 256

struct text
{
    int n;
    char words[WORDS_NUM][WORD_LEN + 1];
};

int read_words(FILE *file, struct text *t);
void reverse(struct text *t);
void write_words(FILE *file, struct text t);
void print_error(const int rc);

#endif