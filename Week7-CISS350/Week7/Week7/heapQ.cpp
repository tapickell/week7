#include "stdafx.h"
#include "heapQ.h"




heapQ::heapQ(int max)
{
	maxItems = max;
	items.elements = new ItemType[max];
	length = 0;
}


heapQ::~heapQ()
{
	delete [] items.elements;
}


void heapQ::MakeEmpty()
{
	length = 0;
}


int heapQ::Dequeue(ItemType& item)
{
	if (length == 0)
		throw EmptyPQ();
	else
	{
		item = items.elements[0];
		items.elements[0] = items.elements[length-1];
		length--;
		int y = items.ReheapDown(0, length-1);
		//y is number of times reheapDown swapped elements
		//std::cout << "Y from dequeue: " << y << std::endl;
		return y;
	}
}


int heapQ::Enqueue(ItemType newItem)
{
	if (length == maxItems)
		throw FullPQ();
	else
	{
		length++;
		items.elements[length-1] = newItem;
		int x = items.ReheapUp(0, length-1);
		//x is number of times reheapUp swapped elements
		//std::cout << "X from enqueue: " << x << std::endl;
		return x;
	}
}


bool heapQ::IsFull() const
{
	return length == maxItems;
}


bool heapQ::IsEmpty() const
{
	return length == 0;
}

int heapQ::GetLength()
{
	return length;
}