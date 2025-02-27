#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <limits>   

const char EMPTY = '.';
const char PLAYER = 'P';
const char MONEY = '$';
const char BANK = 'B';
const char HAZARD = 'x';

struct Position {
    int row, col;
};

class Game {
private:
    std::vector<std::vector<char>> board;
    Position playerPos;
    Position moneyPos;
    Position bankPos;
    int size;
    int turnCount;

public:
    Game(int boardSize = 9) : size(boardSize), turnCount(0) {
        std::srand(std::time(nullptr));
        resetBoard();
    }

    void resetBoard() {
        board = std::vector<std::vector<char>>(size, std::vector<char>(size, EMPTY));
        turnCount = 0;

        board.at(0).at(0) = board.at(0).at(size - 1) = HAZARD;
        board.at(size - 1).at(0) = board.at(size - 1).at(size - 1) = HAZARD;

        playerPos = { size / 2, size / 2 };
        board.at(playerPos.row).at(playerPos.col) = PLAYER;

        bankPos = placeRandom(BANK);
        moneyPos = placeRandom(MONEY);

        int numHazards = (size * size) / 8;
        for (int i = 0; i < numHazards; i++) {
            placeRandom(HAZARD);
        }
    }

    bool isFree(int row, int col) {
        return board.at(row).at(col) == EMPTY;
    }

    Position placeRandom(char symbol) {
        int row, col;
        do {
            row = (symbol == MONEY) ? 1 + (std::rand() % (size - 2)) : std::rand() % size;
            col = (symbol == MONEY) ? 1 + (std::rand() % (size - 2)) : std::rand() % size;
        } while (!isFree(row, col));

        board.at(row).at(col) = symbol;
        return { row, col };
    }

    void printBoard() {
        std::cout << "\n";
        for (const auto& row : board) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }
    }

    bool movePlayer(int dRow, int dCol) {
        int newRow = playerPos.row + dRow;
        int newCol = playerPos.col + dCol;

        if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size) {
            std::cout << "You can't move outside the board!\n";
            return false;
        }

        char& destination = board.at(newRow).at(newCol);

        if (destination == EMPTY) {
            updatePlayerPosition(newRow, newCol);
            return true;
        }
        else if (destination == BANK) {
            std::cout << "You can't step on the bank!\n";
            return false;
        }
        else if (destination == MONEY) {
            return pushMoney(newRow, newCol, dRow, dCol);
        }
        else if (destination == HAZARD) {
            printBoard();
            std::cout << "You lost all your money after " << turnCount << " moves!\n";
            return gameOver();
        }

        return false;
    }

    void updatePlayerPosition(int newRow, int newCol) {
        board.at(playerPos.row).at(playerPos.col) = EMPTY;
        playerPos = { newRow, newCol };
        board.at(playerPos.row).at(playerPos.col) = PLAYER;
        turnCount++;
    }

    bool pushMoney(int newRow, int newCol, int dRow, int dCol) {
        int moneyNewRow = newRow + dRow;
        int moneyNewCol = newCol + dCol;

        if (moneyNewRow < 0 || moneyNewRow >= size || moneyNewCol < 0 || moneyNewCol >= size) {
            std::cout << "You can't push the money outside the board!\n";
            return false;
        }

        char& moneyDest = board.at(moneyNewRow).at(moneyNewCol);

        if (moneyDest == EMPTY) {
            board.at(moneyPos.row).at(moneyPos.col) = EMPTY;
            moneyPos = { moneyNewRow, moneyNewCol };
            board.at(moneyPos.row).at(moneyPos.col) = MONEY;

            updatePlayerPosition(newRow, newCol);
            return true;
        }
        else if (moneyDest == BANK) {
            board.at(moneyPos.row).at(moneyPos.col) = EMPTY;
            moneyPos = { moneyNewRow, moneyNewCol };
            board.at(moneyPos.row).at(moneyPos.col) = MONEY;

            printBoard();
            std::cout << "Congratulations! You deposited the money in " << turnCount << " moves!\n";
            return gameOver();
        }
        else if (moneyDest == HAZARD) {
            printBoard();
            std::cout << "You lost all your money after " << turnCount << " moves!\n";
            return gameOver();
        }
        return false;
    }

    bool gameOver() {
        char choice;
        while (true) {
            std::cout << "\nPlay again? (Y/N): ";
            std::cin >> choice;

            if (choice == 'Y' || choice == 'y') {
                resetBoard();
                printBoard();
                return true;
            }
            else if (choice == 'N' || choice == 'n') {
                std::cout << "Thank you for playing Mogul Moves!\n";
                exit(0);
            }
            else {
                std::cout << "Invalid input. Please enter Y or N.\n";
            }
        }
    }

    void play() {
        printBoard();
        while (true) {
            char move;
            std::cout << "Enter move (WASD): ";
            std::cin >> move;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            move = std::tolower(move);
            if (move != 'w' && move != 'a' && move != 's' && move != 'd') {
                std::cout << "Invalid move! Use W, A, S, or D.\n";
                continue;
            }

            int dRow = (move == 'w') ? -1 : (move == 's') ? 1 : 0;
            int dCol = (move == 'a') ? -1 : (move == 'd') ? 1 : 0;

            if (movePlayer(dRow, dCol)) {
                printBoard();
            }
        }
    }
};

void showInstructions() {
    std::cout << "\nInstructions:\n"
        << "1. Move using W (up), A (left), S (down), D (right).\n"
        << "2. Push '$' to 'B' to win.\n"
        << "3. Avoid 'x' - stepping on it or pushing money onto it ends the game.\n"
        << "4. Corners are always hazards.\n"
        << "5. '$' will never spawn on the edges.\n"
        << "6. Try to win in as few moves as possible!\n\n";
}

void showMenu() {
    while (true) {
        std::cout << "\n===== Mogul Moves =====\n"
            << "1. Play\n"
            << "2. Instructions\n"
            << "3. Exit\n"
            << "Choose an option: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Enter a number (1, 2, or 3).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) Game().play();
        else if (choice == 2) showInstructions();
        else if (choice == 3) {
            std::cout << "Thank you for playing Mogul Moves!\n";
            exit(0);
        }
    }
}

int main() {
    showMenu();
    return 0;
}
