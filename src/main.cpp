#include <ncurses.h>

const char* options[] = {
    "Suma binaria",
    "Resta binaria",
    "Operaciones bitwise",
    "Conversión binario/decimal",
    "Salir"
};
const int n_options = sizeof(options) / sizeof(options[0]);

void printMenu(int highlight) {
    clear();
    mvprintw(0, 0, "=== BitCLI Menu ===");
    for (int i = 0; i < n_options; i++) {
        if (i == highlight)
            attron(A_REVERSE);
        mvprintw(i + 2, 2, options[i]);
        if (i == highlight)
            attroff(A_REVERSE);
    }
    refresh();
}

int main() {
    initscr();              
    cbreak();             
    noecho();               
    keypad(stdscr, TRUE);  

    int highlight = 0;
    int choice = -1;
    int input;

    while (true) {
        printMenu(highlight);
        input = getch();

        switch (input) {
            case KEY_UP:
                highlight = (highlight - 1 + n_options) % n_options;
                break;
            case KEY_DOWN:
                highlight = (highlight + 1) % n_options;
                break;
            case 10:
                choice = highlight;
                if (choice == n_options - 1) {
                    endwin();
                    return 0;
                }
                mvprintw(n_options + 4, 2, "Seleccionaste: %s", options[choice]);
                mvprintw(n_options + 5, 2, "Presiona cualquier tecla...");
                getch();
                break;
        }
    }

    endwin();
    return 0;
}
