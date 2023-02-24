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

//------------

// Обмен строк с порядковыми номерами i1 и i2 в матрице m:
void swapRows(Matrix m, int i1, int i2) {
    assert(i1 >= 0 && i1 < m.Rows);
    assert(i2 >= 0 && i2 < m.Rows);

    swap_pointers(&m.values[i1], &m.values[i2]);
}

// Тестирование функции swapRows путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_swapRows() {
    Matrix m = createMatrixFromArray((int[]) { 6, 5, 7, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 11, 12, 113 }, 5, 3);
    int StartRowNo1[3] = { 6, 5, 7 };
    int StartRowNo4[3] = { 11, 12, 113 };
    int check;

    swap_pointers(&m.values[0], &m.values[4]);
    for (int i = 0; i < m.nCols; i++) {
        if ((StartRowNo1[i] == m.values[4][i]) && (StartRowNo4[i] == m.values[2][i]))
        check = 0;
        else
        check = 1;
        assert(check == 0);
    }
    free(startRowNo1);
    free(startRowNo4);
    freeMemMatrix(m);
}

//---

// Обмен колонок с порядковыми номерами j1 и j2 в матрице m:
void swapColumns(Matrix m, int j1, int j2) {
    assert(j1 >= 0 && j1 < m.Rows);
    assert(j2 >= 0 && j2 < m.Rows);

    for (int i = 0; i < m.nRows; i++) {
        swap_pointers(&m.values[i][j1], &m.values[i][j2]);
    }
}

// Тестирование функции swapColumns путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_swapColumns() {
    Matrix m = createMatrixFromArray((int[]) { 6, 5, 7, 1, 0, 7, 1, 0, 7, 1, 0, 7, 11, 12, 113 }, 5, 3);
    int startColNo0[5] = { 6, 1, 1, 1, 11 };
    int startColNo2[5] = { 7, 7, 7, 7, 113 };

    swapColumns(m, 0, 2);

    for (int i = 0; i < m.nRows; i++) {
        assert((startColNo2[i] == m.values[i][0]) && (startColNo0[i] == m.values[i][3]));
    }
    free(StartColNo0);
    free(StartColNo2);
    freeMemMatrix(m);
}