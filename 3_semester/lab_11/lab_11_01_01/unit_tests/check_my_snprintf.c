#include "check_my_snprintf.h"
#include "my_string.h"
#include <limits.h>
#include <stdio.h>
#include <check.h>

START_TEST(test_my_snprintf_c_usual)
{
    char str[10], str2[10];
    int rc = snprintf(str, 10, "%c test %c", 'a', 'b');
    int rc2 = my_snprintf(str2, 10, "%c test %c", 'a', 'b');

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_c_buf_is_less)
{
    char str[3], str2[3], f[] = "%c test %c";
    int rc = snprintf(str, 3, f, 'a', 'b');
    int rc2 = my_snprintf(str2, 3, f, 'a', 'b');

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_s_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%s test %s", "first", "second");
    int rc2 = my_snprintf(str2, 30, "%s test %s", "first", "second");

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_s_buf_is_less)
{
    char str[3], str2[3], f[] = "%s test %s";
    int rc = snprintf(str, 3, f, "first", "second");
    int rc2 = my_snprintf(str2, 3, f, "first", "second");

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_i_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%i test %i %i", 100, -11, 0);
    int rc2 = my_snprintf(str2, 30, "%i test %i %i", 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_i_buf_is_less)
{
    char str[3], str2[3], f[] = "%i test %i %i";
    int rc = snprintf(str, 3, f, 100, -11, 0);
    int rc2 = my_snprintf(str2, 3, f, 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_i_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%i test", INT_MAX);
    int rc2 = my_snprintf(str2, 80, "%i test", INT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_i_min_int)
{
    char str[80], str2[80];

    int rc = snprintf(str, 80, "%i test", INT_MIN);
    int rc2 = my_snprintf(str2, 80, "%i test", INT_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_d_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%d test %d %d", 100, -11, 0);
    int rc2 = my_snprintf(str2, 30, "%d test %d %d", 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_d_buf_is_less)
{
    char str[3], str2[3], f[] = "%d test %d %d";
    int rc = snprintf(str, 3, f, 100, -11, 0);
    int rc2 = my_snprintf(str2, 3, f, 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_d_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%d test", INT_MAX);
    int rc2 = my_snprintf(str2, 80, "%d test", INT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_d_min_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%d test", INT_MIN);
    int rc2 = my_snprintf(str2, 80, "%d test", INT_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_x_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%x test %x", 21332, 0);
    int rc2 = my_snprintf(str2, 80, "%x test %x", 21332, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
    
}
END_TEST

START_TEST(test_my_snprintf_x_buf_is_less)
{
    char str[6], str2[6], f[] = "%x test %x";
    int rc = snprintf(str, 6, f, 21332, 0);
    int rc2 = my_snprintf(str2, 6, f, 21332, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_x_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%x test", UINT_MAX);
    int rc2 = my_snprintf(str2, 80, "%x test", UINT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_x_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%x test", -678);
    int rc2 = my_snprintf(str2, 80, "%x test", -678);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_o_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%o test %o", 21332, 0);
    int rc2 = my_snprintf(str2, 80, "%o test %o", 21332, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_o_buf_is_less)
{
    char str[6], str2[6], f[] = "%o test %o";
    int rc = snprintf(str, 6, f, 21332, 0);
    int rc2 = my_snprintf(str2, 6, f, 21332, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_o_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%o test", UINT_MAX);
    int rc2 = my_snprintf(str2, 80, "%o test", UINT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_o_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%o test", -678);
    int rc2 = my_snprintf(str2, 80, "%o test", -678);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hi_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%hi test %hi %hi", 100, -11, 0);
    int rc2 = my_snprintf(str2, 30, "%hi test %hi %hi", 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hi_buf_is_less)
{
    char str[3], str2[3], f[] = "%hi test %hi %hi";
    int rc = snprintf(str, 3, f, 100, -11, 0);
    int rc2 = my_snprintf(str2, 3, f, 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hi_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hi test", SHRT_MAX);
    int rc2 = my_snprintf(str2, 80, "%hi test", SHRT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hi_min_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hi test", SHRT_MIN);
    int rc2 = my_snprintf(str2, 80, "%hi test", SHRT_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hd_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%hd test %hd %hd", 100, -11, 0);
    int rc2 = my_snprintf(str2, 30, "%hd test %hd %hd", 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hd_buf_is_less)
{
    char str[3], str2[3], f[] = "%hd test %hd %hd";
    int rc = snprintf(str, 3, f, 100, -11, 0);
    int rc2 = my_snprintf(str2, 3, f, 100, -11, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hd_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hd test", SHRT_MAX);
    int rc2 = my_snprintf(str2, 80, "%hd test", SHRT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hd_min_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hd test", SHRT_MIN);
    int rc2 = my_snprintf(str2, 80, "%hd test", SHRT_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hx_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hx test %hx", 213, 0);
    int rc2 = my_snprintf(str2, 80, "%hx test %hx", 213, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
    
}
END_TEST

START_TEST(test_my_snprintf_hx_buf_is_less)
{
    char str[6], str2[6], f[] = "%hx test %hx";
    int rc = snprintf(str, 6, f, 213, 0);
    int rc2 = my_snprintf(str2, 6, f, 213, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hx_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hx test", USHRT_MAX);
    int rc2 = my_snprintf(str2, 80, "%hx test", USHRT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_hx_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%hx test", -678);
    int rc2 = my_snprintf(str2, 80, "%hx test", -678);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ho_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%ho test %ho", 213, 0);
    int rc2 = my_snprintf(str2, 80, "%ho test %ho", 213, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
    
}
END_TEST

START_TEST(test_my_snprintf_ho_buf_is_less)
{
    char str[6], str2[6], f[] = "%ho test %ho";
    int rc = snprintf(str, 6, f, 213, 0);
    int rc2 = my_snprintf(str2, 6, f, 213, 0);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ho_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%ho test", USHRT_MAX);
    int rc2 = my_snprintf(str2, 80, "%ho test", USHRT_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ho_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%ho test", -678);
    int rc2 = my_snprintf(str2, 80, "%ho test", -678);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_li_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%li test %li %li", 100L, -11L, 0L);
    int rc2 = my_snprintf(str2, 30, "%li test %li %li", 100L, -11L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_li_buf_is_less)
{
    char str[3], str2[3], f[] = "%li test %li %li";
    int rc = snprintf(str, 3, f, 100L, -11L, 0L);
    int rc2 = my_snprintf(str2, 3, f, 100L, -11L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_li_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%li test", LONG_MAX);
    int rc2 = my_snprintf(str2, 80, "%li test", LONG_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_li_min_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%li test", LONG_MIN);
    int rc2 = my_snprintf(str2, 80, "%li test", LONG_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ld_usual)
{
    char str[30], str2[30];
    int rc = snprintf(str, 30, "%ld test %ld %ld", 100L, -11L, 0L);
    int rc2 = my_snprintf(str2, 30, "%ld test %ld %ld", 100L, -11L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ld_buf_is_less)
{
    char str[3], str2[3], f[] = "%ld test %ld %ld";
    int rc = snprintf(str, 3, f, 100L, -11L, 0L);
    int rc2 = my_snprintf(str2, 3, f, 100L, -11L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ld_max_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%ld test", LONG_MAX);
    int rc2 = my_snprintf(str2, 80, "%ld test", LONG_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_ld_min_int)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%ld test", LONG_MIN);
    int rc2 = my_snprintf(str2, 80, "%ld test", LONG_MIN);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lx_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lx test %lx", 213L, 0L);
    int rc2 = my_snprintf(str2, 80, "%lx test %lx", 213L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
    
}
END_TEST

START_TEST(test_my_snprintf_lx_buf_is_less)
{
    char str[6], str2[6], f[] = "%lx test %lx";
    int rc = snprintf(str, 6, f, 213L, 0L);
    int rc2 = my_snprintf(str2, 6, f, 213L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lx_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lx test", ULONG_MAX);
    int rc2 = my_snprintf(str2, 80, "%lx test", ULONG_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lx_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lx test", -678L);
    int rc2 = my_snprintf(str2, 80, "%lx test", -678L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lo_usual)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lo test %lo", 213L, 0L);
    int rc2 = my_snprintf(str2, 80, "%lo test %lo", 213L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
    
}
END_TEST

START_TEST(test_my_snprintf_lo_buf_is_less)
{
    char str[6], str2[6], f[] = "%lo test %lo";
    int rc = snprintf(str, 6, f, 213L, 0L);
    int rc2 = my_snprintf(str2, 6, f, 213L, 0L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lo_max)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lo test", ULONG_MAX);
    int rc2 = my_snprintf(str2, 80, "%lo test", ULONG_MAX);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_lo_neg)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%lo test", -678L);
    int rc2 = my_snprintf(str2, 80, "%lo test", -678L);

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_snprintf_n_0)
{
    int rc = snprintf(NULL, 0, "test");
    int rc2 = my_snprintf(NULL, 0, "test");

    ck_assert_int_eq(rc, rc2);
}
END_TEST

START_TEST(test_my_snprintf_perc)
{
    char str[80], str2[80];
    int rc = snprintf(str, 80, "%% test");
    int rc2 = my_snprintf(str2, 80, "%% test");

    ck_assert_int_eq(rc, rc2);
    ck_assert_str_eq(str, str2);
}
END_TEST

Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos_c;
    TCase *tc_pos_s;
    TCase *tc_pos_i;
    TCase *tc_pos_d;
    TCase *tc_pos_x;
    TCase *tc_pos_o;
    TCase *tc_pos_hi;
    TCase *tc_pos_hd;
    TCase *tc_pos_hx;
    TCase *tc_pos_ho;
    TCase *tc_pos_li;
    TCase *tc_pos_ld;
    TCase *tc_pos_lx;
    TCase *tc_pos_lo;
    TCase *tc_pos_all;

    s = suite_create("my_snprintf");

    tc_pos_c = tcase_create("pos c");
    tcase_add_test(tc_pos_c, test_my_snprintf_c_usual);
    tcase_add_test(tc_pos_c, test_my_snprintf_c_buf_is_less);
    suite_add_tcase(s, tc_pos_c);

    tc_pos_s = tcase_create("pos s");
    tcase_add_test(tc_pos_s, test_my_snprintf_s_usual);
    tcase_add_test(tc_pos_s, test_my_snprintf_s_buf_is_less);
    suite_add_tcase(s, tc_pos_s);

    tc_pos_i = tcase_create("pos i");
    tcase_add_test(tc_pos_i, test_my_snprintf_i_usual);
    tcase_add_test(tc_pos_i, test_my_snprintf_i_buf_is_less);
    tcase_add_test(tc_pos_i, test_my_snprintf_i_max_int);
    tcase_add_test(tc_pos_i, test_my_snprintf_i_min_int);
    suite_add_tcase(s, tc_pos_i);

    tc_pos_d = tcase_create("pos d");
    tcase_add_test(tc_pos_d, test_my_snprintf_d_usual);
    tcase_add_test(tc_pos_d, test_my_snprintf_d_buf_is_less);
    tcase_add_test(tc_pos_d, test_my_snprintf_d_max_int);
    tcase_add_test(tc_pos_d, test_my_snprintf_d_min_int);
    suite_add_tcase(s, tc_pos_d);

    tc_pos_x = tcase_create("pos x");
    tcase_add_test(tc_pos_x, test_my_snprintf_x_usual);
    tcase_add_test(tc_pos_x, test_my_snprintf_x_buf_is_less);
    tcase_add_test(tc_pos_x, test_my_snprintf_x_max);
    tcase_add_test(tc_pos_x, test_my_snprintf_x_neg);
    suite_add_tcase(s, tc_pos_x);

    tc_pos_o = tcase_create("pos o");
    tcase_add_test(tc_pos_o, test_my_snprintf_o_usual);
    tcase_add_test(tc_pos_o, test_my_snprintf_o_buf_is_less);
    tcase_add_test(tc_pos_o, test_my_snprintf_o_max);
    tcase_add_test(tc_pos_o, test_my_snprintf_o_neg);
    suite_add_tcase(s, tc_pos_o);

    tc_pos_hi = tcase_create("pos hi");
    tcase_add_test(tc_pos_hi, test_my_snprintf_hi_usual);
    tcase_add_test(tc_pos_hi, test_my_snprintf_hi_buf_is_less);
    tcase_add_test(tc_pos_hi, test_my_snprintf_hi_max_int);
    tcase_add_test(tc_pos_hi, test_my_snprintf_hi_min_int);
    suite_add_tcase(s, tc_pos_hi);

    tc_pos_hd = tcase_create("pos hd");
    tcase_add_test(tc_pos_hd, test_my_snprintf_hd_usual);
    tcase_add_test(tc_pos_hd, test_my_snprintf_hd_buf_is_less);
    tcase_add_test(tc_pos_hd, test_my_snprintf_hd_max_int);
    tcase_add_test(tc_pos_hd, test_my_snprintf_hd_min_int);
    suite_add_tcase(s, tc_pos_hd);

    tc_pos_hx = tcase_create("pos hx");
    tcase_add_test(tc_pos_hx, test_my_snprintf_hx_usual);
    tcase_add_test(tc_pos_hx, test_my_snprintf_hx_buf_is_less);
    tcase_add_test(tc_pos_hx, test_my_snprintf_hx_max);
    tcase_add_test(tc_pos_hx, test_my_snprintf_hx_neg);
    suite_add_tcase(s, tc_pos_hx);

    tc_pos_ho = tcase_create("pos ho");
    tcase_add_test(tc_pos_ho, test_my_snprintf_ho_usual);
    tcase_add_test(tc_pos_ho, test_my_snprintf_ho_buf_is_less);
    tcase_add_test(tc_pos_ho, test_my_snprintf_ho_max);
    tcase_add_test(tc_pos_ho, test_my_snprintf_ho_neg);
    suite_add_tcase(s, tc_pos_ho);

    tc_pos_li = tcase_create("pos li");
    tcase_add_test(tc_pos_li, test_my_snprintf_li_usual);
    tcase_add_test(tc_pos_li, test_my_snprintf_li_buf_is_less);
    tcase_add_test(tc_pos_li, test_my_snprintf_li_max_int);
    tcase_add_test(tc_pos_li, test_my_snprintf_li_min_int);
    suite_add_tcase(s, tc_pos_li);

    tc_pos_ld = tcase_create("pos ld");
    tcase_add_test(tc_pos_ld, test_my_snprintf_ld_usual);
    tcase_add_test(tc_pos_ld, test_my_snprintf_ld_buf_is_less);
    tcase_add_test(tc_pos_ld, test_my_snprintf_ld_max_int);
    tcase_add_test(tc_pos_ld, test_my_snprintf_ld_min_int);
    suite_add_tcase(s, tc_pos_ld);

    tc_pos_lx = tcase_create("pos lx");
    tcase_add_test(tc_pos_lx, test_my_snprintf_lx_usual);
    tcase_add_test(tc_pos_lx, test_my_snprintf_lx_buf_is_less);
    tcase_add_test(tc_pos_lx, test_my_snprintf_lx_max);
    tcase_add_test(tc_pos_lx, test_my_snprintf_lx_neg);
    suite_add_tcase(s, tc_pos_lx);

    tc_pos_lo = tcase_create("pos lo");
    tcase_add_test(tc_pos_lo, test_my_snprintf_lo_usual);
    tcase_add_test(tc_pos_lo, test_my_snprintf_lo_buf_is_less);
    tcase_add_test(tc_pos_lo, test_my_snprintf_lo_max);
    tcase_add_test(tc_pos_lo, test_my_snprintf_lo_neg);
    suite_add_tcase(s, tc_pos_lo);

    tc_pos_all = tcase_create("pos all");
    tcase_add_test(tc_pos_all, test_my_snprintf_n_0);
    tcase_add_test(tc_pos_all, test_my_snprintf_perc);
    suite_add_tcase(s, tc_pos_all);

    return s;
}
