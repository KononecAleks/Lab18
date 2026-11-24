#include "matrix_processor.h"
#include "math_utils.h"

// Проверяет, находится ли элемент выше главной диагонали.
bool isAboveDiagonal(int i, int j) {
    return j > i;
}

// Проверяет, находится ли элемент ниже главной диагонали.
bool isBelowDiagonal(int i, int j) {
    return i > j;
}

// Находит сумму элементов главной диагонали, удовлетворяющих предикату.
long long sumMainDiagonal(long long** a, int n, bool (*predicate)(long long)) {
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        if (predicate(a[i][i])) {
            sum += a[i][i];
        }
    }

    return sum;
}

// Заменяет элементы выше главной диагонали их факториалами.
void replaceAboveDiagonal(long long** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isAboveDiagonal(i, j)) {
                if (a[i][j] >= 0 && a[i][j] <= 20) {
                    a[i][j] = factorial(static_cast<int>(a[i][j]));
                }
                else {
                    a[i][j] = -1;
                }
            }
        }
    }
}