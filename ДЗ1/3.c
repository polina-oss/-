#include <stdio.h>

int main() {
    unsigned int num, count = 0;
    int i;

    printf("Enter a positive integer: ");
    scanf("%u", &num);

    for (i = 0; i < 32; i++) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }

    printf("The number of 1's in the binary representation is: %d\n", count);

    return 0;
}

