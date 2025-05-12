#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>

int main() {
    Fraction current;

    while (true) {
        std::cout << "\nCurrent Fraction: " << current << "\n";
        std::cout << "\nOptions:\n"
            << "1. Enter a fraction manually\n"
            << "2. Add a fraction\n"
            << "3. Subtract a fraction\n"
            << "4. Multiply by a fraction\n"
            << "5. Divide by a fraction\n"
            << "6. Display as Mixed Fraction\n"
            << "7. Clear Fraction\n"
            << "8. Exit\n"
            << "Choice: ";

        int choice;
        std::cin >> choice;

        int n, d;

        try {
            if (choice == 1) {
                std::cout << "Enter numerator: ";
                std::cin >> n;
                std::cout << "Enter denominator: ";
                std::cin >> d;
                current = Fraction(n, d);
            }
            else if (choice == 2) {
                std::cout << "Enter numerator: ";
                std::cin >> n;
                std::cout << "Enter denominator: ";
                std::cin >> d;
                current = current + Fraction(n, d);
            }
            else if (choice == 3) {
                std::cout << "Enter numerator: ";
                std::cin >> n;
                std::cout << "Enter denominator: ";
                std::cin >> d;
                current = current - Fraction(n, d);
            }
            else if (choice == 4) {
                std::cout << "Enter numerator: ";
                std::cin >> n;
                std::cout << "Enter denominator: ";
                std::cin >> d;
                current = current * Fraction(n, d);
            }
            else if (choice == 5) {
                std::cout << "Enter numerator: ";
                std::cin >> n;
                std::cout << "Enter denominator: ";
                std::cin >> d;
                current = current / Fraction(n, d);
            }
            else if (choice == 6) {
                std::cout << "As Mixed Fraction: " << MixedFraction(current) << "\n";
            }
            else if (choice == 7) {
                current = Fraction();
            }
            else if (choice == 8) {
                break;
            }
            else {
                std::cout << "Invalid option.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
