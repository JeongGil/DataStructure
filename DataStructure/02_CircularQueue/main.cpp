#include <iostream>
#include "Queue.h"

void main()
{
	Queue queue(5);

	queue.Push(1);
	queue.Push(2);
	queue.Push(3);
	queue.Push(4);
	queue.Push(5);
	queue.Push(6);
	queue.Print();

	std::cout << "Pop twice." << std::endl;
	queue.Pop();
	queue.Pop();
	queue.Print();

	std::cout << "Push 6-7." << std::endl;
	queue.Push(6);
	queue.Push(7);
	queue.Print();
}