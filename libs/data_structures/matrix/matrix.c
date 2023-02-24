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

//------------

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

//------------

// Освобождает память, выделенную под хранение матрицы m:
void freeMemMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц:
void freeMemMatrices(Matrix* m, int nRows) {
    for (int i = 0; i < nRows; i++) {
        freeMemMatrix(m[i]);
    }
    free(m);
}

//------------

// Ввод матрицы m:
void inputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

// Вывод матрицы m:
void outputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf(" %d ", m.values[i][j]);
        }
        printf("\n\n");
    }
}

//---

// Ввод массива из nMatrices матриц, хранящейся по адресу ms:
void inputMatrices(Matrix* ms, int n) {
    for (int i = 0; i < n; i++) {
        inputMatrix(ms[i]);
    }
}

// Вывод массива из nMatrices матриц, хранящейся по адресу ms:
void outputMatrices(Matrix* ms, int n) {
    for (int i = 0; i < n; i++) {
        outputMatrix(ms[i]);
    }
}
