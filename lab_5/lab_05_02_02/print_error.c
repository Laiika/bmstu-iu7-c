#include <errno.h>
#include <string.h>
#include "funcs.h"

void print_error(const int rc)
{
    if (ARGC_ERROR == rc)
        printf("main.exe <file-name>\n");
    else if (FILE_ERROR == rc)
        printf("%s\n", strerror(errno));
    else if (READ_ERROR == rc)
        printf("Error while reading from file\n");
    else if (EMPTY_FILE == rc)
        printf("File is empty\n");
    else if (NO_NUMBERS == rc)
        printf("No double number in file\n");
    else if (PARAM_ERROR == rc)
        printf("Function parameters error");
}
