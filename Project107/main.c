#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Якщо M_PI не визначено, визначаємо вручну
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Функція для обчислення значення f(x)
double f(double x) {
    return 0.5 - 0.25 * M_PI * fabs(sin(x));
}

// Функція для обчислення інтегралу методом прямокутників
double rectangle_integral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Функція для обчислення інтегралу методом трапецій
double trapezoidal_integral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2;
    for (int i = 1; i <= n - 1; i++) {
        sum += f(a + i * h);
    }
    return h * sum;
}

// Функція для обчислення інтегралу методом Сімпсона
double simpson_integral(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i <= n - 1; i++) {
        if (i % 2 == 1) {
            sum += 4 * f(a + i * h);
        }
        else {
            sum += 2 * f(a + i * h);
        }
    }
    return h / 3 * sum;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Встановлюємо межі інтегрування
    double a = 0;
    double b = 1;

    // Кількість підінтервалів
    int n = 100;

    // Обчислюємо інтеграли
    double rectangle_result = rectangle_integral(a, b, n);
    double trapezoidal_result = trapezoidal_integral(a, b, n);
    double simpson_result = simpson_integral(a, b, n);

    // Виводимо результати
    printf("Интеграл методом прямоугольников: %f\n", rectangle_result);
    printf("Интеграл методом трапеций: %f\n", trapezoidal_result);
    printf("Интеграл методом Симпсона: %f\n", simpson_result);

    return 0;
}
