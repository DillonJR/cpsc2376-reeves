#include <iostream>
#include <string>

int main() {
    float redPotion{ 0.0f };
    float bluePotion{ 0.0f };
    float* flask{ nullptr };

    std::string choice;

    while (true) {
        std::cout << "Which potion would you like to add liquid to? (Red, Blue, or Done): ";
        std::cin >> choice;

        for (auto& ch : choice) ch = tolower(ch);

        if (choice == "done") {
            std::cout << "Potion brewing complete!" << std::endl;
            break;
        }
        else if (choice == "red") {
            flask = &redPotion;
        }
        else if (choice == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Unknown potion. Try again." << std::endl;
            continue;
        }

        float amount;
        std::cout << "How many milliliters would you like to add? ";
        std::cin >> amount;

        if (amount < 0) {
            std::cout << "You can't add negative potion! Try again." << std::endl;
            continue;
        }

        *flask += amount;

        std::cout << "\nPotion Levels:" << std::endl;
        std::cout << "Red Potion: " << redPotion << " mL" << std::endl;
        std::cout << "Blue Potion: " << bluePotion << " mL\n" << std::endl;
    }

    return 0;
}
