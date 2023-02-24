#include "matrix.h"

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swap_pointers(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

