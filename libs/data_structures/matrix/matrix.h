#ifndef C___14__MATRICES_MATRIX_H
#define C___14__MATRICES_MATRIX_H

#endif //C___14__MATRICES_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

