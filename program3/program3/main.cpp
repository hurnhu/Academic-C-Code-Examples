// This program demonstrates tokenizing comma-delimited data 
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
#include <iomanip>
#include "gradDataClass.h"
#include "StringTokenizer.h"

using namespace std;


void processLine(string inputLine, gradDataClass objArray[], int place);


void parsedDegree(gradDataClass objArray[], int place);



void parseMonth(gradDataClass objArray[], int place);


void parseDay(gradDataClass objArray[], int place);


void parseYear(gradDataClass objArray[], int place);

void delimDate(char dlim, gradDataClass objArray[], int place);


int stringToInt(string toConvert);

void displayDiploma(gradDataClass objArray[], int place);

//enum for each type of degree
enum degree_code
{
	Associate_of_Arts,
	Associate_of_Science,
	Associate_of_Applied_Science,
	Bachelor_of_Arts,
	Bachelor_of_Science
};

degree_code enumDegree(string const& inString);



const int MAX = 50;

int main()
{
	string inputLine;
	int size = 0;

	gradDataClass objArray[MAX];

	ifstream inFile("gradData.txt");

	if (inFile.fail())         // Test for file existence 
	{
		cout << "Problem opening file";
		exit(-1);
	}

	//priming read
	getline(inFile, inputLine);
	while (!inFile.eof())
	{
		processLine(inputLine, objArray, size);
		getline(inFile, inputLine); //continuation read
		size++;
	}
	//loops through each in size and gets all infor for each
	//diploma, and then displays it
	for (int i = 0; i < size; i++)
	{
		delimDate('/', objArray, i);
		parseMonth(objArray, i);
		parseDay(objArray, i);
		parseYear(objArray, i);
		displayDiploma(objArray, i);
		system("pause");
	}

	return 0;
}


/********************************************************
*				displayDiploma deff						*
*displayDiploma take an array of objects and the place	*
*you want to access in the array. it then outputs		*
*a formatted diploma.. had some trouble with this		*
* so a few dont display right.							*
*********************************************************/
void displayDiploma(gradDataClass objArray[], int place)
{
	cout << setw(40) << objArray[place].getCollege() << endl;
	cout << setw(35) << fixed << "has conferred upon" << endl;
	cout << setw(26) << objArray[place].getFName() << " " 
		<< objArray[place].getMiddleA()
		<< " " << objArray[place].getLName() << endl;
	cout << setw(33) << "the degree of" << endl;
	cout << setw(28) << objArray[place].getDegree() << endl;
	cout << setw(50) << "with all right and privilages thereto pertaining" << endl;
	cout << setw(18) << "on this " << objArray[place].getDay() << " of " 
		<< objArray[place].getMonth() << endl;
	cout << setw(20) << "in the year " << objArray[place].getYear() 
		<< endl << endl << endl;
}


/********************************************************
*				parseMonth								*
*parse month takes an array of objects, and the place	*
*in the array you want to be parsed. it then converts	*
*the month in number for into a month in word form		*
*********************************************************/
void parseMonth(gradDataClass objArray[], int place)
{
	int tempM = stringToInt(objArray[place].getMonth());
	switch (tempM)
	{

	case 1:
		objArray[place].setMonth("January");
		break;
	case 2:
		objArray[place].setMonth("February");
		break;
	case 3:
		objArray[place].setMonth("March");
		break;
	case 4:
		objArray[place].setMonth("April");
		break;
	case 5:
		objArray[place].setMonth("May");
		break;
	case 6:
		objArray[place].setMonth("June");
		break;
	case 7:
		objArray[place].setMonth("July");
		break;
	case 8:
		objArray[place].setMonth("January");
		break;
	case 9:
		objArray[place].setMonth("August");
		break;
	case 10:
		objArray[place].setMonth("September");
		break;
	case 11:
		objArray[place].setMonth("October");
		break;
	case 12:
		objArray[place].setMonth("December");
		break;
	default:
		break;
	}
}
/********************************************************
*				parseday								*
*parse day takes an array of objects, and the place		*
*in the array you want to be parsed. it then converts the*
*day in number form into a day in word form				*
*after thinking about it loading all days from a file	*
*would have been better, just not enought time to		*
*implement												*
*********************************************************/

