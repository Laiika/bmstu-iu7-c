#include <stdlib.h>
#include "check_find.h"
#include "check_insert.h"
#include "check_copy.h"
#include "check_sorted_insert.h"
#include "check_sort.h"
#include <stdio.h>
#include <check.h>

int main(void)
{
    int find_no_failed = 0, insert_no_failed = 0, copy_no_failed = 0, sorted_insert_no_failed = 0, sort_no_failed = 0;
    Suite *s;
    SRunner *runner;

    // тестим find
    s = find_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    find_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != find_no_failed)
        printf("Unit testing find error\n");

    // тестим insert
    s = insert_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    insert_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != insert_no_failed)
        printf("Unit testing insert error\n");

    // тестим copy
    s = copy_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    copy_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != copy_no_failed)
        printf("Unit testing copy error\n");

    // тестим sorted_insert
    s = sorted_insert_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    sorted_insert_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != sorted_insert_no_failed)
        printf("Unit testing sorted_insert error\n");

    // тестим sort
    s = sort_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    sort_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != sort_no_failed)
        printf("Unit testing sort error\n");

    if (0 != find_no_failed || 0 != insert_no_failed || 0 != copy_no_failed || 0 != sorted_insert_no_failed || 0 != sort_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
