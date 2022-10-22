#include "check_mtr.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int mtr_exp_no_failed = 0, mtr_mult_no_failed = 0, mtr_cut_no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = mtr_exp_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_exp_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_exp_no_failed)
        printf("Unit testing mtr_exp error\n");

    s = mtr_mult_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_mult_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_mult_no_failed)
        printf("Unit testing mtr_mult error\n");

    s = mtr_cut_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_cut_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_cut_no_failed)
        printf("Unit testing mtr_cut error\n");

    if (0 != mtr_exp_no_failed || 0 != mtr_mult_no_failed || 0 != mtr_cut_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
