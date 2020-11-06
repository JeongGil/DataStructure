#pragma once
class Queue
{
	int* queue;
	int front;
	int rear;
	int size;

public:
	inline bool IsFull();
	inline bool IsEmpty();
	void Push(const int item);
	int Pop();
	inline int Count();
	inline int Capacity();
	void Print();
	
	Queue(const int queueSize);
	~Queue();
};

