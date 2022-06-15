#include "../header.h"

START_TEST(test_s21_memchr1) {
    // str - заполнена, c - не больше len(str), n - вся строка case 1
    char str1[20] = "TESTing1code";
    int c = 5;
    s21_size_t n = 13;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr2) {
    // str - заполнена, c - не больше len(str) (просто изменил c), n - вся строка case 1
    char str1[20] = "TESTing1code";
    int c = 3;
    s21_size_t n = 13;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr3) {
    // str - заполнена, c - не больше len(str), n - часть строки, c не включает case 1
    char str1[] = "TESTing1code";
    int c = 7;
    s21_size_t n = 2;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr4) {
    // str - заполнена, c - не больше len(str), n - часть строки, c включает case 1
    char str1[] = "2221code";
    int c = 1;
    s21_size_t n = 5;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr5) {
    // str - пустая, c - не больше len(str), n - часть строки, c включает case 2
    char str1[] = "\0";
    int c = 2;
    s21_size_t n = 1;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr6) {
    // str - заполнена, c - существует, n > len(str), c включает case 3
    char str1[20] = "2221code";
    int c = 1;
    s21_size_t n = 15;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr7) {
    // str - заполнена, c -  не существует, n < len(str), c включает case 3
    char str1[20] = "222133332";
    int c = 4;
    s21_size_t n = 15;
    ck_assert_ptr_eq(s21_memchr(str1, c, n), memchr(str1, c, n));
}
END_TEST

START_TEST(test_s21_memchr8) {
    // str - заполненная строка, c -  не существует, n > len(str), c включает case 4
    char str[20] = "privetChel";
    int c = 'd';
    s21_size_t n = 4;
    ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST

Suite * string_test(void) {
    Suite *s;
    TCase *tc_s21_memchr1, *tc_s21_memchr2, *tc_s21_memchr3, *tc_s21_memchr4;
    s = suite_create("String memchr");
    tc_s21_memchr1 = tcase_create("Core_stirng1");
    tcase_add_test(tc_s21_memchr1, test_s21_memchr1);
    tcase_add_test(tc_s21_memchr1, test_s21_memchr2);
    tcase_add_test(tc_s21_memchr1, test_s21_memchr3);
    tcase_add_test(tc_s21_memchr1, test_s21_memchr4);
    suite_add_tcase(s, tc_s21_memchr1);
    tc_s21_memchr2 = tcase_create("Core_stirng2");
    tcase_add_test(tc_s21_memchr2, test_s21_memchr5);
    suite_add_tcase(s, tc_s21_memchr2);
    tc_s21_memchr3 = tcase_create("Core_stirng3");
    tcase_add_test(tc_s21_memchr3, test_s21_memchr6);
    tcase_add_test(tc_s21_memchr3, test_s21_memchr7);
    suite_add_tcase(s, tc_s21_memchr3);
    tc_s21_memchr4 = tcase_create("Core_stirng4");
    tcase_add_test(tc_s21_memchr4, test_s21_memchr8);
    suite_add_tcase(s, tc_s21_memchr4);
    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;
    s = string_test();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
