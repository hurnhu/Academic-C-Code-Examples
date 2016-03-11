#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "person.h"
using namespace std;

/*
*this is a class to hold information about an
*amazon transction. it extends person so it 
*also holds the info for the person that made
*this transction
*/
class amazonTrans : public person
{

private:
	int custID;
	double transactionAmount;
	string date;
public:
	amazonTrans();
	void setCustomerID(int toSet);
	int getCustomerID();
	void setTransactionAmount(double toSet);
	double getTransactionAmount();
	void setDate(string toSet);
	//overloading of <        
	bool operator< (const amazonTrans& toTest);
	//overloading of ==
	bool operator== (const amazonTrans& isEql);
	string getDate();

	//overloading for the << so i can cout my obj
	friend ostream &operator<<(ostream &output, amazonTrans &D)
	{
		output.clear();
		output << D.fName << " " << D.lName << "(Customer " << D.custID << ")" << "\n"
			<< D.date << "\n"
			<< "$" << setprecision(2) << fixed << D.transactionAmount << "(Tax $" << D.transactionAmount*.06 << ")";

		return output;
	}
};

