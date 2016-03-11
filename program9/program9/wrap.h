#ifndef WRAP_H 
#define WRAP_H 


#include <fstream> 
#include <iostream> 
#include <string>
#include "binTreeType.h"
#include "amazonTrans.h"
#include "person.h"
using namespace std;

/*
*this is a wrapper class to push all the nasty
*stuff for binary search tree. this way the user
*just has to call the find function to get the info
*they want
*/
class wrap
{
private:
	//two BST to hold all data
	BinTreeType<amazonTrans> transTree;
	BinTreeType<person> personTree;

	//one call to make both BST they have to be
	//built in a certin order
	void makeBST();
	
	//populate the people BST
	void popPepsBST();

	//populate the tranzation BST
	void popTransBST();

public:
	
	wrap();

	//call this to find something in the transction BST
	void find(int toFind, string findIt);
};

#endif 
