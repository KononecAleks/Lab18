#include <iostream>
#include "math_utils.h"
#include "matrix_io.h"
#include "matrix_processor.h"
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    int n;

    cout << "Введите размер квадратной матрицы (от 1 до 10): ";
    if (!(cin >> n) || n < 1 || n > 10) {
        cout << "Ошибка: неверный размер матрицы.\n";
        return 1;
    }

    long long** a = createMatrix(n);

    if (a == nullptr) {
        cout << "Ошибка выделения памяти.\n";
        return 1;
    }

    int choice;

    cout << "\n1 - ввести матрицу";
    cout << "\n2 - использовать тестовую матрицу";
    cout << "\n0 - выход";
    cout << "\nВаш выбор: ";

    if (!(cin >> choice)) {
        cout << "Ошибка ввода.\n";
        deleteMatrix(a, n);
        return 1;
    }

    if (choice == 0) {
        deleteMatrix(a, n);
        cout << "Программа завершена.\n";
        return 0;
    }
    else if (choice == 1) {
        if (!inputMatrix(a, n)) {
            cout << "Ошибка ввода элементов матрицы.\n";
            deleteMatrix(a, n);
            return 1;
        }
    }
    else if (choice == 2) {
        createTestMatrix(a, n);
    }
    else {
        cout << "Ошибка: такого пункта меню нет.\n";
        deleteMatrix(a, n);
        return 1;
    }

    cout << "\nИсходная матрица:\n";
    outputMatrix(a, n);

    long long sum = sumMainDiagonal(a, n, isPrime);

    cout << "\nСумма простых чисел главной диагонали: " << sum << endl;

    replaceAboveDiagonal(a, n);

    cout << "\nМатрица после замены элементов выше главной диагонали:\n";
    outputMatrix(a, n);

    deleteMatrix(a, n);

    return 0;
}