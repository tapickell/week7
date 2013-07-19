#include "stdafx.h"
#include "listQdriver.h"
#include "List.h"
#include "ItemType.h"


listQdriver::listQdriver(void)
{
}


listQdriver::~listQdriver(void)
{
}

void listQdriver::RunTests()
{
	std::cout << "Testing Linked List Implementation" << std::endl;

	int enq = 0;
	int deq = 0;
	//create linked list version of a priorityQ
	List listQ = List();

	//for loop that creates 50 items using random int and adds them to the list
	for (int i = 0; i < 50; i++)
	{
		ItemType item = ItemType(rand());
		//item.Print();
		enq += listQ.PutItem(item);
	}
	//print out accessed number for enqueing
	std::cout << std::endl << "ListQ moves to Enqueue 50 items: " << enq << std::endl;

	std::cout << "List length: " << listQ.GetLength();

	//for loop the pops 50 items of the list
	for (int i = 0; i < listQ.GetLength(); i++)
	{
		deq += listQ.PopItem();
	}

	//print out accessed number for dequeueing
	std::cout << std::endl << "ListQ moves to Dequeue 50 items: " << deq << std::endl;
}