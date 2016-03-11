#include "amazonTrans.h"


amazonTrans::amazonTrans()
{
	custID = 0;
	transactionAmount = 0.00;
}


void amazonTrans::setCustomerID(int toSet)
{
	custID = toSet;
}


int amazonTrans::getCustomerID()
{
	return custID;
}


void amazonTrans::setTransactionAmount(double toSet)
{
	transactionAmount = toSet;
}


double amazonTrans::getTransactionAmount()
{
	return transactionAmount;
}


void amazonTrans::setDate(string toSet)
{
	date = toSet;
}


string amazonTrans::getDate()
{
	return date;
}


//overloading of ==
//if obj passed in equals this return true
bool amazonTrans::operator== (const amazonTrans& isEql)
{
	//everything must equal this
	cout << isEql.custID << " " << custID << " " << isEql.date << " " << date << " " << endl;
	if (isEql.custID == custID)
	{
		//if (isEql.date == date)
		//{
		//	cout << "is eql" << endl;
			return true;
		//}

	}
	return false;
}

//overloading of the < operator
//if criticality of obj getting passed in is
//>then this criticality then return true
bool amazonTrans::operator< (const amazonTrans& toTest)
{
	if (toTest.custID == custID)
	{
		if (toTest.date > date)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (toTest.custID > custID)
	{
		return true;
	}
	else
	{
		return false;
	}

}