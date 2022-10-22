#include "check_mysort.h"
#include "check_key.h"
#include "stdio.h"
#include <stdlib.h>
#include <check.h>

int main(void)
{
    int mysort_no_failed = 0, key_no_failed = 0;
    Suite *s;
    SRunner *runner;

    // тестим mysort
    s = mysort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mysort_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mysort_no_failed)
        printf("Unit testing mysort error\n");

    // тестим key
    s = key_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    key_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != key_no_failed)
        printf("Unit testing key error\n");

    if (0 != mysort_no_failed || 0 != key_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
