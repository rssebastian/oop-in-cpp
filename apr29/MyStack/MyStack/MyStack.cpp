/*#include "MyStack.h"
#include <iostream>

template <typename T>
void MyStack<T>::push(T item) {
	listNode<T>* oldHead = this->head;
	this->head = new listNode<T>;
	this->head->data = item;
	this->head->next = oldHead;
}


template <typename T>
T MyStack<T>::pop() {
	listNode<T>* oldHead = this->head;
	this->head = this->head->next;
	return oldHead->data;
}

template <typename T>
T MyStack<T>::peek() {
	return this->head->data;
}



template class MyStack<int>;
*/