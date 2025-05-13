#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::vector<std::shared_ptr<TextFilter>> filters = {
        std::make_shared<ReverseFilter>(),
        std::make_shared<UppercaseFilter>(),
        std::make_shared<RemoveVowelsFilter>()
    };

    while (true) {
        std::cout << "\nChoose filter: 0=Reverse, 1=Uppercase, 2=Remove Vowels, 3=Exit\n> ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();
        if (choice == 3) break;
        if (choice >= 0 && choice < 3)
            std::cout << "Result: " << filters[choice]->apply(input) << "\n";
        else
            std::cout << "Invalid choice.\n";
    }
    return 0;
}