#include "MyVector.h"
#include <iostream>

using namespace std;

MyVector::MyVector()
{
    vector = new int[10];
    size = 10;
    length = 0;
}

MyVector::MyVector(int size)
{
    vector = new int[size];
    this->size = size;
    length = 0;
}

MyVector::MyVector(int size, int initial)
{
    int el = 0;
    vector = new int[size];
    while (el < size)
    {
        vector[el] = initial;
        el++;
    }
    this->size = size;
    length = size;
};

MyVector::~MyVector()
{
    delete[] vector;
    vector = nullptr;
    cout << "Destructor ran!" << endl;
}

void MyVector::grow()
{
    int newSize = 2 * size;
    int *temp = new int[newSize];
    for (int i = 0; i < length; i++)
    {
        temp[i] = vector[i];
    };
    delete[] vector;
    vector = temp;
    size = newSize;
    cout << "grow() ran!" << endl;
}

void MyVector::shrink()
{
    int newSize = size / 3;
    int *temp = new int[newSize];
    for (int i = 0; i < length; i++)
    {
        temp[i] = vector[i];
    };
    delete[] vector;
    vector = temp;
    size = newSize;
    cout << "shrink() ran!" << endl;
}

void MyVector::pushBack(int n)
{
    if (length == size)
        grow();
    vector[length] = n;
    length++;
}

int MyVector::popBack()
{
    int temp = vector[length];
    length--;
    if (size >= 3 * length)
    {
        shrink();
    }
    return temp;
}

void MyVector::insert(int n, int index)
{
    if (length == size)
        grow();
    if (index >= length)
    {
        pushBack(n);
    }
    else
    {
        for (int i = length; i > index; i--)
        {
            vector[i] = vector[i - 1];
        }
        vector[index] = n;
        length++;
    }
}

void MyVector::remove(int index)
{
    for (int i = index; i < length; i++)
    {
        vector[i] = vector[i + 1];
    }
    length--;
    if (size >= 3 * length)
    {
        shrink();
    }
}

int MyVector::at(int index)
{
    if (index >= length)
    {
        cout << "Index is not in this array";
        exit(0);
    }
    else
    {
        return vector[index];
    }
}

void MyVector::printContents()
{
    int el = 0;
    while (el < length)
    {
        cout << vector[el] << " ";
        el++;
    }
    cout << endl;
}

int MyVector::getLength()
{
    return length;
}

int MyVector::getSize()
{
    return size;
}