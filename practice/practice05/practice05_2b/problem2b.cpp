#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    int count;

    std::cout << "How many numbers? ";
    std::cin >> count;

    std::cout << "Enter " << count << " integers:\n";
    for (int i = 0; i < count; ++i) {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    if (!numbers.empty()) {
        auto maxIt = std::max_element(numbers.begin(), numbers.end());
        auto minIt = std::min_element(numbers.begin(), numbers.end());

        std::cout << "Largest element: " << *maxIt << std::endl;
        std::cout << "Smallest element: " << *minIt << std::endl;
    }
    else {
        std::cout << "Vector is empty.\n";
    }

    return 0;
}
