// Specification file for the BinTreeType class 
// PRECONDITION for use of this class: 
//    Data type defining tree node "info" must have operators 
//   '<', 'cout', and ==', or they must be overloaded 


//Michael changed stuff here..
//added a few features for this .
//for searching.
#ifndef BINARYTREE_H 
#define BINARYTREE_H 

#include "person.h"
#include "amazonTrans.h" 
#include <iostream> 
using namespace std; 

template <class ItemType> 
class BinTreeType 
{ 
   private: 
    struct TreeNode 
    { 
        ItemType info; 
        TreeNode *left; 
        TreeNode *right; 
    }; 

    TreeNode *root; 

    // Overloaded functions for recursive actions 
    void insert(TreeNode *&, TreeNode *&); 
    void deleteIt(ItemType, TreeNode *&); 
    void makeDeletion(TreeNode *&); 
    void destroySubTree(TreeNode *); 
    void getSucccessor( TreeNode* aNode, ItemType& data); 
    void copyTree(TreeNode*& copy, const TreeNode* origTree); 

    // Overloaded traversal functions for recursive actions 
    void displayInOrder(TreeNode *); 
    void displayPreOrder(TreeNode *); 
    void displayPostOrder(TreeNode *); 
     
    // Recursive functions for various utility operations 
    int countNodes(TreeNode* tree); 
    int getDepth(TreeNode* tree); 
	bool found = false;
public: 
    BinTreeType();                            // Constructor 
    BinTreeType(BinTreeType& origTree);       // Copy constructor 
    void operator= (BinTreeType& origTree);   // Overloaded assignment operator 
    ~BinTreeType();                           // Destructor 
     
    // Tree data insertion, deletion, and searching 
    void insertNode(ItemType); 
    bool searchNode(ItemType); 
    void deleteNode(ItemType); 

    // Tree traversal 
    void displayInOrder(); 
    void displayPreOrder(); 
    void displayPostOrder(); 
     
    // Utilities for tree operations 
    int numberOfNodes();                  // Count nodes in tree 
    int treeDepth(); 

	//added the functions below here
	person get(ItemType);
	void findme(ItemType);
	void findme(TreeNode *nodePtr, ItemType);



}; 
//main calling function for the recursive find me function
//if the recursive function does not find it, found will stay false
//once the functions are done. if found is false is will give error
template <class ItemType>
void BinTreeType<ItemType>::findme(ItemType item)
{
	findme(root, item);
	if (found == false)
	{
		cout << "could not find that dat/Cust ID, try again. please check and try again" << endl;
	}
}

// Recursive function fo searching for a cust id and date
template <class ItemType>
void BinTreeType<ItemType>::findme(TreeNode *nodePtr, ItemType item)
{
	//trans the user is looking for
	amazonTrans temp = item;
	if (nodePtr != NULL)
	{
		//temp trans for this current node
		amazonTrans temp2 = nodePtr->info;
		//compare
		if ( temp.getDate() == temp2.getDate()
			&& temp.getCustomerID() == temp2.getCustomerID())
		{
			//if found cout the trans and set found to true
			cout << temp2 << endl;
			found = true;
		}
		else
		{
			//else recurse
			findme(nodePtr->left, temp);
			findme(nodePtr->right, temp);
		}
	}

}

//************************************************************* 
//************************************************************* 
// Implementation file for the BinTreeType class 
//************************************************************* 
//************************************************************* 

// Constructor 
template <class ItemType> 
BinTreeType<ItemType>::BinTreeType()      
{  
   root = NULL; 
} 

template <class ItemType>

