#include <stdio.h>

int main() {
    int n;
    printf("Введите размер матрицы N: ");
    scanf("%d", &n);

    int matrix[n][n];
    int count = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = count++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

