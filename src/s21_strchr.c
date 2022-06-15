#include "./s21_string.h"

// Функция strchr ищет первое вхождение символа, код которого указан в аргументе int c в строке,
// на которую указывает аргумент str.
// Возвращает указатель на искомый символ
// В случае отсутствия искомого символа, возвращает NULL

char *s21_strchr(const char *str, int c) {
    int i = 0;
    char *res = s21_NULL;
    if (s21_strlen(str) == 0) {
    } else {
        while (str[i] != '\0') {
            if (str[i] == c) {
                res = (char*)str+i;
                break;
            }
            i++;
        }
    }
    return res;
}
