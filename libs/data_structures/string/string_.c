#include "string_.h"
#include <assert.h>
#include <ctype.h>

// #17.1

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

// #17.2

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

// #17.3

// Возвращает указатель на первый символ, отличный от пробельных,
// расположенный (на ленте памяти) начиная с begin и заканчивая ноль-символом.
// Если адрес не найден, возвращает адрес первого ноль-символа.
char* findNonSpace(char* begin) {
    while (isspace(*begin) != 0 && *begin != '\0') {
        begin++;
    }
    return begin;
}

// Тестирование функции findNonSpace.
void findNonSpace_test(char* (findNonSpace)(char* s)) {
    char s1[] = "\n\n\nWFFB";
    char s2[] = "\nillf";
    assert(findNonSpace(s1) == &s1[3]);
    assert(findNonSpace(s2) == &s2[1]);
}

// # 17.4

// Возвращает указатель на первый пробельный символ, расположенный (на ленте памяти)
// начиная с begin или на первый ноль-символ.
char* findSpace(char* begin) {
    while (isspace(*begin) == 0 && *begin != '\0') {
        begin++;
    }
    return begin;
}

// Тестирование функции findSpace.
void findSpace_test(char* (findSpace)(char* s)) {
    char s1[] = "\n\n\nWFFB";
    char s2[] = "code3\nx\n";
    assert(findSpace(s1) == &s1[0]);
    assert(findSpace(s2) == &s2[5]);
}

// #17.5, 17.6

// Возвращает указатель на первый справа символ, отличный от пробельных,
// расположенный (на летне памяти) начиная с rbegin и заканчивая rend;
// если символ не найден, возвращает rend.
char* findNonSpaceReverse(char* rbegin, char* rend) {
    while (rbegin > rend)
    {
        if (isspace(*rbegin) == 0)
            return rbegin;
        rbegin--;
    }
    return rend;
}

// Возвращает указатель на первый справа пробельный символ, расположенный (на летне памяти)
// начиная с rbegin и заканчивая rend; если символ не найден, возвращает rend.
char* findSpaceReverse(char* rbegin, char* rend) {
    while (rbegin > rend)
    {
        if (isspace(*rbegin) != 0)
            return rbegin;
        rbegin--;
    }
    return rend;
}