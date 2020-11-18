#pragma once
#include <sal.h>

using Item = int;

class Node
{
private:
	Item item;

	Node* left;
	Node* right;
	Node* parent;
	
public:
	Item GetItem() { return item; }
	void SetItem(Item newItem) { item = newItem; }

	Node* GetLeftChild() { return left; }
	Node* GetRightChild() { return right; }
	Node* GetParent() { return parent; }
	void SetLeftChild(Node* node) { left = node; }
	void SetRightChild(Node* node) { right = node; }
	void SetParent(Node* node) { parent = node; }

	Node();
	Node(int newItem);
	Node(Node& srcNode);
};

class Tree
{
private:
	Node* root;

public:
	// Get, Set
	Node* GetRoot() { return root; }
	void SetRoot(Node* node) { root = node; }
	
	// Traverse
	static void PreorderTraverse(_In_ Node* root);
	static void InorderTraverse(_In_ Node* root);
	static void PostorderTraverse(_In_ Node* root);

	// Search
	static Node* Search(_In_ Node* root, _In_ Item item);
	static Node* Search_NonRecursive(_In_ Node* root, _In_ Item item);
	static Node* Min(_In_ Node* root);
	static Node* Max(_In_ Node* root);

	// Get successor, predecessor
	static Node* Successor(_In_ Node* node);
	static Node* Predecessor(_In_ Node* node);
	
	// Insert, Remove
	static Node* Insert(Tree* tree, Item item);
	static Node* Insert(Tree* tree, Node* newNode);
	Tree();
};
