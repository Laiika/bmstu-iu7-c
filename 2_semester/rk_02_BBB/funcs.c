#include "funcs.h"

int read_words(FILE *file, struct text *t)
{
    t->n = 0;
    char str[STR_LEN + 1];

    while (fgets(str, sizeof(str), file) != NULL)
    {
        int i = 0, j = 0;

        while (str[i] == ' ')
            i++;

        while (str[i] != ' ')
        {
            t->words[t->n][j] = str[i];
            i++;
            j++;
        }

        t->words[t->n][j] = '\0';
        t->n++;
    }

    if (feof(file))
        return OK;
    else
        return FILE_ERROR;
}

void reverse(struct text *t)
{
    char word[WORD_LEN + 1];
    int n = t->n;

    for (int i = 0; i < n / 2; i++)
    {
        strncpy(word, t->words[i], strlen(t->words[i]));
        strncpy(t->words[i], t->words[n - i - 1], strlen(t->words[n - i - 1]));
        strncpy(t->words[n - i - 1], word, strlen(word));
    }

    int i = 0;

    while (i < n)
    {
        size_t len = strlen(t->words[i]);

        for (int j = 0; j < i; j++)
            if (strlen(t->words[j]) == len && (!strncmp(t->words[j], t->words[i], len)))
            {
                for (int k = i; k < n - 1; k++)
                    strncpy(t->words[k], t->words[k + 1], strlen(t->words[k + 1])); 

                n--;
                break;
            }
            else
                i++;

        if (i == 0)
            i++;
    }

    t->n = n;
}

void write_words(FILE *file, struct text t)
{
    for (int i = 0; i < t.n; i++)
        fprintf(file, "%s", t.words[i]);
}

void print_error(const int rc)
{
    if (rc == ARGS_ERROR)
        printf("Arguments error");
    else if (rc == FILE_ERROR)
        printf("File error");
}

