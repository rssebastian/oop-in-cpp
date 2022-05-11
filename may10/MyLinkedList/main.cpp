#include "MyLinkedList.h"

int main()
{
    MyLinkedList list;
    std::cout << "Testing pushBack()..." << std::endl;
    for (int i = 0; i < 10; i++)
    {
        list.pushBack(i);
    }
    std::cout << list << std::endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     list.popBack();
    // }
    std::cout << "Testing insert()..." << std::endl;
    list.insert(11, 10);
    list.insert(-1, 0);
    std::cout << list << std::endl;
    std::cout << "Testing remove()..." << std::endl;
    list.remove(0);
    list.remove(10);
    std::cout << list << std::endl;
    std::cout << "Testing at()..." << std::endl;
    std::cout << "Value at index 0 is: " << list.at(0) << std::endl;
    list.at(0) = 100;
    std::cout << list << std::endl;
    std::cout << "Testing Copy Constructor..." << std::endl;
    MyLinkedList list2 = list;
    list2.at(0) = 0;
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;
    std::cout << "Testing Operator Overloads..." << std::endl;
    std::cout << "Value at index 0 list is: " << list[0] << std::endl;
    list[0] = 0;
    std::cout << "Value at index 0 list is now: " << list[0] << std::endl;
    std::cout << "Value at index 0 list2 is: " << list2[0] << std::endl;
    list2[0] = -1;
    std::cout << "Value at index 0 list2 is: " << list2[0] << std::endl;
}
