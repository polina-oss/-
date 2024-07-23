#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *file;
    char buffer[100];

    // Открываем файл для записи
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Не удалось открыть файл для записи.\n");
        return 1;
    }

    // Записываем строку в файл
    fprintf(file, "String from file");
    fclose(file);

    printf("Файл 'output.txt' создан.\n");

    // Открываем файл для чтения
    file = fopen("output.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл для чтения.\n");
        return 1;
    }

    // Читаем строку из файла
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Не удалось прочитать строку из файла.\n");
        fclose(file);
        return 1;
    }

    // Выводим строку на экран
    printf("Содержимое файла: %s\n", buffer);

    fclose(file);
    return 0;
}

