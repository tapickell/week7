#pragma once

#include "ItemType.h"

//exception classes need to make these!
class FullPQ{};
class EmptyPQ{};

struct NodeType;

class List
{
public:
	List(void);
	~List(void);

	bool IsFull() const;
	bool IsEmpty() const;
	int  GetLength() const;
	void MakeEmpty();
	ItemType GetItem(ItemType& item, bool& found);
	int PutItem(ItemType item); 
	void DeleteItem(ItemType item);
	void ResetList();
	ItemType GetNextItem();
	int PopItem();

private:
	NodeType* listData;
	int length;
	NodeType* currentPos;
};

