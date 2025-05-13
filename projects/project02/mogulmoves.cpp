#include "mogulmoves.h"
#include <cstdlib>
#include <ctime>

Game::Game(int boardSize) : size(boardSize), turnCount(0), status(ONGOING) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    resetBoard();
}

void Game::resetBoard() {
    board = std::vector<std::vector<char>>(size, std::vector<char>(size, EMPTY));
    turnCount = 0;
    status = ONGOING;

    // Place hazards in corners
    board[0][0] = board[0][size - 1] = board[size - 1][0] = board[size - 1][size - 1] = HAZARD;

    // Place player in center
    playerPos = { size / 2, size / 2 };
    board[playerPos.row][playerPos.col] = PLAYER;

    // Place bank and money
    bankPos = placeRandom(BANK);
    moneyPos = placeRandom(MONEY);

    // Place additional hazards
    int numHazards = (size * size) / 8;
    for (int i = 0; i < numHazards; ++i) {
        placeRandom(HAZARD);
    }
}

bool Game::isFree(int row, int col) {
    return board.at(row).at(col) == EMPTY;
}

Position Game::placeRandom(char symbol) {
    int row, col;
    do {
        row = (symbol == MONEY) ? 1 + (std::rand() % (size - 2)) : std::rand() % size;
        col = (symbol == MONEY) ? 1 + (std::rand() % (size - 2)) : std::rand() % size;
    } while (!isFree(row, col));

    board[row][col] = symbol;
    return { row, col };
}

bool Game::movePlayer(int dRow, int dCol) {
    if (status != ONGOING) return false;

    int newRow = playerPos.row + dRow;
    int newCol = playerPos.col + dCol;

    if (newRow < 0 || newRow >= size || newCol < 0 || newCol >= size)
        return false;

    char destination = board.at(newRow).at(newCol);

    if (destination == EMPTY) {
        updatePlayerPosition(newRow, newCol);
        return true;
    }
    else if (destination == BANK) {
        return false;
    }
    else if (destination == MONEY) {
        return pushMoney(newRow, newCol, dRow, dCol);
    }
    else if (destination == HAZARD) {
        status = PLAYER_LOSES;
        return true;
    }

    return false;
}

void Game::updatePlayerPosition(int newRow, int newCol) {
    board[playerPos.row][playerPos.col] = EMPTY;
    playerPos = { newRow, newCol };
    board[playerPos.row][playerPos.col] = PLAYER;
    ++turnCount;
}

bool Game::pushMoney(int newRow, int newCol, int dRow, int dCol) {
    int moneyNewRow = newRow + dRow;
    int moneyNewCol = newCol + dCol;

    if (moneyNewRow < 0 || moneyNewRow >= size || moneyNewCol < 0 || moneyNewCol >= size)
        return false;

    char moneyDest = board.at(moneyNewRow).at(moneyNewCol);  // Copy to preserve original value

    if (moneyDest == EMPTY || moneyDest == BANK) {
        board[moneyPos.row][moneyPos.col] = EMPTY;
        moneyPos = { moneyNewRow, moneyNewCol };
        board[moneyPos.row][moneyPos.col] = MONEY;

        updatePlayerPosition(newRow, newCol);

        if (moneyDest == BANK)
            status = PLAYER_WINS;

        return true;
    }
    else if (moneyDest == HAZARD) {
        status = PLAYER_LOSES;
        return true;
    }

    return false;
}

GameStatus Game::getStatus() const {
    return status;
}

int Game::getTurnCount() const {
    return turnCount;
}

std::ostream& operator<<(std::ostream& os, const Game& g) {
    os << "\n";
    for (const auto& row : g.board) {
        for (char cell : row) {
            os << cell << " ";
        }
        os << "\n";
    }
    return os;
}
