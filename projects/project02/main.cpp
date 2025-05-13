#include "mogulmoves.h"
#include <iostream>
#include <limits>
#include <cctype>

void showInstructions() {
    std::cout << "\nInstructions:\n"
        << "1. Move using W (up), A (left), S (down), D (right).\n"
        << "2. Push '$' to 'B' to win.\n"
        << "3. Avoid 'x' - stepping on it or pushing money onto it ends the game.\n"
        << "4. Corners are always hazards.\n"
        << "5. '$' never spawns on edges.\n"
        << "6. Try to win in as few moves as possible!\n\n";
}

void playGame() {
    Game game;
    std::cout << game;

    while (game.getStatus() == ONGOING) {
        char move;
        std::cout << "Move (WASD): ";
        std::cin >> move;
        move = std::tolower(move);

        int dRow = 0, dCol = 0;
        if (move == 'w') dRow = -1;
        else if (move == 's') dRow = 1;
        else if (move == 'a') dCol = -1;
        else if (move == 'd') dCol = 1;
        else {
            std::cout << "Invalid input.\n";
            continue;
        }

        game.movePlayer(dRow, dCol);
        std::cout << game;

        if (game.getStatus() == PLAYER_WINS)
            std::cout << "You win in " << game.getTurnCount() << " moves!\n";
        else if (game.getStatus() == PLAYER_LOSES)
            std::cout << "You lost after " << game.getTurnCount() << " moves.\n";
    }
}

int main() {
    while (true) {
        std::cout << "\n=== Mogul Moves ===\n1. Play\n2. Instructions\n3. Exit\nChoose: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) playGame();
        else if (choice == 2) showInstructions();
        else if (choice == 3) break;
        else std::cout << "Invalid choice.\n";
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
