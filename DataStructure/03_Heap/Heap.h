#pragma once
#define HEAP_SIZE 20

// Change 1 to 0 for min heap
#define IS_MAX_HEAP 1

class Heap
{
	int heap[HEAP_SIZE + 1];
	int lastIndex;

	void AdjustFromBot();
	void AdjustFromTop();

public:
	inline bool IsFull();
	inline bool IsEmpty();
	void Push(const int item);
	int Pop();
	int GetHeight();
	void Print();

	Heap();
};

