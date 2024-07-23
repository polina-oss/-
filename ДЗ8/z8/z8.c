#include <stdio.h>
#include <dlfcn.h>
#include "libcalc.h"

int main() {
    void *handle;
    int (*add_func)(int, int);
    int (*sub_func)(int, int);
    int (*mul_func)(int, int);
    double (*div_func)(int, int);

    int choice, a, b;

    handle = dlopen("./libcalc.so", RTLD_LAZY);
    if (!handle) {
        printf("Ошибка загрузки библиотеки: %s\n", dlerror());
        return 1;
    }

    // Получение указателей на функции
    add_func = (int (*)(int, int))dlsym(handle, "add");
    sub_func = (int (*)(int, int))dlsym(handle, "sub");
    mul_func = (int (*)(int, int))dlsym(handle, "mul");
    div_func = (double (*)(int, int))dlsym(handle, "div");

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
            printf("Результат: %d\n", add_func(a, b));
            break;
        case 2:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            printf("Результат: %d\n", sub_func(a, b));
            break;
        case 3:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            printf("Результат: %d\n", mul_func(a, b));
            break;
        case 4:
            printf("Введите два числа: ");
            scanf("%d %d", &a, &b);
            if (b == 0) {
                printf("Ошибка: деление на ноль\n");
            } else {
                printf("Результат: %.2f\n", div_func(a, b));
            }
            break;
        case 5:
            dlclose(handle);
            return 0;
        default:
            printf("Неверный выбор\n");
        }
    }
}

