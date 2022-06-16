#include "../header.h"
/*Возвращает новую строку, в которой указанная строка (str) вставлена 
 *в указанную позицию (start_index) в данной строке (src). 
 * Подается позиция внутри строки src */
START_TEST(test_insert1) {
    const char src[20] = "aaaa";
    const char str[20] = "bbbb";
    const char result[] = "abbbbaaa";
    s21_size_t index = 1;
    char *d = s21_insert(src, str, index);
    int a = strcmp(d, result);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Подается позиция в конец строки src */
START_TEST(test_insert2) {
    const char src[20] = "aaaa";
    const char str[20] = "bbbb";
    const char result[] = "aaaabbbb";
    s21_size_t index = 4;
    char *d = s21_insert(src, str, index);
    int a = strcmp(d, result);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST
/* Подается позиция за пределами строки src */
START_TEST(test_insert3) {
    int flag = 0;
    const char src[20] = "aaaa";
    const char str[20] = "bbbb";
    const char *result = s21_NULL;
    s21_size_t index = 5;
    char *d = s21_insert(src, str, index);
    if (d == result) {
        flag = 1;
    }
    free(d);
    ck_assert_int_eq(flag, 1);
}
END_TEST
/* Подается позиция за пределами строки src */
START_TEST(test_insert4) {
    const char src[20] = "aaaa";
    const char str[20] = "\0";
    const char result[] = "aaaa";
    s21_size_t index = 2;
    char *d = s21_insert(src, str, index);
    int a = strcmp(d, result);
    free(d);
    ck_assert_int_eq(a, 0);
}
END_TEST
START_TEST(test_insert5) {
    int flag = 0;
    const char *src = s21_NULL;
    const char str[20] = "asdafs";
    const char *result = s21_NULL;
    s21_size_t index = 2;
    char *d = s21_insert(src, str, index);
    if (d == result) {
        flag = 1;
    }
    free(d);
    ck_assert_int_eq(flag, 1);
}
END_TEST
START_TEST(test_insert6) {
    int flag = 0;
    const char *str = s21_NULL;
    const char src[20] = "asdafs";
    const char *result = s21_NULL;
    s21_size_t index = 2;
    char *d = s21_insert(src, str, index);
    if (d == result) {
        flag = 1;
    }
    free(d);
    ck_assert_int_eq(flag, 1);
}
END_TEST
START_TEST(test_insert7) {
    int flag = 0;
    const char str[20] = "stuck";
    const char src[20] = "asdafs";
    const char *result = s21_NULL;
    s21_size_t index = -2;
    char *d = s21_insert(src, str, index);
    if (d == result) {
        flag = 1;
    }
    free(d);
    ck_assert_int_eq(flag, 1);
}
END_TEST
Suite * string_test(void) {
    Suite *s;
    TCase *tc_to_insert1, *tc_to_insert2, *tc_to_insert3, *tc_to_insert4, *tc_to_insert5;
    s = suite_create("String insert");
    tc_to_insert1 = tcase_create("Core_insert1");
    tcase_add_test(tc_to_insert1, test_insert1);
    suite_add_tcase(s, tc_to_insert1);
    tc_to_insert2 = tcase_create("Core_insert2");
    tcase_add_test(tc_to_insert2, test_insert2);
    suite_add_tcase(s, tc_to_insert2);
    tc_to_insert3 = tcase_create("Core_insert3");
    tcase_add_test(tc_to_insert3, test_insert3);
    suite_add_tcase(s, tc_to_insert3);
    tc_to_insert4 = tcase_create("Core_insert4");
    tcase_add_test(tc_to_insert4, test_insert4);
    suite_add_tcase(s, tc_to_insert4);
    tc_to_insert5 = tcase_create("Core_insert5");
    tcase_add_test(tc_to_insert5, test_insert5);
    tcase_add_test(tc_to_insert5, test_insert6);
    tcase_add_test(tc_to_insert5, test_insert7);
    suite_add_tcase(s, tc_to_insert5);
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
