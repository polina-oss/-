#include <ncurses.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ITEMS 20
#define MAX_PATH 256

int current_panel = 0;
char current_path[MAX_PATH] = "/";
char paths[2][MAX_PATH] = {"/", "/"};
int selected_items[2][MAX_ITEMS] = {0};
int num_items[2] = {0, 0};

void draw_file_list(int panel_index) {
    clear();
    mvprintw(0, 0, "Current path: %s", paths[panel_index]);

    DIR *dir;
    struct dirent *entry;
    int i = 0;

    if ((dir = opendir(paths[panel_index])) != NULL) {
        while ((entry = readdir(dir)) != NULL && i < MAX_ITEMS) {
            if (entry->d_name[0] != '.') {
                if (selected_items[panel_index][i])
                    attron(A_REVERSE);
                mvprintw(i + 1, 0, "%s", entry->d_name);
                attroff(A_REVERSE);
                i++;
            }
        }
        closedir(dir);
    }

    num_items[panel_index] = i;
    refresh();
}

void navigate_files(int panel_index, int direction) {
    int i;
    for (i = 0; i < num_items[panel_index]; i++) {
        if (selected_items[panel_index][i]) {
            selected_items[panel_index][i] = 0;
            break;
        }
    }

    i += direction;
    if (i < 0)
        i = num_items[panel_index] - 1;
    else if (i >= num_items[panel_index])
        i = 0;

    selected_items[panel_index][i] = 1;
    draw_file_list(panel_index);
}

char* get_selected_item(int panel_index) {
    int i;
    for (i = 0; i < num_items[panel_index]; i++) {
        if (selected_items[panel_index][i]) {
            DIR *dir = opendir(paths[panel_index]);
            struct dirent *entry;
            int j = 0;
            while ((entry = readdir(dir)) != NULL && j <= i) {
                if (entry->d_name[0] != '.') {
                    if (j == i)
                        return entry->d_name;
                    j++;
                }
            }
            closedir(dir);
        }
    }
    return NULL;
}

int get_selected_index(int panel_index) {
    int i;
    for (i = 0; i < num_items[panel_index]; i++) {
        if (selected_items[panel_index][i])
            return i;
    }
    return -1;
}

void handle_enter_key(int panel_index) {
    char selected_item[MAX_PATH];
    strcpy(selected_item, paths[panel_index]);
    strcat(selected_item, "/");
    strcat(selected_item, get_selected_item(panel_index));

    struct stat path_stat;
    if (stat(selected_item, &path_stat) == 0 && S_ISDIR(path_stat.st_mode)) {
        strcpy(paths[panel_index], selected_item);
        selected_items[panel_index][get_selected_index(panel_index)] = 0;
    } else {
        char command[MAX_PATH + 10];
        sprintf(command, "xdg-open %s", selected_item);
        system(command);
    }
}

void exit_program() {
    endwin();
    exit(0);
}

int main() {
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);

    while (1) {
        draw_file_list(current_panel);

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                navigate_files(current_panel, -1);
                break;
            case KEY_DOWN:
                navigate_files(current_panel, 1);
                break;
            case '\t':
                current_panel = 1 - current_panel;
                break;
            case 10: // Enter key
                handle_enter_key(current_panel);
                break;
            case 17: // Ctrl+Q
            case 27: // Esc
                exit_program();
                break;
        }
    }

    return 0;
}
