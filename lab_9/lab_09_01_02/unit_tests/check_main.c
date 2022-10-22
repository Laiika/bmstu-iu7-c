#include <stdlib.h>
#include <check.h>
#include <stdio.h>
#include "check_sort_items_array.h"

int main(void)
{
    int sort_items_array_no_failed = 0;
    Suite *s;
    SRunner *runner;

    // тестим sort_items_array
    s = sort_items_array_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    sort_items_array_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != sort_items_array_no_failed)
        printf("Unit testing sort_items_array error\n");

    if (0 != sort_items_array_no_failed)
        return EXIT_FAILURE;
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
