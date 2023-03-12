#include "string_.h"
#include <assert.h>

// Возвращает длину строки s.
size_t strlen(char* begin) {
    char* end = begin;
    while (*end != '\0') {
        end++;
    }
    return end - begin;
}

void strlen_test(int(strlen)(char* begin)) {
    char s1[] = "ABCDEF";
    char s2[] = "CAT";
    char s3[] = "A";
    char s4[] = "";
    assert(strlen(s1) == 6);
    assert(strlen(s2) == 3);
    assert(strlen(s3) == 1);
    assert(strlen(s4) == 0);
}