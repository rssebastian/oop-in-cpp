// Name: Ryan Sebastian
// Course: CIS 25 - OOP in C++
// Description: Plays game of 3x3 tic-tac-toe

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Board dimensions
const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS];

// Function Prototypes
void fillBoard();
void displayBoard();
void inputCheck(int choice, const int *rowOrCol);
bool spaceTaken(int row, int col);

int main()
{
    bool gameOver;
    fillBoard();
    int rowChoice;
    int colChoice;
    while (!gameOver)
    {
        displayBoard();
        cout << "Enter a row between 0 and " << ROWS - 1 << '\n';
        cin >> rowChoice;
        inputCheck(rowChoice, &ROWS);
        cout << "Enter a column between 0 and " << COLUMNS - 1 << '\n';
        cin >> colChoice;
        inputCheck(colChoice, &COLUMNS);
        gameOver = true;
    }
}

// Initialize game
void fillBoard()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            board[row][col] = '*';
        }
    }
}

// Show current game state
void displayBoard()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (board[row][col] == '*')
            {
                cout << '-';
            }
            else
            {
                cout << board[row][col];
            }
            if (col == COLUMNS - 1)
            {
                cout << '\n';
            }
        }
    }
}

// Validate that user's input fits the board's restrictions
void inputCheck(int choice, const int *rowOrCol)
{
    if (rowOrCol == &ROWS)
    {
        while (choice < 0 || choice > ROWS - 1)
        {
            cout << "Please enter a valid row: \n";
            cin >> choice;
        }
    }
    else
    {
        while (choice < 0 || choice > COLUMNS - 1)
        {
            cout << "Please enter a valid column: \n";
            cin >> choice;
        }
    }
}

// Validate user is taking an open spot
bool spaceTaken(int row, int col);