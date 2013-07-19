#include "stdafx.h"
#include "ItemType.h"


ItemType::ItemType()
{ 
  value = 0;
}

ItemType::ItemType(int intIN)
{ 
  value = intIN;
}

RelationType ItemType::ComparedTo(ItemType otherItem) const 
{
  if (value < otherItem.value)
    return LESS;
  else if (value > otherItem.value)
    return GREATER;
  else return EQUAL;
}

void ItemType::Initialize(int number) 
{
  value = number;
}

void ItemType::Print() const 
// pre:  out has been opened.
// post: value has been sent to the stream out.
{
  std::cout << value << std::endl;
}

bool ItemType::operator>(ItemType b)
{
	if(ComparedTo(b) == GREATER)
		return true;
	else 
		return false;
}

bool ItemType::operator<(ItemType b)
{
	if(ComparedTo(b) == LESS)
		return true;
	else 
		return false;
}

bool ItemType::operator<=(ItemType b)
{
	if(ComparedTo(b) == LESS || ComparedTo(b) == EQUAL)
		return true;
	else 
		return false;
}

bool ItemType::operator>=(ItemType b)
{
	if(ComparedTo(b) == GREATER || ComparedTo(b) == EQUAL)
		return true;
	else 
		return false;
}