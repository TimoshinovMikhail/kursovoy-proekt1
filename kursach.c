
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функция вычисления f(x)
double f(double x) {
    if (x < 0) {
        return (sin(x) - x * cos(x)) / (x * x * x);
    }
    else if (x < 4) {
        return exp(atan(x)) * log(1 + x * x) - (x * x * x) / sqrt(1 + x * x * x * x);
    }
    else {
        return log(1 + x) * (x * x - 3 * x + 2);
    }
}

// 1. Вычислить f(x) в точке
void calculate_value() {
    double x;
    printf("\n--- Вычисление f(x) в точке ---\n");

    printf("Введите x: ");
    scanf("%lf", &x);

    // Проверка, что x не равен 0
    if (fabs(x) < 0.000001) {
        printf("Ошибка: x не может быть равен 0!\n");
        printf("При x = 0 происходит деление на ноль в функции.\n");
        return;
    }

    printf("f(%.4f) = %.6f\n", x, f(x));
}

// 2. Построить таблицу значений
void create_table() {
    double start, step;
    int n;
    printf("\n--- Построение таблицы значений ---\n");
    printf("Начальное x: ");
    scanf("%lf", &start);
    printf("Шаг: ");
    scanf("%lf", &step);
    printf("Количество точек: ");
    scanf("%d", &n);

    printf("\n|   x   |        f(x)|\n");
    printf("|-------|------------|\n");

    double x = start;
    for (int i = 0; i < n; i++) {
        printf("|%6.2f |  %10.4f|\n", x, f(x));
        x += step;
    }
}

// 3. Найти минимум и максимум на отрезке
void find_extremum() {
    double a, b;
    printf("\n--- Поиск минимума и максимума ---\n");
    printf("Начало отрезка: ");
    scanf("%lf", &a);
    printf("Конец отрезка: ");
    scanf("%lf", &b);

    double min_val = f(a);
    double max_val = min_val;
    double min_x = a, max_x = a;

    double step = (b - a) / 1000.0;

    for (double x = a; x <= b; x += step) {
        double result = f(x);
        if (result < min_val) {
            min_val = result;
            min_x = x;
        }
        if (result > max_val) {
            max_val = result;
            max_x = x;
        }
    }

    printf("\nРезультаты:\n");
    printf("Минимум: f(%.4f) = %.6f\n", min_x, min_val);
    printf("Максимум: f(%.4f) = %.6f\n", max_x, max_val);
}

// 4. Найти x по заданному значению f(x)
void find_x_by_y() {
    double y, eps;
    printf("\n--- Поиск x: f(x) = Y ---\n");
    printf("Введите Y: ");
    scanf("%lf", &y);
    printf("Введите точность: ");
    scanf("%lf", &eps);

    printf("\nИщем x такие, что f(x) = %.4f +- %.4f\n", y, eps);
    printf("Поиск на интервале [-10, 10]:\n");

    for (double x = -10.0; x <= 10.0; x += 0.01) {
        double result = f(x);
        if (fabs(result - y) < eps) {
            printf("x = %.4f, f(x) = %.4f\n", x, result);
        }
    }
}

// 5. Вычислить производную в точке
void calculate_derivative() {
    double x;
    printf("\n--- Вычисление производной ---\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    double h = 0.0001;
    double derivative = (f(x + h) - f(x - h)) / (2 * h);
    printf("f'(%.4f) = %.6f\n", x, derivative);
}


// Главное меню
int main() {
    setlocale(LC_CTYPE, "RUS");
    printf("Программа для анализа кусочно-заданной функции\n");

    int choice;
    do {
        printf("\n  |-----------------------------|\n");
        printf("  |     АНАЛИЗ ФУНКЦИИ f(x)     |\n");
        printf("  |-----------------------------|\n");
        printf("  |  1. f(x) в точке            |\n");
        printf("  |  2. Таблица значений        |\n");
        printf("  |  3. Поиск min/max           |\n");
        printf("  |  4. Найти x по Y            |\n");
        printf("  |  5. Производная f'(x)       |\n");
        printf("  |  0. Выход                   |\n");
        printf("  |_____________________________|\n");
        printf("Выберите пункт: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: calculate_value(); break;
        case 2: create_table(); break;
        case 3: find_extremum(); break;
        case 4: find_x_by_y(); break;
        case 5: calculate_derivative(); break;
        case 0: printf("\nВыход из программы.\n"); break;
        default: printf("Неверный выбор! Введите 0-5.\n");
        }
    } while (choice != 0);

    return 0;
}