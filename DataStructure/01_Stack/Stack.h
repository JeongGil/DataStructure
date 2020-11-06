#pragma once
class Stack
{
	int* stack;
	int top;
	int size;

public:
	inline bool IsEmpty();
	inline bool IsFull();
	void Push(const int item);
	int Pop();
	void Resize(const int newSize);
	void Print();

	Stack();
	Stack(const int stackSize);
};

