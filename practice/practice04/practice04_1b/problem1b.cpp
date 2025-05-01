#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello") {
    std::cout << prefix << ", " << name << "!" << std::endl;
}

int main() {
    int choice;

    do {
        std::cout << "1. Default Greeting\n";
        std::cout << "2. Greet by Name\n";
        std::cout << "3. Custom Greeting\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        std::cin.ignore();

        if (choice == 1) {
            greet();
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name);
        }
        else if (choice == 3) {
            std::string prefix, name;
            std::cout << "Enter greeting prefix: ";
            std::getline(std::cin, prefix);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(name, prefix);
        }
        else {
            std::cout << "Invalid option. Please choose again.\n";
        }

        std::cout << "\nDo you want to choose again? (1 to continue, 0 to exit): ";
        std::cin >> choice;
        std::cin.ignore();
    } while (choice == 1);

    std::cout << "Goodbye!" << std::endl;
    return 0;
}
