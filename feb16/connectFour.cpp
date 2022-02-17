// Name: Ryan Sebastian
// Course: CIS 25 - OOP in C++
// Description: Plays game of Connect Four on a 8 row, 6 column board

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Board settings
const int ROWS = 8;
const int COLUMNS = 6;
char board[ROWS][COLUMNS];

// Function Prototypes
void fillBoard();
void displayBoard();
bool gatherInputs(bool player1Turn);
void inputCheck(int *choice);
int rowCheck(int *col);
bool vertWin(bool player, int col);
bool horzWin(bool player, int row);
bool tieCheck();

int main()
{
    bool gameOver;
    bool player1Turn = true;
    fillBoard();

    while (!gameOver)
    {
        gameOver = gatherInputs(player1Turn) || tieCheck();
        if (!gameOver)
            player1Turn = !player1Turn;
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

// Prompts users for inputs while checking validity, returns true if move makes a winner
bool gatherInputs(bool player1Turn)
{
    bool validMove = false;
    bool winnerFound = false;
    int row;
    int col;
    string player = (player1Turn) ? "Player 1" : "Player 2";
    while (!validMove)
    {
        cout << player << ", please enter a column number (1-6):" << '\n';
        cin >> col;
        inputCheck(&col);
        row = rowCheck(&col);
        validMove = true;
    }
    board[row][col] = player1Turn ? 'x' : 'o';
    winnerFound = horzWin(player1Turn, row) || vertWin(player1Turn, col);
    if (winnerFound)
        return true;
    else
    {
        displayBoard();
        return false;
    }
}

// Validate that user's input fits the board's restrictions
void inputCheck(int *col)
{
    while (*col < 1 || *col > COLUMNS)
    {
        cout << "Please enter a valid column (1-6): \n";
        cin >> *col;
    }
    *col = *col - 1;
}

// Returns the row where the choice should be inserted, If no spot found, it re-prompts for different col
int rowCheck(int *col)
{
    bool rowFound;
    while (!rowFound)
    {
        for (int row = ROWS - 1; row > -1; row--)
        {
            if (board[row][*col] == '*')
            {
                return row;
            }
        }
        cout << "This column is full, please enter a different column (1-6): \n";
        cin >> *col;
        inputCheck(col);
    }
}

// Check for Vertical Win
bool vertWin(bool player, int col)
{
    char playerSymbol = player ? 'x' : 'o';
    int count = 0;
    for (int row = ROWS - 1; row > -1; row--)
    {
        if (board[row][col] == playerSymbol)
        {
            count++;
            if (count == 4)
            {
                string playerStr = player ? "Player 1" : "Player 2";
                cout << playerStr << " has won!" << '\n';
                displayBoard();
                return true;
            }
            continue;
        }
        else
        {
            count = 0;
            continue;
        }
    }
    return false;
}

// Check for Horizontal Win
bool horzWin(bool player, int row)
{
    char playerSymbol = player ? 'x' : 'o';
    int count = 0;
    for (int col = 0; col < COLUMNS; col++)
    {
        if (board[row][col] == playerSymbol)
        {
            count++;
            if (count == 4)
            {
                string playerStr = player ? "Player 1" : "Player 2";
                cout << playerStr << " has won!" << '\n';
                displayBoard();
                return true;
            }
            continue;
        }
        else
        {
            count = 0;
            continue;
        }
    }
    return false;
}

// Checks if there are any open spots left
bool tieCheck()
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (board[row][col] == '*')
            {
                return false;
            }
        }
    }
    cout << "The board is filled! It's a tie!" << '\n';
    return true;
}

// TEST CASE OUTPUT in testCases.txt