#include "Tree.h"
#include <iostream>

using namespace std;

Node::Node() :item(0), left(nullptr), right(nullptr)
{
}

Node::Node(int newItem) : item(newItem), left(nullptr), right(nullptr)
{
}

Node::Node(Node& srcNode) : item(srcNode.item), left(srcNode.left), right(srcNode.right)
{
}

void Tree::PreorderTraverse(Node* root)
{
	if (root)
	{
		cout << root->GetItem() << " " << endl;
		PreorderTraverse(root->GetLeftChild());
		PreorderTraverse(root->GetRightChild());
	}
}

void Tree::InorderTraverse(Node* root)
{
	if (root)
	{
		PreorderTraverse(root->GetLeftChild());
		cout << root->GetItem() << " " << endl;
		PreorderTraverse(root->GetRightChild());
	}
}

void Tree::PostorderTraverse(Node* root)
{
	if (root)
	{
		PreorderTraverse(root->GetLeftChild());
		PreorderTraverse(root->GetRightChild());
		cout << root->GetItem() << " " << endl;
	}
}

Node* Tree::Search(Node* root, Item item)
{
	if (!root || root->GetItem() == item)
	{
		return root;
	}

	if (item < root->GetItem())
	{
		return Search(root->GetLeftChild(), item);
	}
	else
	{
		return Search(root->GetRightChild(), item);
	}
}

Node* Tree::Search_NonRecursive(Node* root, Item item)
{
	Node* curNode = root;
	while (curNode && item != curNode->GetItem())
	{
		if (item < curNode->GetItem())
		{
			curNode = curNode->GetLeftChild();
		}
		else
		{
			curNode = curNode->GetRightChild();
		}
	}

	return curNode;
}

Node* Tree::Min(Node* root)
{
	Node* curNode = root;
	while (curNode->GetLeftChild())
	{
		curNode = curNode->GetLeftChild();
	}

	return curNode;
}

Node* Tree::Max(Node* root)
{
	Node* curNode = root;
	while (curNode->GetRightChild())
	{
		curNode = curNode->GetRightChild();
	}

	return curNode;
}

Node* Tree::Successor(Node* node)
{
	if (node->GetRightChild())
	{
		return Min(node->GetRightChild());
	}

	Node* curNode = node;
	Node* curParent = curNode->GetParent();
	while (curParent && curNode == curParent->GetRightChild())	// if curNode's left is node,  curNode is successor.
	{
		curNode = curParent;
		curParent = curParent->GetParent();
	}

	return curParent;
}

Node* Tree::Predecessor(Node* node)
{
	if (node->GetLeftChild())
	{
		return Max(node->GetLeftChild());
	}

	Node* curNode = node;
	Node* curParent = curNode->GetParent();
	while (curParent && curNode == curParent->GetLeftChild())	// if curNode's right is node,  curNode is successor.
	{
		curNode = curParent;
		curParent = curParent->GetParent();
	}

	return curParent;
}

Node* Tree::Insert(Tree* tree, Item item)
{
	Node* newNode = new Node(item);
	Insert(tree, newNode);
}

Node* Tree::Insert(Tree* tree, Node* newNode)
{
	Node* curParent(nullptr);
	Node* curNode = tree->GetRoot();
	while (curNode)	// Find insert position
	{
		curParent = curNode;
		if (newNode->GetItem() < curNode->GetItem())
		{
			curNode = curNode->GetLeftChild();
		}
		else
		{
			curNode = curNode->GetRightChild();
		}
	}

	newNode->SetParent(curParent);
	if (!curParent)	// tree is empty
	{
		tree->SetRoot(newNode);
	}
	else if (curNode->GetItem() < curParent->GetItem())
	{
		curParent->SetLeftChild(curNode);
	}
	else
	{
		curParent->SetRightChild(curNode);
	}
}

Tree::Tree() : root(nullptr)
{
}
