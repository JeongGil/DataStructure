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
		int data;

		Node* prev;
		Node* next;

		Node();
		Node(int value);
	};

	Node* head;
	Node* tail;
	int size;

public:
	inline int Front();
	inline int Back();
	void PushFront(const int newValue);
	void PushBack(const int newValue);
	int PopFront();
	int PopBack();
#if IS_LIST == 1
	inline bool IsValid(const int index);
	void Insert(const int index, const int newValue);
	void ReMove(const int index);
#endif
	inline int Size();
	void Print();

	List();
	~List();
};
