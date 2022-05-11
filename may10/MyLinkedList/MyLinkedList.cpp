#include "MyLinkedList.h"

MyLinkedList::MyLinkedList()
{
    length = 0;
    head = nullptr;
    tail = nullptr;
}

MyLinkedList::MyLinkedList(const MyLinkedList &other)
{
    Node *current = other.head;
    length = 0;
    while (current != nullptr)
    {
        pushBack(current->data);
        if (length == other.length)
        {
            tail = current;
        }
        current = current->next;
    }
}

void MyLinkedList::pushBack(int n)
{
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

int MyLinkedList::popBack()
{
    if (head == nullptr)
    {
        return -1;
    }
    else if (length == 1)
    {
        int temp = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        length--;
        return temp;
    }
    else
    {
        Node *current = head;
        while (current->next != tail)
            current = current->next;
        int temp = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        length--;
        return temp;
    }
}

void MyLinkedList::insert(int n, int index)
{
    if (index < 0 || index > length)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else if (index == 0)
    {
        Node *newNode = new Node;
        newNode->data = n;
        newNode->next = head;
        head = newNode;
        length++;
        if (length == 1)
            tail = newNode;
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
        Node *newNode = new Node;
        newNode->data = n;
        newNode->next = current->next;
        current->next = newNode;
        length++;
        if (newNode->next == nullptr)
            tail = newNode;
    }
}

void MyLinkedList::remove(int index)
{
    if (index < 0 || index > length)
    {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }
    else if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        length--;
        if (length == 0)
        {
            tail = nullptr;
        }
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
            current = current->next;
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
        if (current->next == nullptr)
            tail = current;
    }
}

int &MyLinkedList::at(int index)
{
    if (index < 0 || index > length)
    {
        std::cout << "Index out of bounds" << std::endl;
        exit(0);
    }
    else
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
            current = current->next;
        return current->data;
    }
}

int &MyLinkedList::operator[](int index)
{
    return at(index);
}

std::ostream &operator<<(std::ostream &os, const MyLinkedList &list)
{
    Node *current = list.head;
    if (current == nullptr)
    {
        os << "List is empty" << std::endl;
    }
    while (current != nullptr)
    {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}
