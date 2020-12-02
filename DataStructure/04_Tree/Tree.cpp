#include "Tree.h"
#include <iostream>
#include <cmath>

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
	while (curNode && curNode->GetLeftChild())
	{
		curNode = curNode->GetLeftChild();
	}

	return curNode;
}

Node* Tree::Max(Node* root)
{
	Node* curNode = root;
	while (curNode && curNode->GetRightChild())
	{
		curNode = curNode->GetRightChild();
	}

	return curNode;
}

Node* Tree::Successor(Node* node)
{
	if (!node)
	{
		return nullptr;
	}

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
	if (!node)
	{
		return nullptr;
	}

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

void Tree::Insert(Tree* tree, Item item)
{
	Node* newNode = new Node(item);
	Insert(tree, newNode);
}

void Tree::Insert(Tree* tree, Node* newNode)
{
	if (!tree || !newNode)
	{
		return;
	}

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

void Tree::TransPlant(Tree* tree, Node* origin, Node* post)
{
	if (!tree || !origin)
	{
		return;
	}

	if (!origin->GetParent())	// origin node is root node
	{
		tree->SetRoot(post);
	}
	else if (origin == origin->GetParent()->GetLeftChild())	// origin node is left child
	{
		origin->GetParent()->SetLeftChild(post);
	}
	else	// right child
	{
		origin->GetParent()->SetRightChild(post);
	}

	if (post)
	{
		post->SetParent(origin->GetParent());
	}
}

void Tree::Delete(Tree* tree, Node* delNode)
{
	if (!tree || !delNode)
	{
		return;
	}

	if (!delNode->GetLeftChild())
	{
		TransPlant(tree, delNode, delNode->GetRightChild());
	}
	else if (!delNode->GetRightChild())
	{
		TransPlant(tree, delNode, delNode->GetLeftChild());
	}
	else
	{
		Node* temp = Min(delNode->GetRightChild());
		if (temp->GetParent() != delNode)
		{
			TransPlant(tree, temp, temp->GetRightChild());

			temp->SetRightChild(delNode->GetRightChild());
			temp->GetRightChild()->SetParent(temp);
		}

		TransPlant(tree, delNode, temp);
		temp->SetLeftChild(delNode->GetLeftChild());
		temp->GetLeftChild()->SetParent(temp);
	}

	delete delNode;
}

int Tree::GetHeight(Node* node)
{
	if (!node)
	{
		return 0;
	}

	return max(GetHeight(node->GetLeftChild()), GetHeight(node->GetRightChild())) + 1;
}

int Tree::GetBalanceFactor(Node* node)
{
	if (!node)
	{
		return 0;
	}

	return GetHeight(node->GetLeftChild()) - GetHeight(node->GetRightChild());
}

void Tree::RotateLL(Node* node)
{
	if (node)
	{
		if (node->GetLeftChild())
		{
			Node* temp = node->GetLeftChild()->GetRightChild();
			node->GetLeftChild()->SetRightChild(node);
			node->SetParent(node->GetLeftChild());

			if (temp)
			{
				node->SetLeftChild(temp);
			}
			else
			{
				node->SetLeftChild(nullptr);
			}
		}
	}
}

void Tree::RotateRR(Node* node)
{
	if (node)
	{
		if (node->GetRightChild())
		{
			Node* temp = node->GetRightChild()->GetLeftChild();
			node->GetRightChild()->SetLeftChild(node);
			node->SetParent(node->GetRightChild());

			if (temp)
			{
				node->SetRightChild(temp);
			}
			else
			{
				node->SetRightChild(nullptr);
			}
		}
	}
}

void Tree::RotateLR(Node* node)
{
	if (node)
	{
		if (node->GetLeftChild())
		{
			RotateRR(node->GetLeftChild());
			RotateLL(node);
		}
	}
}

void Tree::RotateRL(Node* node)
{
	if (node)
	{
		if (node->GetRightChild())
		{
			RotateLL(node->GetLeftChild());
			RotateRR(node);
		}
	}
}

void Tree::Rebalance(Node* node)
{
	if (node)
	{
		int balanceFactor = GetBalanceFactor(node);

		if (balanceFactor > balanceThreshold)
		{
			if (GetBalanceFactor(node->GetLeftChild()) > 0)
			{
				RotateLL(node);
			}
			else
			{
				RotateLR(node);
			}
		}

		if (balanceFactor < -balanceThreshold)
		{
			if (GetBalanceFactor(node->GetLeftChild()) < 0)
			{
				RotateRR(node);
			}
			else
			{
				RotateRL(node);
			}
		}
	}
}

Tree::Tree() : root(nullptr)
{
}
