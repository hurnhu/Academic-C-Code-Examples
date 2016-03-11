#include<string>
#include <time.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cmath>
#include <fstream>
#include "Alert.h"

	/********************************************//**
	* **NOTE**
	* everything that has been clearly defined
	*through comments in the header will not be
	*redifined here. but some functions will have 
	*a little extra if they do something either 
	*hard to follow, or just need to clear them
	*up
	***********************************************/
string Alert::getdateTimeString()
{
	return dateTimeString;
}

fips Alert::getfips()
{
	return fipsCode;
}
dateTime Alert::getParsedDateTime()
{
	return dateTimeS;
}
dateTime Alert::getDateTimeS()
{
	return dateTimeS;
}
dateTime Alert::getDateTimeE()
{
	return dateTimeE;
}
string Alert::getCode()
{
	return code;
}
string  Alert::getPop()
{
	return pop;
}

void Alert::setDateTimeS(dateTime toSet)
{
	dateTimeS = toSet;
}
void Alert::setDateTimeE(dateTime toSet)
{
	dateTimeE = toSet;
}
void Alert::setdateTimeString(string toSet)
{
	dateTimeString = toSet;
}


void Alert::setParsedDateTime(dateTime toSet)
{
	dateTimeS = toSet;
}
void Alert::setCode(string toSet)
{
	code = toSet;
}
void Alert::setPop(string toSet)
{
	pop = toSet;
}
void Alert::writeAlert()
{
	cout << code << " for " << fipsCode.getCounty() << ", " << fipsCode.getState() << endl
		<< dateTimeS.getMonthP() << " " << dateTimeS.getDay() << ", " << dateTimeS.getTimeP()
		<< " - " << dateTimeE.getMonthP() << " " << dateTimeE.getDay() << ", " << dateTimeE.getTimeP() << endl
		<< "Population Impact: " << pop << endl;
}
	/********************************************//**
	*parse date time parses out a single string
	*that contains the year,month,day,milltime in
	*that order into something readable by humans.
	*how i do it is i take the number, divid it by
	*a decimal. EX(201502121300 turns into 2015.02121300).
	*i then truncate off the decimal. and boom i have
	*the year. next i take that year, times it by a number.
	*(2015.00000000 * 100000000 = 201500000000). i then
	*take that and minus that from the start time. then
	*i just repete the process again and again untill,
	*everything is parsed out.
	***********************************************/
void Alert::parseDateTime(int se)
{
	stringstream ss;

	double m = 0, d = 0, tm = 0, th = 0, y = 0;
	int temp;
	double dateTimeStart = 0.0;
	ss << dateTimeString;
	ss >> dateTimeStart;

	y = trunc(dateTimeStart * .00000001);

	dateTimeStart -= y * 100000000;
	m = trunc(dateTimeStart * .000001);

	dateTimeStart -= m * 1000000;
	d = trunc(dateTimeStart * .0001);

	dateTimeStart -= d * 10000;
	th = trunc(dateTimeStart * .01);

	dateTimeStart -= th * 100;
	tm = trunc(dateTimeStart);
	if (se == 0)
	{
		dateTimeS.setDay(d);
		dateTimeS.setMonth(m);
		dateTimeS.SetYear(y);
		dateTimeS.setHr(th);
		dateTimeS.setMin(tm);
		dateTimeS.parseMonth();
		dateTimeS.parseTime();
	}
	else if (1)
	{
		dateTimeE.setDay(d);
		dateTimeE.setMonth(m);
		dateTimeE.SetYear(y);
		dateTimeE.setHr(th);
		dateTimeE.setMin(tm);
		dateTimeE.parseMonth();
		dateTimeE.parseTime();
	}

	ss.clear();
}
	/********************************************//**
	*parses WWS or color code in to the alert
	*i loop through the file either looking for my color
	*or looking for the code (with out the_).
	*once found excract data after the code, and 
	*make my alert sentance from it.
	***********************************************/
