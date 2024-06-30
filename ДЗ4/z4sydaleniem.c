#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent {
    char name[10];
    char second_name[10];
    char tel[10];
};

void add_abonent(struct abonent* abonents, int* num_abonents) {
    if (*num_abonents == MAX_ABONENTS) {
        printf("Справочник абонентов переполнен!\n");
        return;
    }
    printf("Введите имя абонента: ");
    scanf("%s", abonents[*num_abonents].name);
    printf("Введите фамилию абонента: ");
    scanf("%s", abonents[*num_abonents].second_name);
    printf("Введите телефон абонента: ");
    scanf("%s", abonents[*num_abonents].tel);

    (*num_abonents)++;

    printf("Абонент добавлен успешно!\n");
}

void delete_abonent(struct abonent* abonents, int* num_abonents) {
    char name[10];
    char second_name[10];
    int i, found = 0;
    printf("Введите имя абонента, которого вы хотите удалить: ");
    scanf("%s", name);
    printf("Введите фамилию абонента, которого вы хотите удалить: ");
    scanf("%s", second_name);

    for (i = 0; i < *num_abonents; i++) {
        if (strcmp(abonents[i].name, name) == 0 && strcmp(abonents[i].second_name, second_name) == 0) {
            memset(&abonents[i], 0, sizeof(struct abonent));
            found = 1;
            printf("Абонент %s %s удален успешно!\n", name, second_name);
            break;
        }
    }

    if (!found) {
        printf("Абонент %s %s не найден!\n", name, second_name);
    }
}

void search_abonents(struct abonent* abonents, int num_abonents) {
    char name[10];
    int i, found = 0;
    printf("Введите имя абонента, которого вы хотите найти: ");
    scanf("%s", name);

    for (i = 0; i < num_abonents; i++) {
        if (strcmp(abonents[i].name, name) == 0) {
            printf("Имя: %s, Фамилия: %s, Телефон: %s\n", abonents[i].name, abonents[i].second_name, abonents[i].tel);
            found++;
        }
    }

    if (!found) {
        printf("Абоненты с именем %s не найдены.\n", name);
    } else if (found > 1) {
        printf("Найдено несколько абонентов с именем %s. Пожалуйста, введите фамилию для удаления.\n", name);
    }
}

void print_all_abonents(struct abonent* abonents, int num_abonents) {
    int i;
    for (i = 0; i < num_abonents; i++) {
        if (strlen(abonents[i].name) > 0) {
            printf("%d) Имя: %s, Фамилия: %s, Телефон: %s\n", i+1, abonents[i].name, abonents[i].second_name, abonents[i].tel);
        }
    }
}

int main() {
    struct abonent abonents[MAX_ABONENTS];
    int num_abonents = 0;
    int choice;
    do {
        printf("\n1) Добавить абонента\n2) Удалить абонента\n3) Поиск абонентов по имени\n4) Вывести всех абонентов\n5) Выход\n");
        printf("Введите ваш выбор: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_abonent(abonents, &num_abonents);
                break;
            case 2:
                delete_abonent(abonents, &num_abonents);
                break;
            case 3:
                search_abonents(abonents, num_abonents);
                break;
            case 4:
                print_all_abonents(abonents, num_abonents);
                break;
            case 5:
                printf("Выход...\n");
                break;
            default:
                printf("Неверный выбор, попробуйте еще раз.\n");
        }
    } while (choice != 5);

    return 0;
}
