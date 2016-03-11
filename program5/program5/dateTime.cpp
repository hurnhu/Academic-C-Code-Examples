#include "dateTime.h";
#include <iostream>
#include <string>

	/********************************************//**
	* **NOTE**
	* everything that has been clearly defined
	*through comments in the header will not be
	*redifined here. but some functions will have 
	*a little extra if they do something either 
	*hard to follow, or just need to clear them
	*up
	***********************************************/

int dateTime::getMonth()
{
	return month;
}
int dateTime::getDay()
{
	return day;
}
int dateTime::getYear()
{
	return year;
}
int dateTime::getHr()
{
	return hr;
}
int dateTime::getMin()
{
	return min;
}

string dateTime::getTimeP()
{
	parseTime();
	return timeP;
}
string dateTime::getMonthP()
{
	parseMonth();
	return monthP;
}
void dateTime::setMonth(int toSet)
{
	month = toSet;
}
void dateTime::setDay(int toSet)
{
	day = toSet;
}
void dateTime::SetYear(int toSet)
{
	year = toSet;
}
void dateTime::setHr(int toSet)
{
	hr = toSet;
}
void dateTime::setMin(int toSet)
{
	min = toSet;
}
	/********************************************//**
	*month var goes into a switch, and when apporaprate
	*case is found monthP is set to the new worded month
	***********************************************/
void dateTime::parseMonth()
{
	switch (month)
	{
	case 1:
		monthP = "January ";
		break;
	case 2:
		monthP = "February";
		break;
	case 3:
		monthP = "March";
		break;
	case 4:
		monthP = "April";
		break;
	case 5:
		monthP = "May";
		break;
	case 6:
		monthP = "June";
		break;
	case 7:
		monthP = "July";
		break;
	case 8:
		monthP = "August";
		break;
	case 9:
		monthP = "September";
		break;
	case 10:
		monthP = "October";
		break;
	case 11:
		monthP = "November";
		break;
	case 12:
		monthP = "December";
		break;
	default:
		break;
	}
}
	/********************************************//**
	*concatanates the parsed hour, ":" , minutes, and 
	*am or pm. if mins are 0, addes one zero to the mins
	*string changing it from 0 to 00. to convert form 
	military time to normal, i just minus 12.
	***********************************************/
void dateTime::parseTime()
{
	string temp;
	if (hr <= 12)
	{
		if (min == 0)
		{
			temp = to_string(min) + "0";
		}
		if (hr == 0)
		{
			timeP = to_string(12) + ":" + temp + " AM";
		}
		else
		{
			timeP = to_string(hr) + ":" + temp + " AM";
		}
	}
	else
	{
		if (min == 0)
		{
			temp = to_string(min) + "0";
			timeP = to_string((hr - 12)) + ":" + temp + " PM";
		}
		else
		{
			timeP = to_string((hr - 12)) + ":" + to_string(min) + " PM";
		}
	}
}