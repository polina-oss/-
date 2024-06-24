#include <stdio.h>

int main() {
    int num, newByte, result;

    // Ввод исходного числа
    printf("Введите целое положительное число: ");
    scanf("%d", &num);

    // Проверка на корректность ввода (положительное число)
    if (num <= 0) {
        printf("Введите положительное число\n");
        return 1;
    }

    // Ввод числа для замены
    printf("Введите число для замены третьего байта: ");
    scanf("%d", &newByte);

    // Проверка на корректность ввода (от 0 до 255)
    if (newByte < 0 || newByte > 255) {
        printf("Введите число от 0 до 255\n");
        return 1;
    }

    // Замена третьего байта в числе
    result = (num & 0xFFFF00FF) | (newByte << 8);

    printf("Измененное число: %d\n", result);

    return 0;
}

