#include "funcs.h"

void print_entry(FILE *const file, struct product prod)
{
    fprintf(file, "%s\n", prod.name);
    fprintf(file, "%s\n", prod.producer);
    fprintf(file, "%u\n", prod.price);
    fprintf(file, "%u\n", prod.amount);
}
