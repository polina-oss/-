#include <stdio.h>

int main() {
    unsigned int num, count = 0;
    int i;

    printf("введите число: ");
    scanf("%u", &num);

    for (i = 0; i < 32; i++) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }

    printf("количество единиц в: %d\n", count);

    return 0;
}

