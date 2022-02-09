// Write a program that asks the user for a line of text and returns the
// number of times the characters 'u', 'w', and 'u' appear in that line of
// text, in that order.

// (for the rest of this prompt, I will refer to this set of characters in
// this order as an "uwu")

// Your uwu detector should be *case-insensitive*. uwu is one uwu, but so
// is UwU, uWu, UWu, and so forth.

// Note that the characters in an uwu don't have to appear consecutively.
// For example, the following strings both contain exactly one uwu:
// uwuxx
// uxwxu

// The following string contains *four* uwus:

// uuwuu

// (how does this contain four uwus? one uwu is the one that uses the first 'u'
// and the third 'u'. another uses the first 'u' and the fourth 'u'. Another uses
// the second 'u' and the third 'u'. Finally, the fourth uwu uses the second 'u'
// and the fourth 'u'.

// This string contains eight uwus:

// uuwXwuu

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function Prototype
int uwuCounter(string str);

int main()
{
    string text;
    cout << "Enter a line of text:\n";
    cin >> text;
    cout << "Number of uwus in this line: " << uwuCounter(text);
}

int uwuCounter(string str)
{
    // Convert string to all lowercase
    std::for_each(str.begin(), str.end(), [](char &c)
                  { c = ::tolower(c); });

    // Counter to keep track of uwus
    int uwuCount = 0;

    // Check each index for the correct chars in the correct order
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'u')
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[j] == 'w')
                {
                    for (int k = j + 1; k < str.length(); k++)
                    {
                        if (str[k] == 'u')
                        {
                            uwuCount++;
                        }
                    }
                }
            }
        }
    }
    return uwuCount;
}

// TEST CASE OUTPUT
// --------------------------------
// Enter a line of text:
// uuwu
// Number of uwus in this line: 2
// --------CASE SENSITIVITY--------
// Enter a line of text:
// UwU
// Number of uwus in this line: 1
// Enter a line of text:
// uWu
// Number of uwus in this line: 1
// Enter a line of text:
// UWu
// Number of uwus in this line: 1
// --------NON-CONSECUTIVE--------
// Enter a line of text:
// uwuxx
// Number of uwus in this line: 1
// Enter a line of text:
// uxwxu
// Number of uwus in this line: 1
// Enter a line of text:
// uuwuu
// Number of uwus in this line: 4
// Enter a line of text:
// uuwXwuu
// Number of uwus in this line: 8