#include <iostream>
#include "Stack.h"

void main()
{
	Stack stack(3);

	std::cout << "Push 1-2-3." << std::endl;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Print();

	std::cout << "Push 4." << std::endl;
	stack.Push(4);
	stack.Print();

	std::cout << "Pop." << std::endl;
	std::cout << "Top was: " << stack.Pop() << std::endl;
	stack.Print();

	std::cout << "Pop twice." << std::endl;
	stack.Pop();
	stack.Pop();
	stack.Print();

	std::cout << "Pop." << std::endl;
	stack.Pop();
}