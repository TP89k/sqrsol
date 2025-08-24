#include <stdio.h>
#include <math.h>
#include <TXLib.h>

//@param [in]  a  кожффицент a
//@param [in]  b  коэффицент b
//@param [in]  c  коэффицент c
//@param [out] x1 первый корень уравнения
//@param [out] x2 второй корень уравнения (при наличии)


void solveQuadraticEquation(double a, double b, double c) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("Бесконечное количество решений\n");
            } else {
                printf("Нет орней\n");
            }
        } else {
            double root = -c / b;
            printf("Один корень: x = %.2f\n", root);
        }
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double x1 = (-b + sqrt(discriminant)) / (2 * a);
        double x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Два корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else if (discriminant == 0) {
        double x1 = -b / (2 * a);
        printf("Один корень: x = %.2f\n", x1);
    }
    else {
        printf("Нет корней\n");
    }
}

int main() {
    double a, b, c;

    printf("Решение уравнения вида ax^2 + bx + c = 0\n");
    printf("Введите коэффициенты a, b, c: ");

    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Введите три числа\n");
        return 1;
    }

    solveQuadraticEquation(a, b, c);

    return 0;
}