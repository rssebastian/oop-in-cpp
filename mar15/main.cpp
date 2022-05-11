#include "MyVector.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    MyVector test1;
    MyVector test2(5);
    MyVector test3(2, 3);
    MyVector mainTest;

    test1.printContents();
    test2.printContents();
    test3.printContents();
    cout << "------------------" << endl;
    cout << "Testing pushBack()..." << endl;
    for (int i = 0; i < mainTest.getSize(); i++)
    {
        mainTest.pushBack(10 * i);
    }
    mainTest.printContents();
    mainTest.pushBack(100);
    mainTest.printContents();
    cout << "------------------" << endl;
    cout << "Testing popBack()..." << endl;
    mainTest.popBack();
    mainTest.popBack();
    mainTest.popBack();
    mainTest.popBack();
    mainTest.popBack();
    mainTest.printContents();
    cout << "------------------" << endl;
    cout << "Testing insert()..." << endl;
    mainTest.insert(5, 1);
    mainTest.insert(55, 10);
    mainTest.printContents();
    cout << "------------------" << endl;
    cout << "Testing remove()..." << endl;
    mainTest.remove(1);
    mainTest.remove(6);
    mainTest.printContents();
    cout << "------------------" << endl;
    cout << "Testing at()..." << endl;
    cout << mainTest.at(2) << endl;
    cout << mainTest.at(100) << endl;
    return 0;
}
// TEST CASE OUTPUT:
// Testing pushBack()...
// 0 1 2 3 4 5 6 7 8 9
// Testing insert()...
// -1 0 1 2 3 4 5 6 7 8 9 11
// Testing remove()...
// 0 1 2 3 4 5 6 7 8 9
// Testing at()...
// Value at index 0 is: 0
// 100 1 2 3 4 5 6 7 8 9
// Testing Copy Constructor...
// 100 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// Testing Operator Overloads...
// Value at index 0 list is: 100
// Value at index 0 list is now: 0
// Value at index 0 list2 is: 0
// Value at index 0 list2 is: -1
// List destroyed
// List destroyed

// 3 3
// ------------------
// Testing pushBack()...
// 0 10 20 30 40 50 60 70 80 90
// grow() ran!
// 0 10 20 30 40 50 60 70 80 90 100
// ------------------
// Testing popBack()...
// shrink() ran!
// 0 10 20 30 40 50
// ------------------
// Testing insert()...
// grow() ran!
// 0 5 10 20 30 40 50 55
// ------------------
// Testing remove()...
// 0 10 20 30 40 50
// ------------------
// Testing at()...
// 0x13458701b48
// Index is not in this array