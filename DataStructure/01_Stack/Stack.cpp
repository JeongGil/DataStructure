#include <iostream>
#include "Stack.h"
#include <cstring>

bool Stack::IsEmpty()
{
	return top == 0;
}

bool Stack::IsFull()
{
	return top == size;
}

void Stack::Push(const int item)
{
	if (IsFull())
	{
		std::cout << "Stack is full." << std::endl;

		return;
	}

	stack[top] = item;
	top++;
}

int Stack::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Stack is empty." << std::endl;

		return -1;
	}

	top--;

	return stack[top];
}

int Stack::Count()
{
	return top;
}

int Stack::Capacity()
{
	return size;
}

void Stack::Resize(const int newSize)
{
	int* newStack = new int[newSize];

	size = size < newSize ? size : newSize;
	memcpy(newStack, stack, sizeof(stack[0]) * size);

	top = top < size ? top : size;

	delete[] stack;
	stack = newStack;
}

void Stack::Print()
{
	std::cout << "***" << std::endl;
	for (int i = top - 1; i >= 0; i--)
	{
		std::cout << stack[i] << std::endl;
	}

	std::cout << "***" << std::endl;
}

Stack::Stack() :stack(nullptr), top(0), size(0)
{
}

Stack::Stack(const int stackSize) : stack(new int[stackSize]), top(0), size((stackSize))
{
}

Stack::~Stack()
{
	delete[] stack;
}
