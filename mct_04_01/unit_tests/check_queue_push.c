#include "../inc/check_queue_push.h"

START_TEST(test_queue_push_empty_queue)
{
    queue_t q;
    int rc;

    queue_init(&q);
    rc = queue_push(&q, 333);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(q.st1.ps->val, 333);

    queue_free(&q);
}
END_TEST

START_TEST(test_queue_push_usual)
{
    queue_t q;
    int rc;

    queue_init(&q);
    rc = queue_push(&q, 333);

    if (EXIT_SUCCESS == rc)
    {
        rc = queue_push(&q, 3211);

        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(q.st1.ps->val, 3211);
        queue_free(&q);
    }
}
END_TEST

Suite* queue_push_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("queue_push");
    
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_queue_push_empty_queue);
    tcase_add_test(tc_pos, test_queue_push_usual);

    suite_add_tcase(s, tc_pos);

    return s;
}
