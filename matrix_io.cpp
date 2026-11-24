#include <iostream>
#include <new>
#include "matrix_io.h"

using namespace std;

// Создаёт квадратную матрицу с динамическим выделением памяти.
long long** createMatrix(int n) {
    long long** a = new (nothrow) long long* [n];

    if (a == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < n; i++) {
        a[i] = new (nothrow) long long[n];

        if (a[i] == nullptr) {
            for (int j = 0; j < i; j++) {
                delete[] a[j];
            }

            delete[] a;
            return nullptr;
        }
    }

    return a;
}

// Освобождает память, выделенную для матрицы.
void deleteMatrix(long long** a, int n) {
    if (a == nullptr) {
        return;
    }

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }

    delete[] a;
}

// Вводит элементы матрицы с клавиатуры.
bool inputMatrix(long long** a, int n) {
    cout << "Введите элементы матрицы:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(cin >> a[i][j])) {
                return false;
            }
        }
    }

    return true;
}

// Выводит матрицу на экран.
void outputMatrix(long long** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }

        cout << endl;
    }
}

// Заполняет матрицу тестовыми значениями.
void createTestMatrix(long long** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = i * n + j + 1;
        }
    }
}