#include <string> 
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "transcation.h"
using namespace std;


/****************************************
*function def for transcatoin			*
*this is the constructor for the class	*
*this justs sets all rows and colums to	*
*zero, and the dayArray to zeros		*
*****************************************/
transcatoin::transcatoin()
{
	row = 0;
	col = 0;
	for (int i = 0; i < 72; i++)
	{
		dayArray[i] = 0;
	}
}
/****************************************
*function def for setToParse			*
*sets the varible toParse to a string	*
*in need of parsing						*
*****************************************/
void transcatoin::setToParse(string toParseTemp)
{
	toParse = toParseTemp;
}
/****************************************
*function def for getWeekArray			*
*returns whats in the week array at user*
*specified colum and row				*
*****************************************/
string transcatoin::getWeekArray(int colt, int rowt)
{
	return weekArray[colt][rowt];
}
/****************************************
*function def for getToParse			*
*returns the string that needs to be	*
*parsed									*
*****************************************/
string transcatoin::getToParse()
{
	return toParse;
}
/****************************************
*function def for parse					*
*this method changes the input string	*
*encoded with commas, in to trans type,	*
*trans week, and trans day. it then puts*
*them in the week array.				*
*week array ex data						*
*	0	1	2							*
*0	W	2	0							*
*1	A	5	2							*
*2	P	0	1							*
*****************************************/
void transcatoin::parse()
{
	row = 0;
	string temp;
	istringstream ss(toParse);
	string token;

	while (getline(ss, token, ','))
	{
		weekArray[col][row] = token;
		row++;
	}
	col++;
	row = 0;
}
/****************************************
*function def for display				*
*this functions calculates how many		*
*transtions were made in each week. this*
*also pupulates dayarray for later user	*
*****************************************/
void transcatoin::display()
{
	int t = 3, temp = 0;

	//i had toubles with getting more than one 
	//instance of this class, so i just made this
	//class handle all of the weeks and split up 
	//the data. 

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < t; j++)
		{
			//if the week number is one parse the data into
			//appropriate place for that week. dayArray 
			//holds all data for each day for three weeks.
			//su - sat is places 0-6. each week has three
			//items of seven to store. so one week ends at
			//place 21, and week two starts from ther etc.

			if (weekArray[i][1] == "1")
			{
				temp = stringToInt(weekArray[i][2]);
				if (weekArray[i][j] == "W")
				{
					dayArray[stringToInt(weekArray[i][2])] += 1;
				}
				else if (weekArray[i][j] == "A")
				{
					dayArray[stringToInt(weekArray[i][2]) + 7] += 1;

				}
				else if (weekArray[i][j] == "P")
				{
					dayArray[stringToInt(weekArray[i][2]) + 14] += 1;
				}

			}

			if (weekArray[i][1] == "2")
			{
				if (weekArray[i][j] == "W")
				{
					dayArray[stringToInt(weekArray[i][2]) + 21] += 1;
				}
				else if (weekArray[i][j] == "A")
				{
					dayArray[stringToInt(weekArray[i][2]) + 28] += 1;
				}
				else if (weekArray[i][j] == "P")
				{
					dayArray[stringToInt(weekArray[i][2]) + 35] += 1;
				}

			}
			if (weekArray[i][1] == "3")
			{
				if (weekArray[i][j] == "W")
				{
					dayArray[stringToInt(weekArray[i][2]) + 42] += 1;
				}
				else if (weekArray[i][j] == "A")
				{
					dayArray[stringToInt(weekArray[i][2]) + 49] += 1;
				}
				else if (weekArray[i][j] == "P")
				{
					dayArray[stringToInt(weekArray[i][2]) + 56] += 1;
				}

			}

		}
	}
	//display the week header and call display methods
	int totalr = 0;
	cout << "-------------------------WEEK ONE-------------------------" << endl;
	totalr = totals(0);
	totalsCol(totalr);
	system("pause");
	cout << "-------------------------WEEK TWO-------------------------" << endl;

	totalr = totals(21);
	totalsCol(totalr);
	system("pause");
	cout << "------------------------WEEK THREE-------------------------" << endl;

	totalr = totals(42);
	totalsCol(totalr);
	system("pause");

	maxT();
	minT();

}
/****************************************
*function def for totals				*
*this function loops through dayArray	*
*and outputs the total for each			*
*type, and then overall.				*
*****************************************/
int transcatoin::totals(int start)
{
	int totalw = 0, totala = 0, totalp = 0;
	cout << setw(9) << "su" << setw(6) << "mo" << setw(5) << "tu" <<
		setw(5) << "we" << setw(5) << "th" << setw(5) << "fr" << setw(4) << "sa" <<
		setw(8) << "total" << endl;

	for (int w = 0; w < 3; w++)
	{
		if (w == 0)
		{
			cout << "WEB:   ";
			for (int q = 0; q < 7; q++)
			{
				cout << dayArray[q + start] << "  ";
				totalw += dayArray[q + start];
			}
			cout << totalw;
			cout << endl;
		}
		else if (w == 1)
		{
			cout << "APP:   ";
			for (int q = 0; q < 7; q++)
			{
				//0-6 is allocated for web, 7-13 is alocated for app etc
				cout << dayArray[q + start + 7] << "  ";
				totala += dayArray[q + start + 7];
			}
			cout << totala;
			cout << endl;
		}
		else if (w == 2)
		{
			cout << "PHONE: ";
			for (int q = 0; q < 7; q++)
			{
				cout << dayArray[q + start + 14] << "  ";
				totalp += dayArray[q + start + 14];
			}
			cout << totalp;
			cout << endl;
		}
	}
	return totala + totalp + totalw;
}
/****************************************
*function def for totalsCol				*
*this function outputs the totals for	*
*each day of the week.
*****************************************/
void transcatoin::totalsCol(int t)
{
	int  totalcarray[8] = { 0 }, itt = 0, total = 0;
	for (int o = 0; o < 7; o++)
	{

		totalcarray[o] += dayArray[0 + itt];
		totalcarray[o] += dayArray[7 + itt];
		totalcarray[o] += dayArray[14 + itt];
		itt++;

	}
	cout << "TOTAL: ";
	for (int i = 0; i < 7; i++)
	{
		cout << totalcarray[i] << "  ";
		totalcarray[i] += total;
	}
	cout << total + t;
}
/****************************************
*function def for minT					*
*minT loops through dayArray (witch		*
*contains all of the totals for every	*
*week) looking for the smallest number	*
*once found. is determinds the week,	*
*trans type, and day. through some		*
*clever math							*
*****************************************/
void transcatoin::minT()
{
	/*
	*--------------math explnation--------------
	*so the way the data in dayArray is arranged
	*makes it so 0 - 20 are the first week. (21 - 41
	*second week etc.). then with in the first week
	*(0-20) their are transcatoin types 0-6, 7-13,
	*and 14 - 20 are app, web, phone respectivly
	*and within each trans type their are seven days
	* sun-sat. 0 is sun and 6 is sat. throught the
	*use of modulus to get the remainder i can
	*get the week, trans type, and day. this info
	*is feed into a array thats holds the lowest one
	*/
	min[0] = to_string(1337);
	string testy;
	int forSwitc = 0, testtttt = 0;
	for (int i = 0; i < 56; i++)
	{
		if (dayArray[i] < stringToInt(min[0]))
		{
			testy = to_string(dayArray[i]);
			min[0] = testy;
			if (i > 3)
			{
				testtttt = i % 3;
			}
			switch (testtttt)
			{
			case 0:
				min[3] = "App";
				break;
			case 1:
				min[3] = "web";
				break;
			case 2:
				min[3] = "Phone";
				break;
			default:
				break;
			}
			if (i > 7)
			{
				forSwitc = i % 7;
			}
			switch (forSwitc)
			{
			case 0:
				min[1] = "Sunday";
				break;
			case 1:
				min[1] = "Monday";
				break;
			case 2:
				min[1] = "Tuesday";
				break;
			case 3:
				min[1] = "Wednesday";
				break;
			case 4:
				min[1] = "Thursday";
				break;
			case 5:
				min[1] = "Friday";
				break;
			case 6:
				min[1] = "Saturday";
				break;
			default:
				break;
			}
			if (i <= 21)
			{
				min[2] = "Week One";
			}
			else if (i <= 42)
			{
				min[2] = "Week Two";

			}
			else if (i > 42)
			{
				min[2] = "Week Three";

			}
		}
	}
	cout << "The min amount of purchased occured on " << min[1] << ", " << min[2]
		<< ". \nthe type was " << min[3] << " and amount is " << min[0] << endl;
}
/****************************************
*function def for intToString			*
*converts a int to a string using string*
*streams								*
*****************************************/
string intToString(int toConvert)
{
	stringstream  convert;
	convert << toConvert;
	return convert.str();
}
/****************************************
*function def for transcatoin			*
*****************************************/
void transcatoin::maxT()
{	/*
	*--------------math explnation--------------
	*so the way the data in dayArray is arranged
	*makes it so 0 - 20 are the first week. (21 - 41
	*second week etc.). then with in the first week
	*(0-20) their are transcatoin types 0-6, 7-13,
	*and 14 - 20 are app, web, phone respectivly
	*and within each trans type their are seven days
	* sun-sat. 0 is sun and 6 is sat. throught the
	*use of modulus to get the remainder i can
	*get the week, trans type, and day. this info
	*is feed into a array thats holds the higest one
	*/
	max[0] = dayArray[0];
	string testy;
	int forSwitc = 0, testtttt = 0;
	for (int i = 0; i < 56; i++)
	{
		if (dayArray[i] > stringToInt(max[0]))
		{
			testy = to_string(dayArray[i]);
			max[0] = testy;
			if (i > 3)
			{
				testtttt = i % 3;
			}
			switch (testtttt)
			{
			case 0:
				max[3] = "App";
				break;
			case 1:
				max[3] = "web";
				break;
			case 2:
				max[3] = "Phone";
				break;
			default:
				break;
			}
			if (i > 7)
			{
				forSwitc = i % 7;
			}
			switch (forSwitc)
			{
			case 0:
				max[1] = "Sunday";
				break;
			case 1:
				max[1] = "Monday";
				break;
			case 2:
				max[1] = "Tuesday";
				break;
			case 3:
				max[1] = "Wednesday";
				break;
			case 4:
				max[1] = "Thursday";
				break;
			case 5:
				max[1] = "Friday";
				break;
			case 6:
				max[1] = "Saturday";
				break;
			default:
				break;
			}
			if (i <= 21)
			{
				max[2] = "Week One";
			}
			else if (i <= 42)
			{
				max[2] = "Week Two";

			}
			else if (i > 42)
			{
				max[2] = "Week Three";

			}
		}
	}
	cout << "The max amount of purchased occured on " << max[1] << ", " << max[2]
		<< ". \nthe type was " << max[3] << " and amount is " << max[0] << endl;
}
/****************************************
*function def for stringToInt			*
*converts a string to an int using		*
*string streams							*
*****************************************/
int transcatoin::stringToInt(string toConvert)
{
	int sTi = 0;
	stringstream tempsstring;
	tempsstring << toConvert;
	tempsstring >> sTi;
	return sTi;
}
