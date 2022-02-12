#include <iostream>

void PlaceMarker(const int col, const int row, char**brd, const char* marker)
{
    brd[row][col] = *marker;
}

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
    std::cout << "======" << std::endl << "======" << std::endl;
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
int* GetPlayerChoice()
{
    int col,row = 0;
    std::cout << "What column would you like to play in?" << std::endl;
    std::cin >> col;
    std::cout << "What Row would you like to play in?" << std::endl;
    std::cin >> row;
    int *arr = new int[2];
    arr[0] = row;
    arr[1] = col;
    return arr;
}
int main()
{
    int player = 0;
    const char *x = "X";
    const char *o = "O";
    char** board = CreateBoard();
    for(int i = 0; i < 9; i++)
    {
        if(player == 0)
        {
            std::cout << "Player ones Turn" << std::endl;
            displayBoard(board);
            int *arr = GetPlayerChoice();
            PlaceMarker(arr[1],arr[0],board,x);
            player = 1;
        }
        else
        {
            std::cout << "Player twos Turn" << std::endl;
            displayBoard(board);
            int *arr = GetPlayerChoice();
            PlaceMarker(arr[1],arr[0],board,o);
            player = 0;
        }
    }
    displayBoard(board);
}