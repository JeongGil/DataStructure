#include "Heap.h"
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>

#define L_CHILD_INDEX (curIndex * 2)
#define R_CHILD_INDEX (curIndex * 2 + 1)

using namespace std;

void Heap::AdjustFromBot()
{
	int curIndex(lastIndex);
	while (curIndex > 1)
	{
#if IS_MAX_HEAP == 1
		if (heap[curIndex] > heap[curIndex / 2])
		{
			int temp(heap[curIndex]);
			heap[curIndex] = heap[curIndex / 2];
			heap[curIndex / 2] = temp;

			curIndex /= 2;
		}
		else
		{
			break;
		}
#else
		if (heap[curIndex] < heap[curIndex / 2])
		{
			int temp(heap[curIndex]);
			heap[curIndex] = heap[curIndex / 2];
			heap[curIndex / 2] = temp;
		}
		else
		{
			breka;
		}
#endif
	}
}

void Heap::AdjustFromTop()
{
	int curIndex(1);
	while (curIndex * 2 <= lastIndex)
	{
#if IS_MAX_HEAP == 1
		if (R_CHILD_INDEX <= lastIndex)	// Has right child.
		{
			if (heap[L_CHILD_INDEX] > heap[R_CHILD_INDEX])
			{
				if (heap[L_CHILD_INDEX] > heap[curIndex])
				{
					int temp(heap[curIndex]);
					heap[curIndex] = heap[L_CHILD_INDEX];
					heap[L_CHILD_INDEX] = temp;

					curIndex = L_CHILD_INDEX;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (heap[R_CHILD_INDEX] > heap[curIndex])
				{
					int temp(heap[curIndex]);
					heap[curIndex] = heap[R_CHILD_INDEX];
					heap[R_CHILD_INDEX] = temp;

					curIndex = R_CHILD_INDEX;
				}
				else
				{
					break;
				}
			}
		}
		else if (L_CHILD_INDEX <= lastIndex)	// Has only L-child.
		{
			if (heap[L_CHILD_INDEX] > heap[curIndex])
			{
				int temp(heap[curIndex]);
				heap[curIndex] = heap[L_CHILD_INDEX];
				heap[L_CHILD_INDEX] = temp;

				curIndex = L_CHILD_INDEX;
			}
			else
			{
				break;
			}
		}
		else	// Leaf node.
		{
			break;
		}
#else
		if (R_CHILD_INDEX <= lastIndex)	// Has right child.
		{
			if (heap[L_CHILD_INDEX] < heap[R_CHILD_INDEX])
			{
				if (heap[L_CHILD_INDEX] < heap[curIndex])
				{
					int temp(heap[curIndex]);
					heap[curIndex] = heap[L_CHILD_INDEX];
					heap[L_CHILD_INDEX] = temp;

					curIndex = L_CHILD_INDEX;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (heap[R_CHILD_INDEX] < heap[curIndex])
				{
					int temp(heap[curIndex]);
					heap[curIndex] = heap[R_CHILD_INDEX];
					heap[R_CHILD_INDEX] = temp;

					curIndex = R_CHILD_INDEX;
				}
				else
				{
					break;
				}
			}
		}
		else if (L_CHILD_INDEX <= lastIndex)	// Has only L-child.
		{
			if (heap[L_CHILD_INDEX] < heap[curIndex])
			{
				int temp(heap[curIndex]);
				heap[curIndex] = heap[L_CHILD_INDEX];
				heap[L_CHILD_INDEX] = temp;

				curIndex = L_CHILD_INDEX;
			}
			else
			{
				break;
			}
		}
		else	// Leaf node.
		{
			break;
		}
#endif
	}

}

bool Heap::IsFull()
{
	return lastIndex == HEAP_SIZE;
}

bool Heap::IsEmpty()
{
	return lastIndex < 1;
}

void Heap::Push(const int item)
{
	if (IsFull())
	{
		cout << "Heap is full." << endl;

		return;
	}

	lastIndex++;
	heap[lastIndex] = item;

	AdjustFromBot();
}

int Heap::Pop()
{
	if (IsEmpty())
	{
		cout << "Heap is empty." << endl;

		return -1;
	}

	int retVal(heap[1]);
	heap[1] = heap[lastIndex];
	lastIndex--;

	AdjustFromTop();

	return retVal;
}

int Heap::GetHeight()
{
	return static_cast<int>(ceil(log2(lastIndex + 1))) - 1;
}


void Heap::Print()
{
	int curDepth(0);
	int treeHeight(GetHeight());
	cout << "***" << endl;
	for (int i = 1; i <= lastIndex; i++)
	{
		cout.setf(ios::left);
		cout << setw(3 * pow(2, treeHeight - curDepth)) << heap[i];

		// Level changed.
		if (i == pow(2, curDepth + 1) - 1)
		{
			cout << endl;

			curDepth++;
		}
	}
	cout << endl << "***" << endl;
}

Heap::Heap() :lastIndex(0)
{
	memset(heap, 0, sizeof(heap[0]) * (HEAP_SIZE + 1));
}
