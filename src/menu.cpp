#include <iostream>
#include <cstdlib>  
#include <limits>  

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    cout << "\nPresiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void showMainMenu() {
    int option;

    do {
        clearScreen();
        cout << "=============================\n";
        cout << "       🚀 BitCLI Menu        \n";
        cout << "=============================\n";
        cout << "1. Suma binaria\n";
        cout << "2. Resta binaria\n";
        cout << "3. Operaciones bitwise\n";
        cout << "4. Conversión decimal/binario\n";
        cout << "0. Salir\n";
        cout << "-----------------------------\n";
        cout << "Elige una opción: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "👉 Suma binaria seleccionada (aquí irá la función)\n";
                break;
            case 2:
                cout << "👉 Resta binaria seleccionada (aquí irá la función)\n";
                break;
            case 3:
                cout << "👉 Bitwise seleccionada (aquí irá la función)\n";
                break;
            case 4:
                cout << "👉 Conversión seleccionada (aquí irá la función)\n";
                break;
            case 0:
                cout << "👋 Saliendo...\n";
                break;
            default:
                cout << "❌ Opción no válida.\n";
        }

        if (option != 0) waitForEnter();

    } while (option != 0);
}
