#pragma once
#include <string>
#include <ostream>
#include <iostream>


using namespace std;

/*
*problem class
*this class will hold information for one help
*desk problem
*/
class problem
{
public:
	problem();//constructor
private:
	int problemCode;
	int criticality;
	string Date;
	string desc;
	string lName;
	string fName;
	//--------------------------------
	//i have a bug or in my code
	//but every other item is blank
	//couldnt find the bug, but its the reason
	//why these are 54 not 27
	//--------------------------------
	int probCodeArray[54];//holds the problem code
	string probCodeDiscArray[54];//holds the discription for the problem code
public:
	void setProbCode(int toSet);//set
	int getProbCode();//get
	void setCriticality(int toSet);//set
	int getCriticality();//get
	void setDate(string toSet);//set
	string getDate();//get
	void setdesc(string toSet);//set
	string getConcat();//get
	string getLName();//get
	string getFName();//get
	void setFName(string toSet);//set
	void setLName(string toSet);//set
	bool operator< (const problem& toTest);//overloading of <           
	bool operator== (const problem& isEql);//overloading of ==
	bool operator!= (const problem& isEql);//overloading of !=
	void popArray();//populateing problem code array
	void addDisc();//add decription for each problem


	/*
	*extending (friend of the class) of <<
	*this one through me for a loop, but with some googling i got it!
	*i pass in the stream? and then the object to print
	*then useing the stream i pass in i output how the object should
	*be printted with cout. 
	*/
	friend ostream &operator<<(ostream &output, problem &D)
	{
		output.clear();
		output << "    " << D.criticality << "     " << D.Date << "  " << D.fName << " " << D.lName << "  " << D.desc;
		return output;
	}
};

