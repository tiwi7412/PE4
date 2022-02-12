#include <iostream>

void PlaceMarker(const int col, const int row, char**brd, const char* marker)
{
    brd[row][col] = *marker; //Updates the location requested to the players marker
}

void displayBoard(char** brd)
{
    //Used three loops because i wanted there to be a space between everything in the row, then 
    //a line break, then the next row
     for (int x = 0; x < 3;x++)
    {
        std::cout << brd[0][x] << " "; //Displays the top row of the board
    }
    std::cout << std::endl;
    for (int j = 0; j < 3; j++)
    {
        std::cout << brd[1][j] << " "; //Displays the middle row of the board
    }
    std::cout << std::endl;
    for (int k = 0; k < 3; k++)
    {
        std::cout << brd[2][k] << " "; //Displays the bottom row of the board
    }
    std::cout << std::endl;
    std::cout << "======" << std::endl << "======" << std::endl;
}

char** CreateBoard()
{
    char **board=new char*[3]; //creates an array on the heap that is not local to the function
    //is able to be returned like this
    for (int i=0; i<3; i++)
    {
       board[i] = new char[3]; //creates another array to be stored in the first and make it two dimensional
       for (int j=0; j<3; j++)
         board[i][j]='N'; // Sets everything to N to indicate nothing is played on that square
    }

    return board;
}
int* GetPlayerChoice()
{
    int col,row = 0;
    std::cout << "What column would you like to play in?" << std::endl; 
    std::cin >> col; //Gets player column info
    std::cout << "What Row would you like to play in?" << std::endl;
    std::cin >> row; // Gets player row info
    int *arr = new int[2]; //creates an array
    arr[0] = row;
    arr[1] = col; //stores the inputted info in the array to be returned
    return arr;
}
int main()
{
    int player = 0;
    const char *x = "X"; // Creates the player markers, x and o
    const char *o = "O";
    char** board = CreateBoard(); // Creates the board
    for(int i = 0; i < 9; i++)
    {
        if(player == 0)
        {
            //Player 1s turn asks for input and updates the board
            std::cout << "Player ones Turn" << std::endl;
            displayBoard(board);
            int *arr = GetPlayerChoice();
            PlaceMarker(arr[1],arr[0],board,x);
            player = 1;
        }
        else
        {
            //Player 2s turn asks for input and updates the board
            std::cout << "Player twos Turn" << std::endl;
            displayBoard(board);
            int *arr = GetPlayerChoice();
            PlaceMarker(arr[1],arr[0],board,o);
            player = 0;
        }
    }
    //Displays the final board after the game is over.
    displayBoard(board);
}
