#include "List.h"

List::Node::Node() :prev(nullptr), next(nullptr), item(0)
{
}

List::Node::Node(const int item) : prev(nullptr), next(nullptr), item(item)
{
}

int List::Front()
{
	return head->next->item;
}

int List::Back()
{
	return tail->prev->item;
}

void List::PushFront(const int item)
{
	Node* newNode = new Node(item);

	// Connect front->next to new node.
	newNode->next = head->next;
	head->next->prev = newNode;

	// Connect front to new node.
	head->next = newNode;
	newNode->prev = head;

	size++;
}

void List::PushBack(const int item)
{
	Node* newNode = new Node(item);

	// Connect rear->prev to new node.
	tail->prev->next = newNode;
	newNode->prev = tail->prev;

	// Connect rear to new node;
	newNode->next = tail;
	tail->prev = newNode;

	size++;
}

int List::PopFront()
{
	Node* front = head->next;
	int retValue = front->item;

	// Connect front to front->next.
	head->next = front->next;
	front->next->prev = head;

	delete front;

	size--;

	return retValue;
}

int List::PopBack()
{
	Node* back = tail->prev;
	int retValue = back->item;

	// Connect rear to back->prev.
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

void List::Insert(const int index, const int item)
{
	if (!IsValid((index - 1)))	// It is possible to insert node at nth lastIndex even top is n - 1.
	{
		std::cout << "Invalid lastIndex." << std::endl;

		return;
	}

	// Insert new item after curNode.
	Node* curNode = head;
	for (int i = 0; i < index; i++)
	{
		curNode = curNode->next;
	}

	Node* newNode = new Node(item);

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
		std::cout << "Invalid lastIndex." << std::endl;

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
			std::cout << curNode->item << std::endl;
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
