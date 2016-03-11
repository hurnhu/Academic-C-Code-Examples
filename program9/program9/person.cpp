#include "person.h"


person::person()
{
	transID = 0;
}

//tests to see if lesser. lesser people have
//a lesser trans id
bool person::operator< (const person& toTest)
{
	if (toTest.transID < transID)
	{
		return true;
	}
	return false;
}

//comparing person to person
//the same person has the same trans id
bool person::operator== (const person& isEql)
{
	if (isEql.transID == transID)
	{
		return true;
	}
	return false;
}

void person::setFName(string toSet)
{
	fName = toSet;
}


string person::getFName()
{
	return fName;
}


void person::setLName(string toSet)
{
	lName = toSet;
}


string person::getLName()
{
	return lName;
}


void person::setTransID(int toSet)
{
	transID = toSet;
}


int person::getTransID()
{
	return transID;
}
