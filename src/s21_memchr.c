#include "./s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char* s = (unsigned char*)str;
    unsigned char simbol = (unsigned char)c;
    if (n > 0) {
        while (*s != simbol && n != 0) {
            s += 1;
            n--;
        }
    }
    if (n == 0 && *s != simbol)
        s = s21_NULL;
    return (void*)s;
}
