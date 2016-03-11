
#include "gradDataClass.h"

#include<string> 
using namespace std; 


	//gets, returns the vairable the user needs
	string gradDataClass::getCollege()
	{
		return college;
	}
	string gradDataClass::getLName()
	{
		return LName;
	}
	string gradDataClass::getFName()
	{
		return FName;
	}
	string gradDataClass::getMiddleA()
	{
		return middleA;
	}
	string gradDataClass::getDegree()
	{
		return degree;
	}
	string gradDataClass::getDate()
	{
		return date;
	}
	string gradDataClass::getMonth()
	{
		return month;
	}
	string gradDataClass::getDay()
	{
		return day;
	}
	string gradDataClass::getYear()
	{
		return year;
	}
	//sets, sets the varible to a user specified varible.
	void gradDataClass::setCollege(string collegeTemp)
	{
		college = collegeTemp;
	}
	void gradDataClass::setLName(string LNameTemp)
	{
		LName = LNameTemp;
	}
	void gradDataClass::setFName(string FNameTemp)
	{
		FName = FNameTemp;
	}
	void gradDataClass::setMiddleA(string middleATemp)
	{
		middleA = middleATemp;
	}
	void gradDataClass::setDegree(string degreeTemp)
	{
		degree = degreeTemp;
	}
	void gradDataClass::setDate(string dateTemp)
	{
		date = dateTemp;
	}
	void gradDataClass::setMonth(string monthTemp)
	{
		month = monthTemp;
	}
	void gradDataClass::setDay(string dayTemp)
	{
		day = dayTemp;
	}
	void gradDataClass::setYear(string yearTemp)
	{
		year = yearTemp;
	}