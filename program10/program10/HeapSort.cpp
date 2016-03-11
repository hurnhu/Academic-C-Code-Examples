// This file include the functions to implement Heap Sort. 
namespace {
 int swapss = 0, compss = 0;
}
// This is a generic function to swap values of any data type 
template<class ItemType> 
inline void Swap(ItemType& item1, ItemType& item2) 
{ 
	ItemType tempItem; 
	swapss++;
	tempItem = item1; 
	item1 = item2; 
	item2 = tempItem; 
} 

// This function drives the heapsort algorthm by: 
// 1) converting any array into a heap pattern 
// 2) swapping and reheaping array to perform sort 
template<class ItemType> 
inline void HeapSort(ItemType values[], int numValues) 
{ 
	int index; 

	// Convert the array of values into a heap 
	for (index = numValues/2 - 1; index >= 0; index--) 
		ReheapDown(values, index, numValues-1); 

	// Sort the array 
	for (index = numValues-1; index >=1; index--) 
	{ 
		Swap(values[0], values[index]); 
		ReheapDown(values, 0, index-1); 
	} 
	cout<< swapss << " " << compss << endl;
} 

// This function includes only the action to reheap down 
// to restore a heap from the top-down 
template<class ItemType> 
void ReheapDown(ItemType elements[], int root, int bottom) 
	// Post: Heap property is restored. 
{ 
	int maxChild; 
	int rightChild; 
	int leftChild; 
	leftChild = root * 2 + 1; 
	rightChild = root * 2 + 2; 
	compss++;
	if (leftChild <= bottom) 
	{ 
		compss++;
		if (leftChild == bottom) 
			maxChild = leftChild; 
		else 
		{ 
			compss++;
			if (elements[leftChild] <= elements[rightChild]) 
				maxChild = rightChild; 
			else 
				maxChild = leftChild; 
		} 
		compss++;

		if (elements[root] < elements[maxChild]) 
		{ 
			Swap(elements[root], elements[maxChild]); 
			ReheapDown(elements, maxChild, bottom); 
		} 
	} 
} 
