#include <stdio.h>

void changeThirdByte(int *num, int newByte) {
unsigned char *ptr = (unsigned char *)num;
ptr += 2; 
*ptr = (unsigned char)newByte; 
}

int main() {
int num, newByte;
printf("Введите целое положительное число: ");
scanf("%d", &num);

if (num < 0) {
    printf("Число должно быть положительным.\n");
    return 1;
}

printf("Введите число для замены третьего байта: ");
scanf("%d", &newByte);

if (newByte < 0 || newByte > 255) {
    printf("Число для замены третьего байта должно быть от 0 до 255.\n");
    return 1;
}

changeThirdByte(&num, newByte);

printf("Измененное число: %d\n", num);

return 0;
}