void parseDay(gradDataClass objArray[], int place)
{
	string lThenTwnty[19] = { "first", "second", "third", "fourth", "fifth", "sixth", "seventh",
		"eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth",
		"fourteenth", "fifteenth", "sixteenth", "seventeenth", "eighteenth",
		"nineteenth" };
	string gThenTwnty[4] = { "twentieth", "twenty-", "thirtieth", "thirty-" };
	int tempD = stringToInt(objArray[place].getDay());
	switch (tempD)
	{

	case 1:
		objArray[place].setDay(lThenTwnty[0]);
		break;
	case 2:
		objArray[place].setDay(lThenTwnty[1]);
		break;
	case 3:
		objArray[place].setDay(lThenTwnty[2]);
		break;
	case 4:
		objArray[place].setDay(lThenTwnty[3]);
		break;
	case 5:
		objArray[place].setDay(lThenTwnty[4]);
		break;
	case 6:
		objArray[place].setDay(lThenTwnty[5]);
		break;
	case 7:
		objArray[place].setDay(lThenTwnty[6]);
		break;
	case 8:
		objArray[place].setDay(lThenTwnty[7]);
		break;
	case 9:
		objArray[place].setDay(lThenTwnty[8]);
		break;
	case 10:
		objArray[place].setDay(lThenTwnty[9]);
		break;
	case 11:
		objArray[place].setDay(lThenTwnty[10]);
		break;
	case 12:
		objArray[place].setDay(lThenTwnty[11]);
		break;
	case 13:
		objArray[place].setDay(lThenTwnty[12]);
		break;
	case 14:
		objArray[place].setDay(lThenTwnty[13]);
		break;
	case 15:
		objArray[place].setDay(lThenTwnty[14]);
		break;
	case 16:
		objArray[place].setDay(lThenTwnty[15]);
		break;
	case 17:
		objArray[place].setDay(lThenTwnty[16]);
		break;
	case 18:
		objArray[place].setDay(lThenTwnty[17]);
		break;
	case 19:
		objArray[place].setDay(lThenTwnty[18]);
		break;
	case 20:
		objArray[place].setDay(gThenTwnty[0]);
		break;
	case 21:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[0]);
		break;
	case 22:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[1]);
		break;
	case 23:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[2]);
		break;
	case 24:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[3]);
		break;
	case 25:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[4]);
		break;
	case 26:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[5]);
		break;
	case 27:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[6]);
		break;
	case 28:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[7]);
		break;
	case 29:
		objArray[place].setDay(gThenTwnty[1] + lThenTwnty[8]);
		break;
	case 30:
		objArray[place].setDay(gThenTwnty[2]);
		break;
	case 31:
		objArray[place].setDay(gThenTwnty[3] + lThenTwnty[0]);
		break;
	default:
		break;
	}
}

/********************************************************
*				parseyear								*
*parse year takes an array of objects, and the place	*
*in the array you want to be parsed. it then converts	*
*the year in number form into a year in word form		*
*after thinking about it loading all days from a file	*
*would have been better, just not enought time to		*
*implement												*
*********************************************************/
void parseYear(gradDataClass objArray[], int place)
{
	string lThenTwnty[19] = { "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", " ten", " eleven", " twelve", " thirteen", " fourteen", " fifteen",
		" sixteen", " seventeen", " eighteen", "nineteen" };
	string gThenTwnty[8] = { "two-thousand", "twenty", "thirty", "forty", "fifty", };
	int tempY = stringToInt(objArray[place].getYear());

	switch (tempY)
	{

	case 1:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[0]);
		break;
	case 2:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[1]);
		break;
	case 3:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[2]);
		break;
	case 4:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[3]);
		break;
	case 5:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[4]);
		break;
	case 6:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[5]);
		break;
	case 7:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[6]);
		break;
	case 8:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[7]);
		break;
	case 9:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[8]);
		break;
	case 10:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[9]);
		break;
	case 11:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[10]);
		break;
	case 12:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[11]);
		break;
	case 13:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[12]);
		break;
	case 14:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[13]);
		break;
	case 15:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[14]);
		break;
	case 16:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[15]);
		break;
	case 17:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[16]);
		break;
	case 18:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[17]);
		break;
	case 19:
		objArray[place].setYear(gThenTwnty[0] + lThenTwnty[18]);
		break;
	case 20:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[0]);
		break;
	case 21:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[0]);
		break;
	case 22:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[1]);
		break;
	case 23:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[2]);
		break;
	case 24:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[3]);
		break;
	case 25:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[4]);
		break;
	case 26:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[5]);
		break;
	case 27:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[6]);
		break;
	case 28:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[7]);
		break;
	case 29:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[1] + lThenTwnty[8]);
		break;
	case 30:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2]);
		break;
	case 31:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[0]);
		break;
	case 32:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[1]);
		break;
	case 33:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[2]);
		break;
	case 34:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[3]);
		break;
	case 35:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[4]);
		break;
	case 36:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[5]);
		break;
	case 37:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[6]);
		break;
	case 38:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[7]);
		break;
	case 39:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[2] + lThenTwnty[8]);
		break;
	case 40:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3]);
		break;
	case 41:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[0]);
		break;
	case 42:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[1]);
		break;
	case 43:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[2]);
		break;
	case 44:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[3]);
		break;
	case 45:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[4]);
		break;
	case 46:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[5]);
		break;
	case 47:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[6]);
		break;
	case 48:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[7]);
		break;
	case 49:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[3] + lThenTwnty[8]);
		break;
	case 50:
		objArray[place].setYear(gThenTwnty[0] + gThenTwnty[4]);
		break;

	default:
		break;
	}
}

