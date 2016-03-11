//********************************************* 
// The ListNode class creates a type used to  * 
// store a node of the linked list.           * 
// PRECONDITIONS:                             * 
//   Choice for ItemType implements 'cout'    * 
//   as well as "==" and "<" operators        * 
//********************************************* 
#ifndef OrderOrderLinkedList_H 
#define OrderOrderLinkedList_H 

template <class ItemType> 
class ListNode 
{ 
public: 
	ItemType info;                // Node value 
	ListNode<ItemType> *next;     // Pointer to the next node 

	// Constructor 
	ListNode (ItemType nodeValue) 
	{      
		info = nodeValue; 
		next = NULL; 
	} 
}; 

//********************************************* 
// OrderLinkedList class                           * 
//********************************************* 

template <class ItemType> 
class OrderLinkedList 
{ 
private: 
	ListNode<ItemType> *head;        // List head pointer 
	ListNode<ItemType> *currentPos;  // Pointer to "current" list item 
	int length;                      // Length 

public: 
	OrderLinkedList();                                               // Constructor 
	~OrderLinkedList();                                              // Destructor 
	OrderLinkedList( const OrderLinkedList<ItemType>& anotherList ); // Copy constructor 
	void operator= ( const OrderLinkedList<ItemType>& );             // Assignment op 

	void insertNode(ItemType); 
	void deleteNode(ItemType); 
	bool searchList(ItemType& item); 

	int getLength();     
	void displayList(); 

	void resetList();              
	ItemType getNextItem();        // Iterator 
	bool atEnd(); 
}; 

//************************************************** 
// Constructor                                     * 
// Initial list head pointer and length            * 
//************************************************** 
template <class ItemType> 
OrderLinkedList<ItemType>::OrderLinkedList()     
{ 
	head = NULL; 
	length = 0; 
} 

//************************************************** 
// displayList shows the value stored in each node * 
// of the linked list pointed to by head.          * 
// Precondition: "cout" operator enabled for       * 
// ItemType data type.                             * 
//************************************************** 

template <class ItemType> 
void OrderLinkedList<ItemType>::displayList() 
{ 
	ListNode<ItemType> *nodePtr; 

	nodePtr = head; 
	while (nodePtr != NULL) 
	{ 
		cout << nodePtr->info << endl; 
		nodePtr = nodePtr->next; 
	} 
} 
//************************************************** 
// The insertNode function inserts a node with     * 
// newValue copied to its value member.            * 
//************************************************** 

template <class ItemType> 
void OrderLinkedList<ItemType>::insertNode(ItemType newValue) 
{ 
	//Michael Edit!!
	//had to set previous new to null.
	ListNode<ItemType> *newNode, *nodePtr, *previousNode = NULL; 

	// Allocate a new node & store newValue 
	newNode = new ListNode<ItemType>(newValue); 

	// If there are no nodes in the list 
	// make newNode the first node 
	if (head == NULL) 
	{ 
		head = newNode; 
		newNode->next = NULL; 
	} 
	else    // Otherwise, insert newNode 
	{ 
		// Initialize nodePtr to head of list and previousNode to NULL. 
		nodePtr = head; 
		previousNode = NULL; 

		// Skip all nodes whose value member is less 
		// than newValue. 
		while (nodePtr != NULL && nodePtr->info < newValue) 
		{     
			previousNode = nodePtr; 
			nodePtr = nodePtr->next; 
		} 

		// If the new node is to be the 1st in the list, 
		// insert it before all other nodes. 
		if (previousNode == NULL) 
		{ 
			head = newNode; 
			newNode->next = nodePtr; 
		} 
		else    // Otherwise, insert it after the prev. node. 
		{ 
			previousNode->next = newNode; 
			newNode->next = nodePtr; 
		} 
	} 
	length++;
} 

//***************************************************** 
// The deleteNode function searches for a node        * 
// with searchValue as its value. The node, if found, * 
// is deleted from the list and from memory.          * 
//***************************************************** 

template <class ItemType> 
void OrderLinkedList<ItemType>::deleteNode(ItemType searchValue) 
{ 
	ListNode<ItemType> *nodePtr, *previousNode = NULL; 

	// If the list is empty, do nothing. 
	if (!head) 
		return; 

	// Determine if the first node is the one. 
	if (head->info == searchValue) 
	{ 
		nodePtr = head->next; 
		delete head; 
		head = nodePtr; 
	} 
	else 
	{ 
		// Initialize nodePtr to head of list 
		nodePtr = head; 

		// Skip all nodes whose value member is  
		// not equal to searchValue. 
		while (nodePtr != NULL && nodePtr->info != searchValue) 
		{     
			previousNode = nodePtr; 
			nodePtr = nodePtr->next; 
		} 

		// If nodePtr is not at the end of the list,  
		// link the previous node to the node after 
		// nodePtr, then delete nodePtr. 
		if (nodePtr) 
		{ 
			previousNode->next = nodePtr->next; 
			delete nodePtr; 
		}     
	} 
	length--; 
} 

