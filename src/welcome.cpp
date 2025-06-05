#include <iostream>
#include <unistd.h>

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