void Alert::parseCode()
{
	int  i = 0, q = 0;
	ifstream inFile("warningList.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	//priming read
	string nonColor, isColor, temp, WAY;
	//if not a color parse the warning prfix
	if (code != "RED" && code != "ORANGE"
		&& code != "YELLOW" && code != "BLUE"
		&& code != "GREEN")
	{
		temp = code[0];
		code.erase(0, 1);
		if (temp == "W")
		{
			WAY = "Warning";
		}
		else if (temp == "A")
		{
			WAY = "Watch";
		}
		else if (temp == "Y")
		{
			WAY = "Advisory";
		}
	}

	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read
		stringstream iss(inputLine);

		while (getline(iss, inputLine, '_'))
		{
			//substr is used to skip either the _ or the color and
			//get the data behind it.
			 string::size_type pos = inputLine.find(code);
			if (pos !=  string::npos)
			{
				if (code == "RED" || code == "ORANGE"
					|| code == "YELLOW" || code == "BLUE"
					|| code == "GREEN")
				{
					isColor = inputLine.substr(pos + 8);
				}
				else
				{
					nonColor = inputLine.substr(pos + 3);
				}
			}
		}
		i++;
	}
	inFile.close();
	if (isColor.empty())
	{
		if (WAY.empty())
		{
			code = nonColor;
		}
		else
		{
			code = (nonColor + " " + WAY);
		}
	}
	else
	{
		code = isColor;
	}
}
	/********************************************//**
	*populates the fips code object looking for input
	*as criteria
	***********************************************/
void Alert::popFips(string toParse)
{
	ifstream inFile("fipsCounty.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	//priming read
	string countyF, stateF, fipsCodeF;

	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read
		stringstream iss(inputLine);
		if (inputLine.find(toParse) != string::npos)
		{
			int i = 0;
			inputLine = inputLine.erase(0, 6);
			while (getline(iss, inputLine, ','))
			{
				if (i == 0)
				{
					countyF = inputLine.erase(0, 6);
				}
				else if (i == 1)
				{
					stateF = inputLine;
				}

				i++;
			}
		}
	}
	fipsCode.setCounty(countyF);
	fipsCode.setFipsCode(toParse);
	fipsCode.setState(stateF);
	inFile.close();
	getPopByFips();
}
	/********************************************//**
	*gets the population by useing the fips code
	***********************************************/
void Alert::getPopByFips()
{
	ifstream inFile("popcounty.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}


	while (!inFile.eof())
	{
		getline(inFile, inputLine); //read
		stringstream iss(inputLine);
		//loop through file remove ',' and find pop linked with fips code
		if (inputLine.find(fipsCode.getFipsCode()) != string::npos)
		{
			int i = 0;
			while (getline(iss, inputLine, ','))
			{
				if (i == 1)
				{
					pop = inputLine;
				}
				i++;
			}
		}
	}
	inFile.close();
}
	/********************************************//**
	*searches for a fips code specified by the user
	*loops through file removeing ',' and looking for
	*correct fips code
	***********************************************/
void Alert::searchFipsCode(string toFind)
{
	int   q = 0;
	ifstream inFile("fipsCounty.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	//priming read
	string countyF, stateF;
	bool found = false;

	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read
		stringstream iss(inputLine);
		if (inputLine.find(toFind) != string::npos)
		{
			found = true;
			int i = 0;
			inputLine = inputLine.erase(0, 6);
			while (getline(iss, inputLine, ','))
			{
				if (i == 0)
				{
					countyF = inputLine.erase(0, 6);
				}
				else if (i == 1)
				{
					stateF = inputLine;
				}

				i++;
			}
		}
	}
	if (found)
	{
		fipsCode.setCounty(countyF);
		fipsCode.setFipsCode(toFind);
		fipsCode.setState(stateF);
		getPopByFips();
	}
	inFile.close();
}