//************************************************** 
// Linear search                                   * 
// Post: If found, item's key matches an element's * 
// key in the list and a copy of that element has  * 
// been stored in item; otherwise, item is         * 
// unchanged.  Return value is boolean to indicate * 
// status of search.                               * 
//************************************************** 

template <class ItemType> 
bool OrderLinkedList<ItemType>::searchList(ItemType& item) 
{ 
	bool moreToSearch; 
	ListNode<ItemType>* nodePtr; 

	nodePtr = head;                // Start search from head of list 
	bool found = false;            // Assume value not found 
	moreToSearch = (nodePtr != NULL); 

	while (moreToSearch && !found) 
	{ 
		if (nodePtr->info < item) 
		{ 
			nodePtr = nodePtr->next; 
			moreToSearch = (nodePtr != NULL); 
		} 
		else if (item == nodePtr->info) 
		{ 
			found = true; 
			item = nodePtr->info; 
		} 
		else 
			moreToSearch = false; 
	} 
	return found; 
} 

//************************************************** 
// Iterator reset function                         * 
// Resets pointer of current item in list to the   * 
// head of the list.                               * 
//************************************************** 

template <class ItemType> 
void OrderLinkedList<ItemType>::resetList() 
	// Post: Current position has been initialized. 
{ 
	currentPos = head;  
} 

//************************************************** 
// Function: Gets the next element in list as  
//           referenced by currPtr 
// Pre:  Current position is defined. 
//       Element at current position is not last in list.  
// Post: Current position is updated to next position. 
//       item is a copy of element at current position. 
//************************************************** 
template <class ItemType> 
ItemType OrderLinkedList<ItemType>::getNextItem()  
{ 
	ItemType item; 

	if (currentPos == NULL)    
		currentPos = head;  // wrap if getnext is called at past-end 
	//else  
	item = currentPos->info; 
	currentPos = currentPos->next; 

	return item; 
}  

//************************************************** 
// Observer function to return current list length * 
//************************************************** 
template <class ItemType> 
int OrderLinkedList<ItemType>::getLength() 
{ 
	return length; 
} 

//************************************************** 
// Observer function to determine if current       * 
// is the end of the list                          * 
//************************************************** 
template <class ItemType> 
bool OrderLinkedList<ItemType>::atEnd() 
{ 
	if (currentPos == NULL) 
		return true; 
	else 
		return false;   
} 

//************************************************** 
// Copy Constructor                                * 
//************************************************** 
template<class ItemType>         
OrderLinkedList<ItemType>::OrderLinkedList( const OrderLinkedList<ItemType>& anotherList ) 
{     
	ListNode<ItemType>* ptr1; 
	ListNode<ItemType>* ptr2; 

	if (anotherList.head == NULL) 
		head = NULL; 
	else 
	{ 
		head = new ListNode<ItemType>(anotherList.head->info); 
		ptr1 = anotherList.head->next; 
		ptr2 = head; 
		while (ptr1 != NULL) 
		{ 
			ptr2->next = new ListNode<ItemType>(ptr1->info); 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
		ptr2->next = NULL; 
	}     
	length = anotherList.length; 
} 

//************************************************** 
// Overloaded Assignment Operator                  * 
//************************************************** 
template<class ItemType>         
void OrderLinkedList<ItemType>::operator=( const OrderLinkedList<ItemType>& anotherList ) 
{        
	ListNode<ItemType>* ptr1; 
	ListNode<ItemType>* ptr2; 

	if (anotherList.head == NULL) 
		head = NULL; 
	else 
	{ 
		head = new ListNode<ItemType>(anotherList.head->info); 
		ptr1 = anotherList.head->next; 
		ptr2 = head; 
		while (ptr1 != NULL) 
		{ 
			ptr2->next = new ListNode<ItemType>(ptr1->info); 
			ptr2 = ptr2->next; 
			ptr1 = ptr1->next; 
		} 
		ptr2->next = NULL; 
	}     
	length = anotherList.length; 
} 

//************************************************** 
// Destructor                                      * 
// This function deletes every node in the list.   * 
//************************************************** 

template <class ItemType> 
OrderLinkedList<ItemType>::~OrderLinkedList() 
{ 
	ListNode<ItemType> *nodePtr, *nextNode; 

	nodePtr = head; 
	while (nodePtr != NULL) 
	{ 
		nextNode = nodePtr->next; 
		delete nodePtr; 
		nodePtr = nextNode; 
	} 
} 

#endif 