//will return the person info.
//this will scan through the tree looking
//for a person by their id and then return them
person BinTreeType<ItemType>::get(ItemType item)
{
	TreeNode *nodePtr = root;
	person temp;
	while (nodePtr != NULL)
	{
		if (nodePtr->info == item)
		{
			//temp = nodePtr->info;
			return nodePtr->info;
		}
		
		else if (item < nodePtr->info)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
}	


//************************************************************* 
// Copy constructor - Utilizes recursive utility function 
// copyTree to actually replicate original tree 
//************************************************************* 

template <class ItemType> 
BinTreeType<ItemType>::BinTreeType(BinTreeType<ItemType>& origTree) 
{ 
   copyTree(root, origTree.root); 
} 

//************************************************************* 
// Overloaded assignment operator - Utilizes recursive utility function 
// copyTree to actually replicate original tree 
//************************************************************* 

template <class ItemType> 
void BinTreeType<ItemType>::operator= (BinTreeType<ItemType>& origTree) 
{ 
   destroySubTree(root);          // Eliminate any existing nodes in target 
   copyTree(root, origTree.root); // Copy source to target as part of assignment 
} 

//************************************************************* 
// Destructor 
//************************************************************* 

template <class ItemType> 
BinTreeType<ItemType>::~BinTreeType()      
{ 
   destroySubTree(root); 
} 

//************************************************************* 
// insert accepts a TreeNode pointer and a pointer to a node. * 
// The function inserts the node into the tree pointed to by  * 
// the TreeNode pointer. This function is called recursively. * 
//************************************************************* 

template <class ItemType> 
void BinTreeType<ItemType>::insert(TreeNode *&nodePtr, TreeNode *&newNode) 
{ 
    if (nodePtr == NULL) 
        nodePtr = newNode;                      // Insert the node. 
    else if (newNode->info < nodePtr->info) 
        insert(nodePtr->left, newNode);         // Search the left branch 
    else  
        insert(nodePtr->right, newNode);        // Search the right branch 
} 

//********************************************************** 
// insertNode creates a new node to hold num as its value, * 
// and passes it to the insert function.                   * 
//********************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::insertNode(ItemType num) 
{ 
    TreeNode *newNode;        // Pointer to a new node. 

    // Create a new node and store num in it. 
    newNode = new TreeNode; 
    newNode->info = num; 
    newNode->left = newNode->right = NULL; 
    // Insert the node. 
    insert(root, newNode); 
} 

//*************************************************** 
// destroySubTree is called by the destructor. It   * 
// deletes all nodes in the tree.                   * 
//*************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::destroySubTree(TreeNode *nodePtr) 
{ 
    if (nodePtr != NULL) 
    { 
        if (nodePtr->left != NULL) 
            destroySubTree(nodePtr->left); 
        if (nodePtr->right != NULL) 
            destroySubTree(nodePtr->right); 
        delete nodePtr; 
    } 
} 
     
//*************************************************** 
// searchNode determines if a value is present in   * 
// the tree. If so, the function returns true.      * 
// Otherwise, it returns false.                     * 
//*************************************************** 

template <class ItemType> 
bool BinTreeType<ItemType>::searchNode(ItemType item) 
{ 
    TreeNode *nodePtr = root; 

    while (nodePtr != NULL) 
    { 
        if (nodePtr->info == item) 
            return true; 
        else if (item < nodePtr->info) 
            nodePtr = nodePtr->left; 
        else 
            nodePtr = nodePtr->right; 
    } 
    return false; 
} 

//********************************************** 
// Function deleteNode triggers the chain of   * 
// recursive  calls to search for and delete   * 
// target node.                                * 
//********************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::deleteNode(ItemType item) 
{ 
    deleteIt(item, root); 
} 


//*********************************************** 
// Function deleteIt recursively searches for   * 
// the item to delete and calls function        * 
// makeDeletion to perform the actual deletion. * 
//*********************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::deleteIt(ItemType item, TreeNode *&nodePtr) 
{ 
    if (item < nodePtr->info) 
        deleteIt(item, nodePtr->left); 
    else if (item > nodePtr->info) 
        deleteIt(item, nodePtr->right); 
    else 
        makeDeletion(nodePtr); 
} 

//*********************************************************** 
// makeDeletion takes a reference to a pointer to the node  * 
// that is to be deleted. The node is removed and the       *    
// branches of the tree below the node are reattached.      * 
//*********************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::makeDeletion(TreeNode *&nodePtr) 
{ 
    TreeNode *tempNodePtr;   // Temporary pointer, used for deletion 
    ItemType data; 

    if (nodePtr->right == NULL)       // If no right child exists 
    { 
        tempNodePtr = nodePtr;  
        nodePtr = nodePtr->left;      // Then reattach the left child 
        delete tempNodePtr; 
    } 
    else if (nodePtr->left == NULL)   // If no left child exists 
    { 
        tempNodePtr = nodePtr;  
        nodePtr = nodePtr->right;     // Then reattach the right child 
        delete tempNodePtr; 
    }  
    else                              // If the node has two children 
    { 
        // Get data for immediate successor (largest node in right subtree) 
        getSucccessor(nodePtr,data); 
             
        // Move information from successor node to target node 
        nodePtr->info = data; 
        deleteIt(data, nodePtr->right);     // And delete successor node       
    } 
} 

//**************************************************************** 
// This function scans for the succeeding node in order within   * 
// a binary tree.  It moves the the right child, and then moves  * 
// down the chain of left children until NULL is reached.   It   * 
// returns the data at the predecessor node by reference.        * 
//**************************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::getSucccessor( TreeNode* aNode, ItemType& data) 
{ 
   aNode = aNode->right; 
   while (aNode->left != NULL) 
      aNode = aNode->left; 
   data = aNode->info; 
    
} 

//**************************************************************** 
// The displayInOrder member function displays the values        * 
// in the subtree pointed to by nodePtr, via inorder traversal.  * 
//**************************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::displayInOrder() 
{     
   displayInOrder(root);  
} 

// Recursive function performing traversal 
template <class ItemType> 
void BinTreeType<ItemType>::displayInOrder(TreeNode *nodePtr) 
{ 
    if (nodePtr != NULL) 
    { 

        displayInOrder(nodePtr->left); 
        cout << nodePtr->info << " "; 
        displayInOrder(nodePtr->right); 
    } 
} 

//**************************************************************** 
// The displayPreOrder member function displays the values       * 
// in the subtree pointed to by nodePtr, via preorder traversal. * 
//**************************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::displayPreOrder() 
{     
   displayPreOrder(root);  
} 

// Recursive function performing traversal 
template <class ItemType> 
void BinTreeType<ItemType>::displayPreOrder(TreeNode *nodePtr) 
{ 
    if (nodePtr != NULL) 
    { 
        cout << nodePtr->info << " "; 
        displayPreOrder(nodePtr->left);         
        displayPreOrder(nodePtr->right); 
    } 
} 

//**************************************************************** 
// The displayPostOrder member function displays the values      * 
// in the subtree pointed to by nodePtr, via postorder traversal.* 
//**************************************************************** 

template <class ItemType> 
void BinTreeType<ItemType>::displayPostOrder() 
{ 
   displayPostOrder(root); 
} 

// Recursive function performing traversal 
template <class ItemType> 
void BinTreeType<ItemType>::displayPostOrder(TreeNode *nodePtr) 
{ 
    if (nodePtr != NULL) 
    { 
        displayPostOrder(nodePtr->left);         
        displayPostOrder(nodePtr->right); 
        cout << nodePtr->info << " "; 
    } 
} 

//**************************************************************** 
// This function recursively traverses the tree and increments   * 
// a counter at each node "visit" to count the total number of   * 
// data nodes in the tree.                                       * 
//**************************************************************** 

template<class ItemType> 
int BinTreeType<ItemType>::numberOfNodes() 
{ 
  return countNodes(root); 
} 

// Private function performing recursive count 
template<class ItemType> 
int BinTreeType<ItemType>::countNodes(TreeNode* tree) 
{ 
  if (tree == NULL) 
    return 0; 
  else 
    return countNodes(tree->left)  + 
           countNodes(tree->right) + 1; 
} 

//****************************************************************** 
// This function replicates a tree as part of the copy constructor * 
// and overloaded assignment operations.                            * 
//****************************************************************** 

template<class ItemType> 
void BinTreeType<ItemType>::copyTree(TreeNode*& copy, const TreeNode* origTree) 
{ 
   if (origTree == NULL)   // Handle case of empty tree 
      copy = NULL; 
   else 
   { 
      copy = new TreeNode; 
      copy->info = origTree->info; 
      copyTree(copy->left, origTree->left); 
      copyTree(copy->right, origTree->right); 
   } 
} 

//****************************************************************** 
// Function checking maximum depth below current node 
//****************************************************************** 

// Public function initiating count and returning total to main 
// function call 
template<class ItemType> 
int BinTreeType<ItemType>::treeDepth() 
{ 
    int    depth = getDepth(root) - 1; 
    return depth; 
} 

template<class ItemType> 
int BinTreeType<ItemType>::getDepth(TreeNode* tree) 
{ 
    if (tree == NULL) 
        return 0; 
    else 
    { 
        // Get depths below current node 
        int leftDepth  = getDepth(tree->left); 
        int rightDepth = getDepth(tree->right); 
         
        // Return max depth of subtrees plus one for "this" node 
        if ( leftDepth > rightDepth) 
            return leftDepth + 1; 
        else 
            return rightDepth + 1; 
    } 
} 



#endif 
