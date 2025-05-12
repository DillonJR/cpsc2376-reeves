#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int count;

    std::cout << "How many numbers would you like to enter? ";
    std::cin >> count;

    std::cout << "Enter " << count << " integers:\n";
    for (int i = 0; i < count; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    std::cout << "Numbers in reverse order:\n";
    for (std::vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << std::endl;
    return 0;
}
