#include "../header.h"

START_TEST(test_strchr1) {
    char *a = "Hello, world";
    int b = 'H';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strchr2) {
    char *a = "abcdefg";
    int b = 'h';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

// с пустым символом внутри строки
START_TEST(test_strchr3) {
    char *a = "abcde\0fg";
    int b = 'e';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

// с пустым символом внутри строки
START_TEST(test_strchr4) {
    char *a = "abcde\0fg";
    int b = 'g';
    char *a1 = s21_strchr(a, b);
    char *a2 = strchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

Suite * strchr_test(void) {
    Suite *s;
    TCase *tc_strchr1;
    TCase *tc_strchr2;

    s = suite_create("String s21_strchr");

    tc_strchr1 = tcase_create("The letter includes in string");
    tc_strchr2 = tcase_create("The letter doesn't include in string");

    tcase_add_test(tc_strchr1, test_strchr1);
    tcase_add_test(tc_strchr2, test_strchr2);

    tcase_add_test(tc_strchr1, test_strchr3);
    tcase_add_test(tc_strchr2, test_strchr4);

    suite_add_tcase(s, tc_strchr1);
    suite_add_tcase(s, tc_strchr2);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strchr_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
