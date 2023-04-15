#ifndef C___14__MATRICES_VECTOR_H
#define C___14__MATRICES_VECTOR_H

#endif //C___14__MATRICES_VECTOR_H

#include "stdio.h"

// 14.1

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

// 14.2

vector createVector(size_t  capacity);