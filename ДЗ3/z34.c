#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char str[MAX_STRING_LENGTH];
    char substr[MAX_STRING_LENGTH];

    
    printf("Введите строку: ");
    fgets(str, MAX_STRING_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0'; 

    printf("Введите подстроку: ");
    fgets(substr, MAX_STRING_LENGTH, stdin);
    substr[strcspn(substr, "\n")] = '\0'; 

   
    char* result = strstr(str, substr);

    if (result == NULL) {
        printf("Подстрока не найдена.\n");
    } else {
        printf("Подстрока найдена, начиная с позиции %ld\n", result - str);
    }

    return 0;
}
