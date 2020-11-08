#include <iostream>
#include "Heap.h"

void main()
{
	Heap heap;
	for (int i = 1; i <= HEAP_SIZE; i++)
	{
		heap.Push(i);
	}

	heap.Print();
	std::cout << "Height of tree: " << heap.GetHeight() << std::endl;

	heap.Push(21);
	heap.Print();

	std::cout << "Pop: " << heap.Pop() << std::endl;
	heap.Print();

	for (int i = 1; i < HEAP_SIZE; i++)
	{
		heap.Pop();
	}
	heap.Print();

	heap.Pop();
}