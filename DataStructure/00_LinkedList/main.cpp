#include "List.h"

void main()
{
	List list;

	std::cout << "Push back 3-2-1." << std::endl;
	list.PushBack(3);
	list.PushBack(2);
	list.PushBack(1);
	list.Print();

	std::cout << "Pop front." << std::endl;
	list.PopFront();
	list.Print();

	std::cout << "Push front 6-7." << std::endl;
	list.PushFront(6);
	list.PushFront(7);
	list.Print();

#if IS_LIST == 1
	std::cout << "Remove at 4th" << std::endl;
	list.Remove(4);
	list.Print();

	std::cout << "Remove at 2nd" << std::endl;
	list.Remove(2);
	list.Print();

	std::cout << "Insert 9 at 3th" << std::endl;
	list.Insert(3, 9);
	list.Print();
#endif

}