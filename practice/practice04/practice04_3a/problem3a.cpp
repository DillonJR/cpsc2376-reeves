#include <iostream>
#include <list>
#include <string>

void addTask(std::list<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added!\n";
}

void removeTask(std::list<std::string>& tasks) {
    int taskNum;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNum;
    std::cin.ignore();

    if (taskNum < 1 || taskNum > tasks.size()) {
        std::cout << "Invalid task number.\n";
        return;
    }

    auto it = tasks.begin();
    std::advance(it, taskNum - 1);
    tasks.erase(it);
    std::cout << "Task removed!\n";
}

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to show.\n";
        return;
    }

    std::cout << "Tasks:\n";
    int taskNum = 1;
    for (const auto& task : tasks) {
        std::cout << taskNum++ << ". " << task << "\n";
    }
}

int main() {
    std::list<std::string> tasks;
    int choice;

    do {
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Show Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            removeTask(tasks);
        }
        else if (choice == 3) {
            showTasks(tasks);
        }
        else if (choice == 4) {
            std::cout << "Exiting...\n";
        }
        else {
            std::cout << "Invalid option. Please choose again.\n";
        }

    } while (choice != 4);

    return 0;
}
