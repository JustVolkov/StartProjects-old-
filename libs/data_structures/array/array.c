#include "array.h"

// Возвращает сумму массива a размера n.
int getSum(int* a, int n) {
    int sumOfArray = 0;
    for (int i = 0; i < n; i++) {
        sumOfArray += a[i];
    }
    return sumOfArray;
}

// Возвращает True, если массив a не содержит одинаковых элементов, False в противном случае.
bool isUnique(int* a, int n) {
    int i = 0;
    while (i < n - 1) {
        int j = i + 1;
        while (j < n) {
            if (a[i] == a[j])
                return false;
            j++;
        }
        i++;
    }
    return true;
}

