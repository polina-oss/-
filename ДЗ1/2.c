#include <stdio.h>

int main() {
    int num, i;

    printf("введите число: ");
    scanf("%d", &num);

    printf("двоичная система %d: ", num);


 for (i = 31; i >= 0; i--) {
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }

    printf("\n");

    return 0;
}

