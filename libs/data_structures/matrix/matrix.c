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

//------------

// Возвращает значение «истина», если матрица m является квадратной,
// «ложь» – в противном случае:
bool isSquareMatrix(Matrix* m) {
    return m->nCols == m->nRows;
}

// Возвращает значение «истина», если матрицы m1 и m2 равны,
// «ложь» – в противном случае:
bool areTwoMatricesEqual(Matrix* m1, Matrix* m2) {
    if ((m1->nCols != m2->nCols) || (m1->nRows != m2->nRows))
        return false;
    else {
        for (int rowIndex = 0; rowIndex < m1->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m1->nCols; colIndex++) {
                if (m1->values[rowIndex][colIndex] != m2-> values[rowIndex][colIndex])
                return false;
            }
        }
        return true;
    }
}

// Возвращает значение «истина», если матрица m является единичной,
// «ложь» – в противном случае:
bool isEMatrix(Matrix* m) {
    if (m->nCols != m->nRows)
        return false;
    else {
        int sumOfRow = 0;
        for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m->nCols; colIndex++) {
                sumOfRow += m->values[rowIndex][colIndex];
            }
            if ((sumOfRow != 1) || (m->values[rowIndex][rowIndex] != 1))
                return false;
        }
        return false;
    }
}

// Возвращает значение «истина», если матрица m является симметричной,
// «ложь» – в противном случае:
bool isSymmetricMatrix(Matrix* m) {
    if (m->nCols != m->nRows)
        return false;
    else {
        for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
            for (int colIndex = 0; colIndex < m->nRows; colIndex++) {
                if (m->values[rowIndex][colIndex] != m-> values[colIndex][rowIndex])
                return false;
            }
        }
        return true;
    }
}

//------------

// Транспонирование квадратной матрицы m:
void transposeSquareMatrix(Matrix* m) {
    int startIndexForNextIteration = 0;
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        for (int colIndex = startIndexForNextIteration; colIndex < m->nRows; colIndex++) {
            swap_pointers(&m->values[rowIndex][colIndex], &m-> values[colIndex][rowIndex]);
        }
        startIndexForNextIteration++;
    }
}

// Тестирование функции transposeSquareMatrix путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_transposeSquareMatrix() {
    Matrix m = createMatrixFromArray((int[]) { 1, 3, 7, 5, 63, 26, 19, 0, 1 }, 3, 3);
    transposeSquareMatrix(&m);
    Matrix transposed_m = createMatrixFromArray((int[]) { 1, 5, 19, 3, 63, 0, 7, 26, 1 }, 3, 3);
    for (int i = 0; i < m.nRows; i++) {
        for (int l = 0; l < m.nRows; l++) {
            assert(m.values[i][l] == transposed_m.values[i][l]);
        }
    }
}

 // Транспонирование матрицы m. Возвращает транспонированную матрицу.
Matrix transposeMatrix(Matrix* m) {
    Matrix transposedMatrix = getMemMatrix(m->nCols, m->nRows);
    for (int rowIndex = 0; rowIndex < m->nRows; rowIndex++) {
        for (int colIndex = 0; colIndex < m->nCols; colIndex++) {
            transposedMatrix.values[colIndex][rowIndex] = m-> values[rowIndex][colIndex];
        }
    }
    return transposedMatrix;
}

// Тестирование функции transposeMatrix  путём ввода произвольной матрицы
// и сравнения полученного результата с ожидаемым (с помощью assert):
void test_transposeMatrix() {
    Matrix m = createMatrixFromArray((int[]) { 4, 14, 6, 65, 1, 5, 3, 17, 18, 0 }, 5, 2);
    Matrix m_transposed = transposeMatrix(&m);
    Matrix m_afterTranspExample = createMatrixFromArray((int[]) { 4, 6, 1, 3, 18, 14, 65, 5, 17, 0 }, 2, 5);

    for (int i = 0; i < m_transposed.nRows; i++) {
        for (int l = 0; l < m_transposed.nCols; l++) {
            assert(m_afterTranspExample.values[i][l] == m_transposed.values[i][l]);
        }
    }
    freeMemMatrix(m_transposed);
    freeMemMatrix(m_afterTranspExample);
}