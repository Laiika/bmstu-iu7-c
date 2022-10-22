#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>

#define OK 0
#define ARGS_ERROR 53
#define FILE_ERROR -1
#define NO_NEEDED_ENTRY -2
#define INPUT_ERROR -3
#define PARAM_ERROR -4
#define NAME_LEN 30
#define PRODUCER_LEN 15

struct product
{
    char name[NAME_LEN + 1];
    char producer[PRODUCER_LEN + 1];
    unsigned int price;
    unsigned int amount;
};

int file_size(FILE *file, size_t *const size);
int get_entry_by_pos(FILE *file, size_t pos, struct product *prod);
int put_entry_by_pos(FILE *file, size_t pos, struct product prod);
void print_entry(FILE *const file, struct product prod);
int read_entry(struct product *prod);

int sort_products(const char *const file1, const char *const file2);
int print_spec_products(char *const f, char *const substr);
int add_product(char *const f);

#endif
