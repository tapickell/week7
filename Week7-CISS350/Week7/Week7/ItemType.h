#pragma once

const int MAX_ITEMS = 5;
enum RelationType  {LESS, GREATER, EQUAL};

class ItemType 
{ 
public:
	ItemType();
	ItemType(int);
	RelationType ComparedTo(ItemType) const;
	void Print() const;
	void Initialize(int number);
	bool operator>(ItemType);
	bool operator<(ItemType);
	bool operator<=(ItemType);
	bool operator>=(ItemType);

private:
	int value;
};