#include "problem.h"
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;

//constructor
problem::problem()
{
	problemCode = 0;//set to 0
	criticality = 0;// set to 0
	popArray();//read the file into array
}

//overloading of ==
//if obj passed in equals this return true
bool problem::operator== (const problem& isEql)
{
	//everything must equal this
	if (isEql.criticality == criticality && isEql.Date == Date
		&& isEql.fName == fName && isEql.lName == lName
		&& isEql.problemCode == problemCode)
	{
		return true;
	}
	return false;
}

//adddisc
//adds the discription for each problem code
void problem::addDisc()
{
	//loop through array looking for correct problem code
	for (size_t i = 0; i < 54; i++)
	{
		if (probCodeArray[i] == problemCode)
		{
			desc = probCodeDiscArray[i + 1];
		}
	}
}

//reads everything from the file into the array
void problem::popArray()
{
	int n = 0;
	int t = 0;
	string toParse;
	ifstream wordFile2("problemlist.txt");

	//if file not found
	if (wordFile2.fail())
	{
		cout << "Problem opening document file";
		exit(-1);
	}

	// Build list of words in document 
	getline(wordFile2, toParse);      // Get first word 
	while (!wordFile2.eof())
	{
		stringstream ss(toParse);
		string s;

		//split at -
		while (getline(ss, s, '-')) {
			if (t == 0)
			{
				probCodeArray[n] = atoi(s.c_str());
				t++;
			}
			else if (t == 1)
			{
				probCodeDiscArray[n] = s;
				t = 0;
			}
			n++;
		}
		getline(wordFile2, toParse);      // Get second word 
	}
	wordFile2.close();
}
//overloading of !=
//if obj passed in does not equals any part of
//this. return true
bool problem::operator!= (const problem& isEql)
{
	if (isEql.criticality != criticality || isEql.Date != Date
		|| isEql.fName != fName || isEql.lName != lName
		|| isEql.problemCode != problemCode)
	{
		return true;
	}
	return false;
}

//overloading of the < operator
//if criticality of obj getting passed in is
//>then this criticality then return true
bool problem::operator< (const problem& toTest)
{
	if (toTest.criticality == criticality)
	{
		if (toTest.Date > Date)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{

		if (toTest.criticality >= criticality)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

//set problem code
void problem::setProbCode(int toSet)
{
	problemCode = toSet;
	addDisc();
}

//return problemcode
int problem::getProbCode()
{
	return problemCode;
}

//set criticality
void problem::setCriticality(int toSet)
{
	criticality = toSet;
}

//get criticality
int problem::getCriticality()
{
	return criticality;
}

//set date
void problem::setDate(string toSet)
{
	Date = toSet;
}

//return date
string problem::getDate()
{
	return Date;
}

//set desc
void problem::setdesc(string toSet)
{
	desc = toSet;
}

//return desc
string problem::getConcat()
{
	return desc;
}

//return last name
string problem::getLName()
{
	return lName;
}

//return first name
string problem::getFName()
{
	return fName;

}

//set first name
void problem::setFName(string toSet)
{
	fName = toSet;
}

//set last name
void problem::setLName(string toSet)
{
	lName = toSet;
}