#include <iostream>
#include <unistd.h>
#include <ncurses.h>

void showWelcome() {
    std::string reset = "\033[0m";
    std::string neonCyan = "\033[1;36m";
    std::string neonMagenta = "\033[1;35m";

    std::cout << neonCyan;
    std::cout << R"( 
╔════════════════════════════════════════════════╗
║                                                ║
║         ██████╗ ██████╗ ██████╗                ║
║        ██╔════╝██╔═══██╗██╔══██╗               ║
║        ██║     ██║   ██║██████╔╝               ║
║        ██║     ██║   ██║██╔═══╝                ║
║        ╚██████╗╚██████╔╝██║                    ║
║         ╚═════╝ ╚═════╝ ╚═╝                    ║
║                                                ║
║        BitCLI - Binary Command Line Tool       ║
║        By Luis Fernando                        ║
╚════════════════════════════════════════════════╝
)" << std::endl;

    std::cout << neonMagenta << "\nPresiona ENTER para continuar..." << reset << std::endl;
    std::cin.get(); 
}

// Menú interactivo con ncurses
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
    // Mostrar pantalla de bienvenida
    showWelcome();

    // Inicializar ncurses
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
            case 10: // ENTER
                choice = highlight;
                if (choice == n_options - 1) {
                    endwin(); // Finaliza ncurses
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
