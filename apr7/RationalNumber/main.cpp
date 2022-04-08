#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
    cout << "----------------------" << endl;
    cout << "Testing Addition..." << endl;
    RationalNumber r1(2, 5);
    RationalNumber r2(1, 10);
    RationalNumber r3 = r1 + r2;
    RationalNumber r4 = 1 + r3;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r3 = r1 + r2 == " << r3 << endl;
    cout << "r4 = 1 + r3 == " << r4 << endl;

    cout << "----------------------" << endl;
    cout << "Testing Subtraction..." << endl;
    RationalNumber r5 = r1 - r2;
    RationalNumber r6 = 1 - r5;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r5 = r1 - r2 == " << r5 << endl;
    cout << "r6 = 1 - r5 == " << r6 << endl;

    cout << "----------------------" << endl;
    cout << "Testing Multiplication..." << endl;
    RationalNumber r7 = r1 * r2;
    RationalNumber r8 = 2 * r7;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r7 = r1 * r2 == " << r7 << endl;
    cout << "r8 = 2 * r7 == " << r8 << endl;

    cout << "----------------------" << endl;
    cout << "Testing Division..." << endl;
    RationalNumber r9 = r1 / r2;
    RationalNumber r10 = 1 / r9;
    cout << "r1 = " << r1 << endl;
    cout << "r2 = " << r2 << endl;
    cout << "r9 = r1 / r2 == " << r9 << endl;
    cout << "r10 == 1 / r9 == " << r10 << endl;
}

// TEST CASE OUTPUT
// ----------------------
// Testing Addition...
// r1 = 2/5
// r2 = 1/10
// r3 = r1 + r2 == 1/2
// r4 = 1 + r3 == 3/2
// ----------------------
// Testing Subtraction...
// r1 = 2/5
// r2 = 1/10
// r5 = r1 - r2 == 3/10
// r6 = 1 - r5 == 7/10
// ----------------------
// Testing Multiplication...
// r1 = 2/5
// r2 = 1/10
// r7 = r1 * r2 == 1/25
// r8 = 2 * r7 == 2/25
// ----------------------
// Testing Division...
// r1 = 2/5
// r2 = 1/10
// r9 = r1 / r2 == 4/1
// r10 == 1 / r9 == 1/4