#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVector
{
private:
    // Instance Variables
    int size;
    int length;
    int *vector;

    // Private Methods
    void grow();
    void shrink();

public:
    // Constructors / Destructor
    MyVector();
    MyVector(int size);
    MyVector(int size, int initial);
    ~MyVector();

    // Public Methods
    void pushBack(int n);
    int popBack();
    void insert(int n, int index);
    void remove(int index);
    int *at(int index);

    // Helper Methods/Variables
    void printContents();
    int getSize();
    int getLength();
};
#endif