// Name: Ryan Sebastian
// Course: CIS 25 - OOP in C++
// Description: Plays game of 3x3 tic-tac-toe

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Board settings
const int ROWS = 3;
const int COLUMNS = 3;
char board[ROWS][COLUMNS];

// Function Prototypes
void fillBoard();
void displayBoard();
void gatherInputs(bool player1Turn);
void inputCheck(int *choice, const int *rowOrCol);
bool spaceCheck(int row, int col);
bool vertWin(bool player);
bool horzWin(bool player);
bool diagWin(bool player);
bool tieCheck();

int main()
{
    bool gameOver;
    bool player1Turn = true;
    fillBoard();

    while (!gameOver)
    {
        displayBoard();
        gatherInputs(player1Turn);
        gameOver = vertWin(player1Turn) || horzWin(player1Turn) || diagWin(player1Turn) || tieCheck();
        if (!gameOver)
            player1Turn = !player1Turn;
    }
    displayBoard();
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

// Prompts users for inputs while checking validity
void gatherInputs(bool player1Turn)
{
    bool validMove;
    int rowChoice;
    int colChoice;
    while (!validMove)
    {
        cout << "Enter a row between 1 and " << ROWS << '\n';
        cin >> rowChoice;
        inputCheck(&rowChoice, &ROWS);
        rowChoice--;
        cout << "Enter a column between 1 and " << COLUMNS << '\n';
        cin >> colChoice;
        inputCheck(&colChoice, &COLUMNS);
        colChoice--;
        validMove = spaceCheck(rowChoice, colChoice);
    }
    board[rowChoice][colChoice] = player1Turn ? 'X' : 'O';
}

// Validate that user's input fits the board's restrictions
void inputCheck(int *choice, const int *rowOrCol)
{
    if (rowOrCol == &ROWS)
    {
        while (*choice < 1 || *choice > ROWS)
        {
            cout << "Please enter a valid row: \n";
            cin >> *choice;
        }
    }
    else
    {
        while (*choice < 1 || *choice > COLUMNS)
        {
            cout << "Please enter a valid column: \n";
            cin >> *choice;
        }
    }
}

// Validate user is taking an open spot
bool spaceCheck(int row, int col)
{
    if (board[row][col] != '*')
    {
        cout << "This space is already taken, please choose a different space.\n";
        return false;
    }
    else
    {
        return true;
    }
}

// Check for Vertical Win
bool vertWin(bool player)
{
    char playerSymbol = player ? 'X' : 'O';
    for (int col = 0; col < COLUMNS; col++)
    {
        for (int row = 0; row < ROWS; row++)
        {
            if (board[row][col] != playerSymbol)
            {
                break;
            }
            if (row == ROWS - 1)
            {
                string playerStr = player ? "Player 1" : "Player 2";
                cout << playerStr << " wins!" << '\n';
                return true;
            }
        }
    }
    return false;
}

// Check for Horizontal Win
bool horzWin(bool player)
{
    char playerSymbol = player ? 'X' : 'O';
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLUMNS; col++)
        {
            if (board[row][col] != playerSymbol)
            {
                break;
            }
            if (col == COLUMNS - 1)
            {
                string playerStr = player ? "Player 1" : "Player 2";
                cout << playerStr << " wins!" << '\n';
                return true;
            }
        }
    }
    return false;
}

// Check for Diagonal Win
bool diagWin(bool player)
{
    char playerSymbol = player ? 'X' : 'O';

    // Checks top left to bottom right
    for (int i = 0; i < ROWS; i++)
    {
        if (!board[i][i] != playerSymbol)
        {
            break;
        }
        if (i == COLUMNS - 1)
        {
            string playerStr = player ? "Player 1" : "Player 2";
            cout << playerStr << " wins!" << '\n';
            return true;
        }
    }

    // Checks bottom left to top right
    int col = 0;
    for (int row = ROWS - 1; row > -1; row--)
    {
        if (board[row][col] == playerSymbol)
        {
            col++;
            if (col == COLUMNS)
            {
                string playerStr = player ? "Player 1" : "Player 2";
                cout << playerStr << " wins!" << '\n';
                return true;
            }
        }
        else
        {
            break;
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

// TEST CASE OUTPUT
// Game #1: Player 1 wins horizontally
// ---
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 1
// X--
// ---
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 2
// X--
// -O-
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 2
// XX-
// -O-
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 1
// XX-
// OO-
// ---
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 1
// XX-
// OO-
// X--
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 2
// XX-
// OO-
// XO-
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 3
// Player 1 wins!
// XXX
// OO-
// XO-
// Game #2: Player 2 wins vertically
// ---
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 1
// X--
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 2
// XO-
// ---
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 1
// XO-
// X--
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 2
// XO-
// XO-
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 3
// XOX
// XO-
// ---
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 2
// Player 2 wins!
// XOX
// XO-
// -O-
// Game #3: Player 1 Diagonal Win
// ---
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 1
// X--
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 2
// XO-
// ---
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 2
// XO-
// -X-
// ---
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 3
// XO-
// -X-
// --O
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 1
// XO-
// -X-
// X-O
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 1
// XO-
// OX-
// X-O
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 3
// Player 1 wins!
// XOX
// OX-
// X-O
// Game #4: Tie + Error Checking
// ---
// ---
// ---
// Enter a row between 1 and 3
// 0
// Please enter a valid row:
// 4
// Please enter a valid row:
// 1
// Enter a column between 1 and 3
// 0
// Please enter a valid column:
// 4
// Please enter a valid column:
// 1
// X--
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 2
// XO-
// ---
// ---
// Enter a row between 1 and 3
// 1
// Enter a column between 1 and 3
// 3
// XOX
// ---
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 1
// XOX
// O--
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 2
// XOX
// OX-
// ---
// Enter a row between 1 and 3
// 2
// Enter a column between 1 and 3
// 3
// XOX
// OXO
// ---
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 2
// XOX
// OXO
// -X-
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 1
// XOX
// OXO
// OX-
// Enter a row between 1 and 3
// 3
// Enter a column between 1 and 3
// 3
// The board is filled! It's a tie!
// XOX
// OXO
// OXX