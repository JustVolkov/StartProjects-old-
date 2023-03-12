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

// Тестирование функции strlen.
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

//----------

/* Возвращает указатель на первый элемент с кодом ch, расположенный
(на ленте памяти) между адресами begin и end (не включая end);
если символ не найден, возвращает значение end.
 */
char* find(char* begin, char* end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

// Тестирование функции find.
void find_test(char*(find)(char* begin, char* end, int ch)) {
    char s[] = "ISDAAAT";
    char* p_begin = &s[0];
    char* p_end = &s[strlen(s)];
    // Числовые коды и соответствующие им символы (в ASCII):
    int ch1 = 65;	// A
    int ch2 = 73;	// I
    int ch3 = 61;	// =
    assert(find(p_begin, p_end, ch1) == &s[3]);
    assert(find(p_begin, p_end, ch2) == &s[0]);
}