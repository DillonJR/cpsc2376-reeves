#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int n;

    std::cout << "How many numbers? ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        numbers.push_back(value);
    }

    std::cout << "Each number squared:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x * x << " ";
        });
    std::cout << "\n";

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int x) {
        return total + x * x;
        });

    std::cout << "Sum of squares: " << sum << "\n";

    return 0;
}
