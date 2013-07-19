#include "stdafx.h"
#include "List.h"
#include "ItemType.h"


struct NodeType
{
  ItemType info;
  NodeType* next;
};



List::List()  // Class constructor
{
  length = 0;
  listData = NULL;
}


List::~List()
{
  NodeType* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}


bool List::IsFull() const
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

bool List::IsEmpty() const
{
	if (length == 0)
		return true;
	else 
		return false;
}


int List::GetLength() const
{
  return length;
}



void List::MakeEmpty()
{
  NodeType* tempPtr;

  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
}



ItemType List::GetItem(ItemType& item, bool& found)
{
  bool moreToSearch;
  NodeType* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    switch(item.ComparedTo(location->info))
    {
      case GREATER: location = location->next;
                    moreToSearch = (location != NULL);
                    break;
      case EQUAL:   found = true;
                    item = location->info;
                    break;
      case LESS:    moreToSearch = false;
                    break;
    }
  }
  return item;
}


int List::PopItem()
{
	if (IsEmpty())
		throw EmptyPQ();
	else
	{
		NodeType* tmpPtr;
		tmpPtr = listData;
		listData = listData->next;
		delete tmpPtr;
		return 1;
	}
}



int List::PutItem(ItemType item)
{
	int accessed = 0;
	NodeType* newNode;  	// pointer to node being inserted
	NodeType* predLoc;  	// trailing pointer
	NodeType* location; 	// traveling pointer
	bool moreToSearch;

	location = listData;
	predLoc = NULL;
	moreToSearch = (location != NULL);

	// Find insertion point.
	while (moreToSearch)
	{
		switch(item.ComparedTo(location->info))
		{
			case GREATER: predLoc = location;
      					location = location->next;
						accessed++;
						moreToSearch = (location != NULL);
						break;
			case LESS:    moreToSearch = false;
						break;
		}
	}

	// Prepare node for insertion
	newNode = new NodeType;
	newNode->info = item;
	// Insert node into list.
	if (predLoc == NULL)         // Insert as first
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
	return accessed;
}



void List::DeleteItem(ItemType item)
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item.ComparedTo(listData->info) == EQUAL)
  {
    tempLocation = location;
    listData = listData->next;	// Delete first node.
  }
  else
  {
    while (item.ComparedTo((location->next)->info) != EQUAL)
      location = location->next;

    // Delete node at location->next
    tempLocation = location->next;
    location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}



void List::ResetList()
{
  currentPos = NULL;
} 



ItemType List::GetNextItem()
{
  ItemType item;
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;
  return item;

} 
