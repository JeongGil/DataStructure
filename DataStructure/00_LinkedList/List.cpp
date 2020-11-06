#include "List.h"

List::Node::Node() :prev(nullptr), next(nullptr), data(0)
{
}

List::Node::Node(int value) : prev(nullptr), next(nullptr), data(value)
{
}

int List::Front()
{
	return head->next->data;
}

int List::Back()
{
	return tail->prev->data;
}

void List::PushFront(const int newValue)
{
	Node* newNode = new Node(newValue);

	// Connect head->next to new node.
	newNode->next = head->next;
	head->next->prev = newNode;

	// Connect head to new node.
	head->next = newNode;
	newNode->prev = head;

	size++;
}

void List::PushBack(const int newValue)
{
	Node* newNode = new Node(newValue);

	// Connect tail->prev to new node.
	tail->prev->next = newNode;
	newNode->prev = tail->prev;

	// Connect tail to new node;
	newNode->next = tail;
	tail->prev = newNode;

	size++;
}

int List::PopFront()
{
	Node* front = head->next;
	int retValue = front->data;

	// Connect head to front->next.
	head->next = front->next;
	front->next->prev = head;

	delete front;

	size--;

	return retValue;
}

int List::PopBack()
{
	Node* back = tail->prev;
	int retValue = back->data;

	// Connect tail to back->prev.
	back->prev->next = tail;
	tail->prev = back->prev;

	delete back;

	size--;

	return retValue;
}

#if IS_LIST
bool List::IsValid(const int index)
{
	return index < size;
}

void List::Insert(const int index, const int newValue)
{
	if (!IsValid((index - 1)))	// It is possible to insert node at nth index even size is n - 1.
	{
		std::cout << "Invalid index." << std::endl;

		return;
	}

	// Insert new data after curNode.
	Node* curNode = head;
	for (int i = 0; i < index; i++)
	{
		curNode = curNode->next;
	}

	Node* newNode = new Node(newValue);

	// Connect curNode->next to newNode.
	curNode->next->prev = newNode;
	newNode->next = curNode->next;

	// Connect curNode to newNode.
	curNode->next = newNode;
	newNode->prev = curNode;

	size++;
}

void List::Remove(const int index)
{
	if (!IsValid((index)))
	{
		std::cout << "Invalid index." << std::endl;

		return;
	}

	Node* targetNode = head;
	for (int i = 0; i < index; i++)
	{
		targetNode = targetNode->next;
	}

	// Connect targetNode->prev to targetNode->next.
	targetNode->prev->next = targetNode->next;
	targetNode->next->prev = targetNode->prev;

	delete targetNode;

	size--;
}
#endif

int List::Size()
{
	return size;
}

void List::Print()
{

	std::cout << "***" << std::endl;

	Node* curNode = head->next;
	if (size != 0)
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << curNode->data << std::endl;
			curNode = curNode->next;
		}
	}
	else
	{
		std::cout << "It is empty." << std::endl;
	}

	std::cout << "***" << std::endl;
}

List::List() : head(new Node()), tail(new Node()), size(0)
{
	head->next = tail;
	tail->prev = head;
}

List::~List()
{
}
