
#include<string> 
using namespace std; 

//the class filestuff is all of my file io for arrays
//eventually ill add to this so i have a resuable
//fileio class
class fileStuff
{
private:

public:
	/****************************************************
	*function def for writeToFile						*
	*This takes the array and the curr size of the array*
	*then writes the contents of the array to the file	*
	*this does not append to the file, it writes over	*
	*every time (had some logic trouble when trying		*
	*to append)											*
	*****************************************************/
	void writeToFile(string* stringToParse, int lineNum, string fileToRead);
	/****************************************************
	*function def for readFromFile						*
	*This takes the array and has a ref to the size of	*
	*array. this reads the file and returns the length	*
	*by reference.										*
	*****************************************************/
	void readFromFile(string* stringToParse, int &size);
	/****************************************************
	*function def for shouldLoad						*
	* this reads the file and returns the contents of	*
	*the file divided by four. becuase my object holds	*
	*four types. if the file has at least three things	*
	*in it, the program will load the file first		*
	*****************************************************/
	int shouldLoad();
};
