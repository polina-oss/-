#include <stdio.h>
#include "libcalc.h"

int main() {
    int choice, a, b;

    while (1) {
        printf("Калькулятор:\n");
        printf("1) Сложение\n");
        printf("2) Вычитание\n");
        printf("3) Умножение\n");
        printf("4) Деление\n");
        printf("5) Выход\n");
        printf("Введите номер операции: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            printf("Результат: %d\n", add(a, b));
            break;
        case 2:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            printf("Результат: %d\n", sub(a, b));
            break;
        case 3:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            printf("Результат: %d\n", mul(a, b));
            break;
        case 4:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            if (b == 0) {
                printf("Ошибка: деление на ноль\n");
            } else {
                printf("Результат: %.2f\n", div(a, b));
            }
            break;
        case 5:
            return 0;
        default:
            printf("Неверный выбор\n");
        }
    }
}

