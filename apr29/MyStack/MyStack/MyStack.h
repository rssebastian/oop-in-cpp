#pragma once
#include <iostream>
template <typename T>
struct listNode {
	T data;
	listNode<T>* next;
};

template <typename T>
class MyStack {

private:
	listNode<T>* head;
public:
	MyStack<T>() {
		this->head = nullptr;
	};
	MyStack<T>(const MyStack<T> &stack) {
		this->head = stack.head;
	}
	void push(T item) {
		listNode<T>* oldHead = this->head;
		this->head = new listNode<T>;
		this->head->data = item;
		this->head->next = oldHead;
	};
	T pop() {
		listNode<T>* oldHead = this->head;
		this->head = this->head->next;
		return oldHead->data;
	};
	T peek() {
		return this->head->data;
	};
	void printList() {
		if (this->head == nullptr) {
			std::cout << "Empty List" << std::endl;
		};
		listNode<T>* current = this->head;
		while (current != nullptr) {
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << " null " << std::endl;
	}
	listNode<T>* deleteList() {
		if (this->head == nullptr) return this->head;
		listNode<T>* current = this->head;
		while (current != nullptr) {
			std::cout << "Deleting " << current->data << std::endl;
			listNode<T>* temp = current->next;
			delete current;
			current = temp;
		}
		return head;
	}
};
