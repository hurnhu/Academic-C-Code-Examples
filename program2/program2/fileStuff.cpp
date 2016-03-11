#include <iostream>
#include <fstream>

#include "fileStuff.h"

using namespace std;
/****************************************************
*function def for writeToFile						*
*This takes the array and the curr size of the array*
*then writes the contents of the array to the file	*
*this does not append to the file, it writes over	*
*every time (had some logic trouble when trying		*
*to append)											*
*****************************************************/
void fileStuff::writeToFile(string* arrayOfObj, int lineNum, string fileToRead)
{
	ofstream myfile;
	//uses a .perf file, this keeps user from
	//messing with the file, can be opened
	//as plain text tho.
	myfile.open(fileToRead);
	if (!myfile.fail())
	{
		cout << "Looks like the file isnt there." << endl;
	}
	else
	{
		for (int i = 0; i <= lineNum; i++)
		{
			myfile << arrayOfObj;
		}
		myfile.close();

	}
}
/****************************************************
*function def for readFromFile						*
*This takes the array and has a ref to the size of	*
*array. this reads the file and returns the length	*
*by reference.										*
*****************************************************/
void fileStuff::readFromFile(string* arrayOfObj, int &size)
{
	int i = 0, id = 0, sp = 0;
	int bkn = 0;
	double weight = 0;
	//uses a .perf file, this keeps user from
	//messing with the file, can be opened
	//as plain text tho.
	ifstream myfile("bag.txt");

	while (myfile >> id >> sp >> weight >> bkn)
	{
		/*arrayOfObj[i].setBagId(id);
		arrayOfObj[i].setInvSpaces(sp);
		arrayOfObj[i].setInvMaxWeight(weight);
		arrayOfObj[i].setStateOfDecay(bkn);*/
		i++;
	}
	size = i;
}
/****************************************************
*function def for shouldLoad						*
* this reads the file and returns the contents of	*
*the file divided by four. becuase my object holds	*
*four types. if the file has at least three things	*
*in it, the program will load the file first		*
*****************************************************/
int fileStuff::shouldLoad()
{
	int i = 0, temp = 0;
	//uses a .perf file, this keeps user from
	//messing with the file, can be opened
	//as plain text tho.
	ifstream myfile("bag.txt");
	while (myfile >> temp)
	{
		i++;
	}
	return i / 4;
}