#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>

const std::string BALANCE_FILE = "account_balance.txt";

double getBalance() {
    std::ifstream file(BALANCE_FILE);
    if (!file) {
        std::ofstream newFile(BALANCE_FILE);
        newFile << "100.00";
        newFile.close();
        return 100.00;
    }
    double balance;
    file >> balance;
    if (file.fail()) {
        std::cerr << "Error reading balance file." << std::endl;
        exit(1);
    }
    return balance;
}

void updateBalance(double balance) {
    std::ofstream file(BALANCE_FILE);
    if (!file) {
        std::cerr << "Error writing balance file." << std::endl;
        exit(1);
    }
    file << balance;
}

void checkBalance() {
    double balance = getBalance();
    std::cout << "Your current balance is: $" << balance << std::endl;
}

void depositMoney() {
    double balance = getBalance();
    double amount;
    std::cout << "Enter deposit amount: ";
    while (!(std::cin >> amount) || amount <= 0) {
        std::cout << "Error: Deposit amount must be a positive number. Try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    balance += amount;
    updateBalance(balance);
    std::cout << "Deposit successful. Your new balance is: $" << balance << std::endl;
}

void withdrawMoney() {
    double balance = getBalance();
    double amount;
    std::cout << "Enter withdrawal amount: ";
    while (!(std::cin >> amount) || amount <= 0 || amount > balance) {
        if (amount > balance) {
            std::cout << "Error: Insufficient funds. Your balance is $" << balance << ". Try again: ";
        }
        else {
            std::cout << "Error: Withdrawal amount must be a positive number. Try again: ";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    balance -= amount;
    updateBalance(balance);
    std::cout << "Withdrawal successful. Your new balance is: $" << balance << std::endl;
}

int main() {
    std::cout << "Welcome to Your Bank Account!" << std::endl;
    getBalance();

    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Check Balance" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (choice == 1) {
            checkBalance();
        }
        else if (choice == 2) {
            depositMoney();
        }
        else if (choice == 3) {
            withdrawMoney();
        }
        else if (choice == 4) {
            std::cout << "Thank you for using Your Bank Account. Goodbye!" << std::endl;
            return 0;
        }
        else {
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    }
}
