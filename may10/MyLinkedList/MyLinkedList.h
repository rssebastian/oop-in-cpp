#pragma once
#include <iostream>
struct Node
{
    int data;
    Node *next;
};

class MyLinkedList
{
private:
    // Instance Variables
    int length;
    Node *head;
    Node *tail;

public:
    // Constructors / Destructor
    MyLinkedList();
    MyLinkedList(const MyLinkedList &other);
    ~MyLinkedList()
    {
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;
            head = next;
        };
        std::cout << "List destroyed" << std::endl;
    }

    // Public Methods
    void pushBack(int n);
    int popBack();
    void insert(int n, int index);
    void remove(int index);
    int &at(int index);

    // Operator Overloads
    int &operator[](int index);
    friend std::ostream &operator<<(std::ostream &os, const MyLinkedList &list);
};