/********************************************************
*				parseDegree								*
*parse degree takes an array of objects and the place	*
*in the array you want to be parsed. it then convers	*
*the acrocrymn to the full name							*
*********************************************************/

void parsedDegree(gradDataClass objArray[], int place)
{

	string temp = objArray[place].getDegree();
	switch (enumDegree(temp)){
	case Associate_of_Arts:
		objArray[place].setDegree("Associate of Arts");
		break;
	case Associate_of_Science:
		objArray[place].setDegree("Associate of Science");

		break;
	case Associate_of_Applied_Science:
		objArray[place].setDegree("Associate of Applied Science");

		break;
	case Bachelor_of_Arts:
		objArray[place].setDegree("Bachelor of Arts");

		break;
	case Bachelor_of_Science:
		objArray[place].setDegree("Bachelor of Science");
		break;
	default:
		break;
	}
}

/********************************************************
*				enumDegree								*
*converts the input string (a degree) into the assoatied*
*enum to be put into the switch							*
*********************************************************/
degree_code enumDegree(string const& inString)
{
	if (inString == "A.A") return Associate_of_Arts;
	if (inString == "A.S") return Associate_of_Science;
	if (inString == "A.A.S") return Associate_of_Applied_Science;
	if (inString == "B.A") return Bachelor_of_Arts;
	if (inString == "B.S") return Bachelor_of_Science;
}

/********************************************************
*				stringToInt								*
*changes a string to an integer be useing a string stream*
*********************************************************/
int stringToInt(string toConvert)
{
	int sTi = 0;
	stringstream tempsstring;
	tempsstring << toConvert;
	tempsstring >> sTi;
	return sTi;
}

/********************************************************
*				delimDate								*
*takes the delimiter to look for, the array of objects	*
* and the place to look at. it then splits out the month*
*, day and, year fomr a date							*
*********************************************************/
void delimDate(char dlim, gradDataClass objArray[], int place)
{
	string stringToDelim;
	StringTokenizer tokenizer(dlim);
	tokenizer.setLine(objArray[place].getDate());

	stringToDelim = tokenizer.getStringToken();
	objArray[place].setMonth(stringToDelim);
	stringToDelim = tokenizer.getStringToken();
	objArray[place].setDay(stringToDelim);
	stringToDelim = tokenizer.getStringToken();
	objArray[place].setYear(stringToDelim);
}


/********************************************************
*				processLine								*
*this function parses a coma seperated line, and places	*
*each item in to the class. did this the long way by not*
*useing the stringTokenizer class provided in example,	*
*was haveing some trouble getting the class to work		*
*untill today											*
*********************************************************/

void processLine(string inputLine, gradDataClass objArray[], int place)
{

	string college, lastName, firstName, middleInital, degree, date;

	// Variables to mark string positions 
	int  len, start, nextComma;

	// Get first string 
	nextComma = inputLine.find(',');             // Mark 1st comma location 
	len = nextComma - 0;                         // Calculate length of substring 
	college = inputLine.substr(0, len);          // Get zip code as string 
	start = nextComma + 1;                       // Mark position after this comma 

	// Get second 
	nextComma = inputLine.find(',', start);     // Mark 2nd comma location 
	len = nextComma - start;                     // Calculate length of substring 
	lastName = inputLine.substr(start, len);   // Get numerical info as string 
	start = nextComma + 1;                       // Mark position after this comma 

	// Get third string 
	nextComma = inputLine.find(',', start);      // Mark next comma location 
	len = nextComma - start;                     // Calculate length of substring 
	firstName = inputLine.substr(start, len);      // Get string 
	start = nextComma + 1;                       // Mark position after this comma 

	// Get fourth string 
	nextComma = inputLine.find(',', start);      // Mark next comma location 
	len = nextComma - start;                     // Calculate length of substring 
	middleInital = inputLine.substr(start, len);      // Get string 
	start = nextComma + 1;                       // Mark position after this comma 

	// Get fifth string 
	nextComma = inputLine.find(',', start);      // Mark next comma location 
	len = nextComma - start;                     // Calculate length of substring 
	degree = inputLine.substr(start, len);      // Get string 
	start = nextComma + 1;                       // Mark position after this comma 

	// Get sixth string 
	nextComma = inputLine.find(',', start);      // Mark next comma location 
	len = nextComma - start;                     // Calculate length of substring 
	date = inputLine.substr(start, len);      // Get string 
	start = nextComma + 1;                       // Mark position after this comma 

	objArray[place].setCollege(college);
	objArray[place].setDate(date);
	objArray[place].setDegree(degree);
	objArray[place].setFName(firstName);
	objArray[place].setLName(lastName);
	objArray[place].setMiddleA(middleInital);
}