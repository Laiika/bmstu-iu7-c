#include "check_my_snprintf.h"
#include "stdio.h"
#include <stdlib.h>
#include <check.h>

int main(void)
{
    int my_snprintf_no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = my_snprintf_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    my_snprintf_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != my_snprintf_no_failed)
        printf("Unit testing my_snprintf error\n");;

    if (0 != my_snprintf_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
