template <class ItemType>
void swap(ItemType& one, ItemType& two);

template<class ItemType>
// Assumes ItemType is either a built-in simple type or a class
// with overloaded relational operators.
struct HeapType
{
  int ReheapDown(int root, int bottom);
  int ReheapUp(int root, int bottom);
  ItemType* elements;   // Array to be allocated dynamically
  int numElements;
};

template <class ItemType>
void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}  

// need this to return an int of how many elements are compared or swapped
template<class ItemType>
int HeapType<ItemType>::ReheapUp(int root, int bottom)
// Post: Heap property is restored.
{
	int accessed = 0;
	int parent;
  
	if (bottom < root)//bottom < root for min // bottom > root  for max  ###########################
	{
		parent = (bottom-1) / 2;
		if (elements[parent] < elements[bottom])
		{
			Swap(elements[parent], elements[bottom]);
			accessed++;
			ReheapUp(root, parent);
		}
	}
	accessed++;
	//std::cout << "Accessed from reheapUp: " << accessed << std::endl;
	return accessed;
}

// need this to return an int of how many elements are compared or swapped
template<class ItemType>
int HeapType<ItemType>::ReheapDown(int root, int bottom)
// Post: Heap property is restored.
{
	int accessed = 0;
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;
	rightChild = root*2+2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] > elements[maxChild])// elements[root] > elements[maxChild] for min // elements[root] < elements[maxChild] for max##################
		{
			Swap(elements[root], elements[maxChild]);
			
			ReheapDown(maxChild, bottom);
			accessed++; 
		}
	}
	accessed++;
	//std::cout << "Accessed from reheapDown: " << accessed << std::endl;
	return accessed;
}

