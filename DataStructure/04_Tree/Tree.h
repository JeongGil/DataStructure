#pragma once
#include <sal.h>

using Item = int;
const int balanceThreshold(1);	// at least 1

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
	static void Insert(Tree* tree, Item item);
	static void Insert(Tree* tree, Node* newNode);

	// Change node origin to post
	static void TransPlant(Tree* tree, Node* origin, Node* post);

	static void Delete(Tree* tree, Node* delNode);

	// re-balance
	static int GetHeight(_In_ Node* node);
	static int GetBalanceFactor(_In_ Node* node);	// if return value is +, left high
	static void RotateLL(Node* node);
	static void RotateRR(Node* node);
	static void RotateLR(Node* node);
	static void RotateRL(Node* node);
	static void Rebalance(Node* node);
	
	Tree();
};
