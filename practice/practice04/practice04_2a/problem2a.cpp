#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
T calculate(T num1, T num2, char op) {
    if (op == '+') return num1 + num2;
    if (op == '-') return num1 - num2;
    if (op == '*') return num1 * num2;
    if (op == '/') return num1 / num2;
    throw std::invalid_argument("Invalid operation");
}

int main() {
    std::string input1, input2;
    char op;

    std::cout << "Enter first number: ";
    std::getline(std::cin, input1);
    std::cout << "Enter second number: ";
    std::getline(std::cin, input2);
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    bool isDouble = (input1.find('.') != std::string::npos) || (input2.find('.') != std::string::npos);

    if (isDouble) {
        double num1 = std::stod(input1);
        double num2 = std::stod(input2);
        double result = calculate(num1, num2, op);
        std::cout << "Result: " << result << std::endl;
    }
    else {
        int num1 = std::stoi(input1);
        int num2 = std::stoi(input2);
        int result = calculate(num1, num2, op);
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
