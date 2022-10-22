#include "check_mtr.h"
#include <check.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int mtr_sum_no_failed = 0, mtr_mult_no_failed = 0, mtr_calc_det_no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = mtr_sum_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_sum_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_sum_no_failed)
        printf("Unit testing mtr_sum error\n");

    s = mtr_mult_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_mult_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_mult_no_failed)
        printf("Unit testing mtr_mult error\n");

    s = mtr_calc_det_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    mtr_calc_det_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != mtr_calc_det_no_failed)
        printf("Unit testing mtr_calc_det error\n");

    if (0 != mtr_sum_no_failed || 0 != mtr_mult_no_failed || 0 != mtr_calc_det_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
