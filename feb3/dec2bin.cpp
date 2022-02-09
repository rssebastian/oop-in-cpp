// Write a program that reads a  (positive) integer from cin and prints the
// binary representation of that integer.

// For example, if your program read the integer 7, it would print 111

// If your program read the integer 8, it would print 1000

// Note: Don't worry about negative numbers -- I won't use anything but
// positive integers when testing your programs.

// Note: The largest number I will test your program with is 2147483647

#include <iostream>
#include <string>
using namespace std;

// Function Prototype
string dec2bin(int);

int main()
{
    int number;
    cout << "Which positive integer do you want to convert to binary?: ";
    cin >> number;
    cout << dec2bin(number);
    return 0;
}

string dec2bin(int num)
{
    if (num == 1)
        return "1";
    else
        return dec2bin(num / 2) + std::to_string(num % 2);
}

// TEST CASE OUTPUT
// -----------------
// Which positive integer do you want to convert to binary?: 7
// 111
// -----------------
// Which positive integer do you want to convert to binary?: 8
// 1000
// -----------------
// Which positive integer do you want to convert to binary?: 2147483647
// 1111111111111111111111111111111
// -----------------