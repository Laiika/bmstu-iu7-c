#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include "../inc/check_queue_push.h"

int main(void)
{
    int queue_push_no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = queue_push_suite();
    runner = srunner_create(s);
    queue_push_no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (0 != queue_push_no_failed)
    {
        printf("Unit testing queue push error\n");
        return EXIT_FAILURE;
    }
        
    printf("Success\n");
    return EXIT_SUCCESS;
}
