#ifndef PERSON_H 
#define PERSON_H 
#include <string>
#include <iostream>

using namespace std;

/*
*this is a basic person class
*holds info about a person
*/
class person
{
protected:
	string fName;
	string lName;
	int transID;
public:
	person();
	void setFName(string toSet);
	string getFName();
	void setLName(string toSet);
	string getLName();
	void setTransID(int toSet);
	//overloading of < 
	bool operator< (const person& toTest);
	//overloading of ==
	bool operator== (const person& isEql);
	int getTransID();

	//overloading for the << to cout the obj
	friend ostream &operator<<(ostream &output, person &D)
	{
		output.clear();
		output << "    " << D.fName << "     " << D.lName << "  " << D.transID;
		return output;
	}
};

#endif 
