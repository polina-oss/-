#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char second_name[MAX_NAME_LENGTH];
    char tel[MAX_PHONE_LENGTH];
} Abonent;

Abonent* abonents = NULL;
size_t num_abonents = 0;
size_t max_abonents = 0;

void add_abonent() {
    if (num_abonents == max_abonents) {
        max_abonents++;
        abonents = realloc(abonents, max_abonents * sizeof(Abonent));
    }

    printf("Введите имя: ");
    scanf("%s", abonents[num_abonents].name);
    printf("Введите фамилию: ");
    scanf("%s", abonents[num_abonents].second_name);
    printf("Введите телефон: ");
    scanf("%s", abonents[num_abonents].tel);
    num_abonents++;
}

void delete_abonent() {
    char name[MAX_NAME_LENGTH];
    printf("Введите имя абонента для удаления: ");
    scanf("%s", name);

    for (size_t i = 0; i < num_abonents; i++) {
        if (strcmp(abonents[i].name, name) == 0) {
            num_abonents--;
            if (i != num_abonents) {
                abonents[i] = abonents[num_abonents];
            }
            break;
        }
    }

    if (num_abonents == 0) {
        free(abonents);
        abonents = NULL;
        max_abonents = 0;
    } else if (num_abonents < max_abonents / 2) {
        max_abonents /= 2;
        abonents = realloc(abonents, max_abonents * sizeof(Abonent));
    }
}

void search_abonents() {
    char name[MAX_NAME_LENGTH];
    printf("Введите имя для поиска: ");
    scanf("%s", name);

    printf("Найденные абоненты:\n");
    for (size_t i = 0; i < num_abonents; i++) {
        if (strcmp(abonents[i].name, name) == 0) {
            printf("%s %s, тел: %s\n", abonents[i].name, abonents[i].second_name, abonents[i].tel);
        }
    }
}

void print_all_abonents() {
    printf("Все абоненты:\n");
    for (size_t i = 0; i < num_abonents; i++) {
        printf("%s %s, тел: %s\n", abonents[i].name, abonents[i].second_name, abonents[i].tel);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1) Добавить абонента\n");
        printf("2) Удалить абонента\n");
        printf("3) Поиск абонентов по имени\n");
        printf("4) Вывод всех записей\n");
        printf("5) Выход\n");
        printf("Выберите пункт меню: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_abonent();
            break;
        case 2:
            delete_abonent();
            break;
        case 3:
            search_abonents();
            break;
        case 4:
            print_all_abonents();
            break;
        case 5:
            free(abonents);
            return 0;
        default:
            printf("Неверный выбор.\n");
        }
    }
}

