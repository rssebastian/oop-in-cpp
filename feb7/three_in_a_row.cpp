// Write a function called three_in_a_row that takes an array of characters (a regular,
// one-dimensional array) as a parameter, and returns true if there are three or more x
// characters in a row in the array. Return false otherwise.
#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

bool three_in_a_row(char row[]);

int main()
{
    char test1[] = "-xXx-";
    char test2[] = "-x-x--xXx-";
    char test3[] = "-x-x----x-";
    char test4[] = "-x-x--x-xx--XXX";
    char test5[] = "-x-x--x-xx--XX-";

    cout << three_in_a_row(test1) << endl;
    cout << three_in_a_row(test2) << endl;
    cout << three_in_a_row(test3) << endl;
    cout << three_in_a_row(test4) << endl;
    cout << three_in_a_row(test5) << endl;
    return 0;
}

bool three_in_a_row(char row[])
{
    int arrLength = strlen(row);
    for (int i = 0; i < arrLength - 2; i++)
    {
        if (tolower(row[i]) == 'x')
        {
            if (i + 1 < arrLength - 1 && tolower(row[i + 1]) == 'x')
            {
                if (i + 2 < arrLength && tolower(row[i + 2]) == 'x')
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// TEST CASE OUTPUT
// 1
// 1
// 0
// 1
// 0