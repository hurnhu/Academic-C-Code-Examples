#ifndef GRAD_DATA_CLASS_H
#define GRAD_DATA_CLASS_H



#include<string> 
using namespace std; 
/********************************
*class gradDataClass deff		*
*this class hold information	*
*about a diploma				*
*********************************/
class gradDataClass
{

private:
	string college;
	string LName;
	string FName;
	string middleA;
	string degree;
	string date;
	string month;
	string day;
	string year;
public:

	//gets, returns the vairable the user needs
	string getCollege();
	string getLName();
	string getFName();
	string getMiddleA();
	string getDegree();
	string getDate();
	string getMonth();
	string getDay();
	string getYear();

	//sets, sets the varible to a user specified varible.
	void setCollege(string college);
	void setLName(string LName);
	void setFName(string FName);
	void setMiddleA(string middleA);
	void setDegree(string degree);
	void setDate(string date);
	void setMonth(string month);
	void setDay(string day);
	void setYear(string year);
};

#endif 
