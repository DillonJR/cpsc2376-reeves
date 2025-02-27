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

struct Position
{
    int row, col;
};

class Game
{
private:
    std::vector<std::vector<char>> board;
    Position playerPos;
    Position moneyPos;
    Position bankPos;
    int size;
    int turnCount;

public:
    Game(int boardSize = 9) : size(boardSize), turnCount(0)
    {
        std::srand(std::time(nullptr));
        resetBoard();
    }

    void resetBoard()
    {
        board = std::vector<std::vector<char>>(size, std::vector<char>(size, EMPTY));
        turnCount = 0;

        board[0][0] = board[0][size - 1] = HAZARD;
        board[size - 1][0] = board[size - 1][size - 1] = HAZARD;

        playerPos = { size / 2, size / 2 };
        board[playerPos.row][playerPos.col] = PLAYER;

        bankPos = placeRandom(BANK);
        moneyPos = placeRandom(MONEY);

        int numHazards = (size * size) / 8;
        for (int i = 0; i < numHazards; i++)
        {
            placeRandom(HAZARD);
        }
    }

    bool isFree(int row, int col)
    {
        return board[row][col] == EMPTY;
    }

    Position placeRandom(char symbol)
    {
        int row, col;
        if (symbol == MONEY)
        {
            do
            {
                row = 1 + (std::rand() % (size - 2));
                col = 1 + (std::rand() % (size - 2));
            } while (!isFree(row, col));
        }
        else
        {
            do
            {
                row = std::rand() % size;
                col = std::rand() % size;
            } while (!isFree(row, col));
        }

        board[row][col] = symbol;
        return { row, col };
    }

    void printBoard()
    {
        std::cout << "\n";
        for (const auto& row : board)
        {
            for (char cell : row)
            {
                std::cout << cell << " ";
            }
            std::cout << "\n";
        }
    }

    bool movePlayer(int dRow, int dCol)
    {
        int newRow = playerPos.row + dRow;
        int newCol = playerPos.col + dCol;

        if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size)
        {
            std::cout << "You can't move outside the board!\n";
            return false;
        }

        char destination = board[newRow][newCol];

        if (destination == EMPTY)
        {
            turnCount++;
            board[playerPos.row][playerPos.col] = EMPTY;
            playerPos = { newRow, newCol };
            board[playerPos.row][playerPos.col] = PLAYER;
            return true;
        }
        else if (destination == BANK)
        {
            std::cout << "You can't step on the bank!\n";
            return false;
        }
        else if (destination == MONEY)
        {
            int moneyNewRow = newRow + dRow;
            int moneyNewCol = newCol + dCol;

            if (moneyNewRow < 0 || moneyNewRow >= size || moneyNewCol < 0 || moneyNewCol >= size)
            {
                std::cout << "You can't push the money outside the board!\n";
                return false;
            }

            char moneyDest = board[moneyNewRow][moneyNewCol];

            if (moneyDest == EMPTY || moneyDest == BANK)
            {
                turnCount++;
                board[moneyPos.row][moneyPos.col] = EMPTY;
                moneyPos = { moneyNewRow, moneyNewCol };
                board[moneyPos.row][moneyPos.col] = MONEY;

                board[playerPos.row][playerPos.col] = EMPTY;
                playerPos = { newRow, newCol };
                board[playerPos.row][playerPos.col] = PLAYER;

                if (moneyDest == BANK)
                {
                    printBoard();
                    std::cout << "Congratulations! You deposited the money in " << turnCount << " moves!\n";
                    return gameOver();
                }
                return true;
            }
            else if (moneyDest == HAZARD)
            {
                printBoard();
                std::cout << "You lost all your money after " << turnCount << " moves!\n";
                return gameOver();
            }
        }
        else if (destination == HAZARD)
        {
            printBoard();
            std::cout << "You lost all your money after " << turnCount << " moves!\n";
            return gameOver();
        }

        return false;
    }

    bool gameOver()
    {
        char choice;
        while (true)
        {
            std::cout << "\nPlay again? (Y/N): ";
            std::cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {
                resetBoard();
                printBoard();
                return true;
            }
            else if (choice == 'N' || choice == 'n')
            {
                std::cout << "Thank you for playing Mogul Moves!\n";
                exit(0);
            }
            else
            {
                std::cout << "Invalid input. Please enter Y or N.\n";
            }
        }
    }

    void play()
    {
        printBoard();
        while (true)
        {
            char move;
            bool validInput = false;

            while (!validInput)
            {
                std::cout << "Enter move (WASD): ";
                std::cin >> move;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                move = std::tolower(move);
                if (move == 'w' || move == 'a' || move == 's' || move == 'd')
                {
                    validInput = true;
                }
                else
                {
                    std::cout << "Invalid move! Use W, A, S, or D.\n";
                }
            }

            int dRow = 0, dCol = 0;
            if (move == 'w') dRow = -1;
            if (move == 's') dRow = 1;
            if (move == 'a') dCol = -1;
            if (move == 'd') dCol = 1;

            if (movePlayer(dRow, dCol))
            {
                printBoard();
            }
        }
    }
};

void showInstructions()
{
    std::cout << "\nInstructions:\n";
    std::cout << "1. Move using W (up), A (left), S (down), D (right).\n";
    std::cout << "2. Push '$' to 'B' to win.\n";
    std::cout << "3. Avoid 'x' - stepping on it or pushing money onto it ends the game.\n";
    std::cout << "4. Corners are always hazards.\n";
    std::cout << "5. '$' will never spawn on the edges.\n";
    std::cout << "6. Try to win in as few moves as possible!\n\n";
}

void showMenu()
{
    while (true)
    {
        std::cout << "\n===== Mogul Moves =====\n";
        std::cout << "\nMain Menu\n";
        std::cout << "1. Play\n";
        std::cout << "2. Instructions\n";
        std::cout << "3. Exit\n";
        std::cout << "Choose an option: ";

        int choice;

        if (!(std::cin >> choice))
        {
            std::cout << "Invalid input! Enter a number (1, 2, or 3).\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) Game().play();
        else if (choice == 2) showInstructions();
        else if (choice == 3)
        {
            std::cout << "Thank you for playing Mogul Moves!\n";
            exit(0);
        }
    }
}

int main()
{
    showMenu();
    return 0;
}
