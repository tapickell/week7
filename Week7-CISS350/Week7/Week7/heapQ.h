#pragma once

//exception classes need to make these!
class FullPQ{};
class EmptyPQ{};

#include "heap.h"
#include "ItemType.h"

class heapQ
{
public:
	heapQ(int);
	~heapQ();

	void MakeEmpty();
	// Function: Initializes the queue to an empty state.
	// Post: Queue is empty.
  
	bool IsEmpty() const;
	// Function: Determines whether the queue is empty.
	// Post: Function value = (queue is empty)
  
	bool IsFull() const;
	// Function: Determines whether the queue is full.
	// Post: Function value = (queue is full)
  
	int Enqueue(ItemType newItem);
	// Function: Adds newItem to the rear of the queue.
	// Post: if (the priority queue is full) exception FullPQ is thrown;
	//       else newItem is in the queue.
  
	int Dequeue(ItemType& item);
	// Function: Removes element with highest priority from the queue
	// and returns it in item.
	// Post: If (the priority queue is empty) exception EmptyPQ is thrown;
	//       else highest priority element has been removed from queue.
	//       item is a copy of removed element.
	int GetLength();
private:
	int length;
	HeapType<ItemType> items;
	int maxItems;
};

