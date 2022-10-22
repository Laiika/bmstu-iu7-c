#include <stdlib.h>
#include "check_list_add_end.h"
#include "check_list_calc_polyn.h"
#include "check_list_calc_dx.h"
#include "check_lists_calc_sum.h"
#include "check_list_get_by_cond.h"
#include <stdio.h>
#include <check.h>

int main(void)
{
    int add_no_failed = 0, polyn_no_failed = 0, dx_no_failed = 0, sum_no_failed = 0, cond_no_failed = 0;
    Suite *s;
    SRunner *runner;

    // тестим list_add_end
    s = list_add_end_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    add_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != add_no_failed)
        printf("Unit testing list_add_end error\n");

    // тестим list_calc_polyn
    s = list_calc_polyn_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    polyn_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != polyn_no_failed)
        printf("Unit testing list_calc_polyn error\n");

    // тестим list_calc_dx
    s = list_calc_dx_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    dx_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != dx_no_failed)
        printf("Unit testing list_calc_dx error\n");

    // тестим lists_calc_sum
    s = lists_calc_sum_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    sum_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != sum_no_failed)
        printf("Unit testing lists_calc_sum error\n");

    // тестим list_get_by_cond
    s = list_get_by_cond_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    cond_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != cond_no_failed)
        printf("Unit testing list_get_by_cond error\n");

    if (0 != add_no_failed || 0 != polyn_no_failed || 0 != dx_no_failed || 0 != sum_no_failed || 0 != cond_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
