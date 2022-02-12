#include <iostream>

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
void DisplayBoard(char** board)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << board[0][i] << " ";
    }
    std::cout << std::endl;
    for (int j = 0; j < 3; j++)
    {
        std::cout << board[1][j] << " ";
    }
    std::cout << std::endl;
    for (int k = 0; k < 3; k++)
    {
        std::cout << board[2][k] << " ";
    }
    std::cout << std::endl;
}
int main()
{
    char** board = CreateBoard();
    DisplayBoard(board);
}