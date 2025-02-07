#include <iostream>
#include <vector>
#include <limits>

void printVector(const std::vector<int>& nums) {
    std::cout << "Vector elements: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void doubleVector(std::vector<int>& nums) {
    for (int& num : nums) {
        num *= 2;
    }
    std::cout << "All elements have been doubled.\n";
}

int calcSum(const std::vector<int>& nums) {
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return sum;
}

void printMultiples(const std::vector<int>& nums, int multiple) {
    std::cout << "Multiples of " << multiple << ": ";
    for (int num : nums) {
        if (num % multiple == 0) {
            std::cout << num << " ";
        }
    }
    std::cout << "\n";
}

void addToVector(std::vector<int>& nums, int value) {
    nums.push_back(value);
    std::cout << value << " added to the vector.\n";
}

int getValidInteger() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    std::vector<int> nums;
    int choice, value;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of all numbers\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";

        choice = getValidInteger();

        if (choice == 1) {
            std::cout << "Enter a number to add: ";
            value = getValidInteger();
            addToVector(nums, value);
        }
        else if (choice == 2) {
            printVector(nums);
        }
        else if (choice == 3) {
            doubleVector(nums);
        }
        else if (choice == 4) {
            std::cout << "Sum of all numbers: " << calcSum(nums) << "\n";
        }
        else if (choice == 5) {
            std::cout << "Enter a number to find multiples: ";
            value = getValidInteger();
            printMultiples(nums, value);
        }
        else if (choice == 6) {
            std::cout << "Exiting the program.\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
