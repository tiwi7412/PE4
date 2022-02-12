#include <iostream>

void displayBoard(char** brd)
{
     for (int x = 0; x < 3;x++)
    {
        std::cout << brd[0][x] << " ";
    }
    std::cout << std::endl;
    for (int j = 0; j < 3; j++)
    {
        std::cout << brd[1][j] << " ";
    }
    std::cout << std::endl;
    for (int k = 0; k < 3; k++)
    {
        std::cout << brd[2][k] << " ";
    }
    std::cout << std::endl;
}

char** CreateBoard()
{
    char **board=new char*[3];
    for (int i=0; i<3; i++)
    {
       board[i] = new char[3];
       for (int j=0; j<3; j++)
         board[i][j]='N';
    }

    return board;
}

int main()
{
    char** board = CreateBoard();
    DisplayBoard(board);
}