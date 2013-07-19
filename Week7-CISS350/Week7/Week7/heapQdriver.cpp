#include "stdafx.h"
#include "heapQdriver.h"
#include "heapQ.h"


heapQdriver::heapQdriver(void)
{
}


heapQdriver::~heapQdriver(void)
{
}

void heapQdriver::RunTests()
{
	std::cout << "Testing Minimum Heap Implementation" << std::endl;

	int enq = 0;
	int deq = 0;

	//create heap version of priorityQ
	heapQ minHeapQ = heapQ(100);

	//for loop that creat 50 items using random int and adds them to the heapQ
	for (int i = 0; i < 50; i++)
	{
		ItemType item = ItemType(rand());
		//item.Print();
		enq += minHeapQ.Enqueue(item);
	}
	//print out accessed number for enqueing
	std::cout << std::endl << "heapQ moves to Enqueue 50 items: " << enq << std::endl;

	std::cout << "List length: " << minHeapQ.GetLength();

	//for loop the pops 50 items of the heapQ
	for (int i = 0; i < minHeapQ.GetLength(); i++)
	{
		ItemType temp;
		deq += minHeapQ.Dequeue(temp);
	}

	//print out accessed number for dequeueing
	std::cout << std::endl << "heapQ moves to Dequeue 50 items: " << deq << std::endl;
}
