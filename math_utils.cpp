#include "math_utils.h"

// Проверяет, является ли число простым.
bool isPrime(long long n) {
    if (n < 2) {
        return false;
    }

    for (long long i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Рекурсивно вычисляет факториал числа.
long long factorial(int n) {
    if (n < 0 || n > 20) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

// Вспомогательная функция для рекурсивного вычисления суммы цифр.
static int sumDigitsUnsigned(unsigned long long n) {
    if (n < 10) {
        return static_cast<int>(n);
    }

    return static_cast<int>(n % 10) + sumDigitsUnsigned(n / 10);
}

// Вычисляет сумму цифр числа, в том числе отрицательного.
int sumDigits(long long n) {
    unsigned long long value;

    if (n < 0) {
        value = 0ULL - static_cast<unsigned long long>(n);
    }
    else {
        value = static_cast<unsigned long long>(n);
    }

    return sumDigitsUnsigned(value);
}