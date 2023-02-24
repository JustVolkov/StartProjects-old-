#include "matrix.h"

// Обмен значений переменных.
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Обмен значений переменных по указателям.
void swap_pointers(int** a, int** b) {
    int* t = *a;
    *a = *b;
    *b = t;
}

// Размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.
Matrix getMemMatrix(int nRows, int nCols) {
    int** values = (int**)malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int*)malloc(sizeof(int) * nCols);
    return (Matrix) { values, nRows, nCols };
}

// Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу.
Matrix* getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    Matrix* ms = (Matrix*)malloc(sizeof(Matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}


