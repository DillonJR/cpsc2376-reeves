#pragma once
#include <vector>
#include <iostream>

enum GameStatus {
    ONGOING,
    PLAYER_WINS,
    PLAYER_LOSES
};

enum Cell {
    EMPTY = '.',
    PLAYER = 'P',
    MONEY = '$',
    BANK = 'B',
    HAZARD = 'x'
};

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
    GameStatus status;

    bool isFree(int row, int col);
    Position placeRandom(char symbol);
    bool pushMoney(int newRow, int newCol, int dRow, int dCol);
    void updatePlayerPosition(int newRow, int newCol);

public:
    Game(int boardSize = 9);
    void resetBoard();
    bool movePlayer(int dRow, int dCol);
    GameStatus getStatus() const;
    int getTurnCount() const;
    friend std::ostream& operator<<(std::ostream& os, const Game& g);
};
