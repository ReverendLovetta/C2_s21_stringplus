#include "s21_string.h"

/* Функция получает строку и переводит символы с верхнего регистра в нижний,
 * Возвращает копию этой строки
 */

void *s21_to_lower(const char *str) {
    static char *copy;
    copy = (char *)malloc(sizeof(char)*(s21_strlen(str) + 1));
    int i = 0;
    if (copy) {
        while (str[i] != '\0') {
            if (str[i] >= 65 && str[i] <= 90) {
                copy[i] = str[i] + 32;
            } else {
                copy[i] = str[i];
            }
            i++;
        }
        copy[i] = '\0';
    }
    char *pointer;
    if (i == 0) {
        pointer = s21_NULL;
    } else {
        pointer = copy;
    }
    return (void *)pointer;
}
