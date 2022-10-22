#include "funcs.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Arguments error");
        return ARGS_ERROR;
    }

    FILE *in = fopen(argv[1], "r");
    int rc = OK;

    if (in == NULL)
        rc = ARGS_ERROR;

    if (rc == OK)
    {
        struct text t;
        rc = read_words(in, &t);

        if (rc == OK)
        {
            reverse(&t);

            FILE *out = fopen("out.txt", "w");

            write_words(out, t);

            fclose(out);
        }

        fclose(in);
    }

    print_error(rc);

    return rc;
}