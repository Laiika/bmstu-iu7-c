#include "check_arr_lib.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int arr_fill_no_failed = 0, arr_copy_no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = arr_fill_fib_nums_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    arr_fill_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != arr_fill_no_failed)
        printf("Unit testing arr_fill_fib_nums error\n");

    s = arr_copy_first_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    arr_copy_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != arr_copy_no_failed)
        printf("Unit testing arr_copy_first error\n");

    if (0 != arr_fill_no_failed || 0 != arr_copy_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
