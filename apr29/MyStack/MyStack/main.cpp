#include "MyStack.h"
#include <crtdbg.h>

int main() {
	MyStack<int> stack;
	for (int i = 0; i < 5; i++) stack.push(i);
	stack.printList();
	std::cout << "stack popped: " << stack.pop() << std::endl;
	std::cout << "stack peeked: " << stack.peek() << std::endl;
	MyStack<int> stackCopy = stack;

	stackCopy.printList();
	std::cout << "stackCopy popped: " << stackCopy.pop() << std::endl;
	std::cout << "stackCopy peeked: " << stackCopy.peek() << std::endl;
	stack.deleteList();
	stackCopy.deleteList();
	
	_CrtDumpMemoryLeaks();
	return 0;
}
/*
TEST CASE OUTPUT
4 -> 3 -> 2 -> 1 -> 0->null
stack popped : 4
stack peeked : 3
3 -> 2 -> 1 -> 0->null
stackCopy popped : 3
stackCopy peeked : 2
*/
