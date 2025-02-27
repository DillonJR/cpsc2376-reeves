#include <iostream>
#include <vector>

std::vector<std::vector<int>> makeBoard(int size=9)
{
    std::vector<std::vector<int>> board(size, std::vector<int>(size));
        return board;
}

void printBoard(std::vector<std::vector<int>> board)
{

    int size = board.size();
    for (auto row : board)
    {
        for (auto elem : row)
        {
            std::cout << elem;
        }
        std::cout << "\n";
    }
}

void play(std::vector<std::vector<int>>& board, int row, int col, int token)
{
    board.at(row).at(col) = token;
}


int main()
{
    auto board{ makeBoard() };
    play(board, 4, 4, 1);
    printBoard(board);

}
