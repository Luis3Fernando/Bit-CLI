#include <ncurses.h>
#include <string>
#include <vector>
#include "menu.h"

std::vector<std::string> options = {
    "1. Sumar",
    "2. Restar",
    "3. Multiplicar",
    "4. Dividir",
    "5. Convertir palabra a binario",
    "6. Salir"
};

void runMenu() {
    initscr();             
    noecho();
    cbreak(); 
    keypad(stdscr, TRUE);
    curs_set(0);

    int choice = 0;
    int ch;

    while (true) {
        clear();
        attron(COLOR_PAIR(1));
        mvprintw(1, 5, "===== BIT-CLI =====");
        attroff(COLOR_PAIR(1));

        for (int i = 0; i < options.size(); ++i) {
            if (i == choice) {
                attron(A_REVERSE);
                mvprintw(3 + i, 7, options[i].c_str());
                attroff(A_REVERSE);
            } else {
                mvprintw(3 + i, 7, options[i].c_str());
            }
        }

        ch = getch();

        switch (ch) {
            case KEY_UP:
                choice = (choice - 1 + options.size()) % options.size();
                break;
            case KEY_DOWN:
                choice = (choice + 1) % options.size();
                break;
            case '\n': // ENTER
                if (choice == 5) { // Salir
                    endwin();
                    return;
                } else {
                    clear();
                    mvprintw(10, 5, "Seleccionaste: %s", options[choice].c_str());
                    mvprintw(12, 5, "Presiona una tecla para volver al menú...");
                    getch();
                }
                break;
        }
    }

    endwin();
}
