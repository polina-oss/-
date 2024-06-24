#include <stdio.h>

int main() {
    int n;
    printf("Введите размер массива N: ");
    scanf("%d", &n);

    int arr[n];
    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Массив в обратном порядке: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

