#pragma once
#include <iostream>
// If it is dequeue, change value of IS_LIST to 0.
#define IS_LIST 1

class List
{
private:
	class Node
	{
	public:
		int item;

		Node* prev;
		Node* next;

		Node();
		Node(const int item);
	};

	Node* head;
	Node* tail;
	int size;

public:
	inline int Front();
	inline int Back();
	void PushFront(const int item);
	void PushBack(const int item);
	int PopFront();
	int PopBack();
#if IS_LIST == 1
	inline bool IsValid(const int index);
	void Insert(const int index, const int item);
	void Remove(const int index);
#endif
	inline int Size();
	void Print();

	List();
	~List();
};
