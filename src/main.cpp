#include "MainWindow.hpp"
#include <lib.rs.h>

int main(int argc, char **argv) {
    std::cout << "Hello World!" << std::endl;
    std::cout << "Rust says: " << add(5, 37) << std::endl;

    auto app = QApplication(argc, argv);

    auto window = MainWindow();
    window.show();

    return app.exec();
}