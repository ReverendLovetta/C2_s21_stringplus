#include "../header.h"

START_TEST(test_strrchr1) {
    char *a = "Hello, world";
    int b = 'H';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

START_TEST(test_strrchr2) {
    char *a = "abcdefg";
    int b = 'h';
    char *a1 = s21_strrchr(a, b);
    char *a2 = strrchr(a, b);
    ck_assert_ptr_eq(a1, a2);
}
END_TEST

Suite * strrchr_test(void) {
    Suite *s;
    TCase *tc_strrchr1;
    TCase *tc_strrchr2;

    s = suite_create("String s21_strrchr");

    tc_strrchr1 = tcase_create("The letter includes in string");
    tc_strrchr2 = tcase_create("The letter doesn't include in string");

    tcase_add_test(tc_strrchr1, test_strrchr1);
    tcase_add_test(tc_strrchr2, test_strrchr2);

    suite_add_tcase(s, tc_strrchr1);
    suite_add_tcase(s, tc_strrchr2);

    return s;
}

int main() {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = strrchr_test();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
