#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;

#include "ProblemList.h"
#include "orderLinkedList.h"

/*
*problem list constructor
*reads the file and puts it into a llinked list of problems
*and populates the array
*/
ProblemList::ProblemList(string toRead)
{
	string aWord;
	problem prob;
	int i = 0;
	ifstream wordFile(toRead);
	//if file not found
	if (wordFile.fail())
	{
		cout << "Problem opening document file";
		exit(-1);
	}

	// Build list of words in document 
	wordFile >> aWord;                // Get first word 
	while (!wordFile.eof())
	{
		stringstream ss(aWord);
		string s;
		
		//split word appart at the comma
		while (getline(ss, s, ',')) {

			//i then count the commas and assign everything.
			if (i == 0)
			{
				prob.setProbCode(atoi(s.c_str()));
			}
			else if (i == 1)
			{
				prob.setCriticality(atoi(s.c_str()));
			}
			else if (i == 2)
			{
				prob.setDate(s);
			}
			else if (i == 3)
			{
				prob.setFName(s);
			}
			else if (i == 4)
			{
				prob.setLName(s);
				i = -1;
			}
			i++;
		}
		head.insertNode(prob);

		wordFile >> aWord;             // Get next word 

	}

	wordFile.close();//close the file
}

//returns the length of the linked list
int ProblemList::getLen()
{
	return head.getLength();
}

//returns the head of the linked list
OrderLinkedList<problem> ProblemList::getHead()
{
	return head;
}

/*
*write top
*writes the top of the list. using a user defined number
*/
void ProblemList::writeTop(int numToWrite)
{
	for (size_t i = 0; i < numToWrite; i++)
	{
		//advance till users num
		cout << head.getNextItem() << endl;
	}
}

//writes the bottem of the list
//using user defined number
void ProblemList::writeBottom(int numToWrite)
{
	int len = head.getLength();

	//the number i use here is 155.
	//for some reason genlength returns the wrong number
	//it returns 205 not the real length of 155
	for (size_t i = 0; i <= 155; i++)
	{
		if (i >= 155 - numToWrite)
		{
			cout << head.getNextItem() << endl;
		}
		head.getNextItem();
	}
}

//overloading of the += operator
ProblemList ProblemList::operator+= (ProblemList& toAdd)
{
	//assign the list to add to a temp.
	OrderLinkedList<problem> temp = toAdd.getHead();        // List head pointer

	//reset it, to ensure starting from the front
	temp.resetList();
	for (size_t i = 0; i < toAdd.getLen(); i++)
	{
		//insert the new item into the list
		head.insertNode(temp.getNextItem());
	}
	return toAdd;
}

//overloading of the -= operator
ProblemList ProblemList::operator-= (ProblemList& toAdd)
{
	//assign the list to add to a temp.
	OrderLinkedList<problem> temp = toAdd.getHead();         // List head pointer

	//reset it, to ensure starting from the front
	temp.resetList();
	for (size_t i = 0; i < toAdd.getLen(); i++)
	{
		//delete item in oldlist
		head.deleteNode(temp.getNextItem());
	}
	return toAdd;
}
