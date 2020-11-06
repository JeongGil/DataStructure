#include "Queue.h"
#include <iostream>
#include <cstring>
#define ARRAY_SIZE (size + 1)

bool Queue::IsFull()
{
	return ((rear + 1) % ARRAY_SIZE) == front;
}

bool Queue::IsEmpty()
{
	return front == rear;
}

void Queue::Push(const int item)
{
	if (IsFull())
	{
		std::cout << "Queue is full." << std::endl;

		return;
	}

	queue[rear] = item;

	rear = (rear + 1) % ARRAY_SIZE;
}

int Queue::Pop()
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty." << std::endl;

		return -1;
	}

	int retVal = queue[front];
	queue[front] = 0;
	front = (front + 1) % ARRAY_SIZE;

	return retVal;
}

int Queue::Count()
{
	return ((rear - front) % ARRAY_SIZE);	// There is empty index in queue to check full.
}

int Queue::Capacity()
{
	return size;
}

void Queue::Print()
{
	std::cout << "***" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << queue[i] << std::endl;
	}

	std::cout << "***" << std::endl;
}

Queue::Queue(const int queueSize) :queue(new int(queueSize + 1)), front(0), rear(0), size(queueSize)
{
	memset(queue, 0, sizeof(queue[0]) * (queueSize + 1));
}

Queue::~Queue()
{
	if (queue)
	{
		delete[] queue;
	}
}
