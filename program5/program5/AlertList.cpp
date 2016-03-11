#include<string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "AlertList.h"
using namespace std;



	/********************************************//**
	* **NOTE**
	* everything that has been clearly defined
	*through comments in the header will not be
	*redifined here. but some functions will have 
	*a little extra if they do something either 
	*hard to follow, or just need to clear them
	*up
	***********************************************/


	/********************************************//**
	*getFileSize loops throught the file,
	*counts and counts the lines in the file
	*@return [out] - returns the number of lines
	***********************************************/

int AlertList::getFileSize()
{
	int i = 0;
	ifstream inFile("alerts.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	//priming read
	getline(inFile, inputLine);
	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read
		i++;
	}
	return i;
}

	/********************************************//**
	*populates the list of Alert objects
	*from the alert file.
	***********************************************/
void AlertList::popList()
{
	int size = getFileSize(), i = 0, q = 0;
	ifstream inFile("alerts.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}
	//priming read

	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read

		stringstream iss(inputLine);
		//loop through looking for the comma and splitting the data
		while (getline(iss, inputLine, ','))
		{
			if (q == 0)
			{
				list[i].popFips(inputLine);
			}
			else if (q == 1)
			{
				list[i].setdateTimeString(inputLine);
				list[i].parseDateTime(0);
			}
			else if (q == 2)
			{
				list[i].setdateTimeString(inputLine);
				list[i].parseDateTime(1);
			}
			else if (q == 3)
			{
				list[i].setCode(inputLine);
				list[i].parseCode();
			}
			q++;
		}
		q = 0;
		i++;
	}
}

void AlertList::writeList()
{
	int size = getFileSize();
	for (int i = 0; i < size; i++)
	{
		list[i].writeAlert();
		system("pause");
	}
}

void AlertList::writeSortedListByFips()
{
	quickSort(list, 0, 6);
	int size = getFileSize();
	for (int i = 0; i < size + 1; i++)
	{
		list[i].writeAlert();
		system("pause");
	}
}

/**
* Quicksort, taken from the internet, modified by
*Michael LaPan to sort an array of objects by the
*fips code object in the array object.
* @param a - The array to be sorted.
* @param first - The start of the sequence to be sorted.
* @param last - The end of the sequence to be sorted.
*/
void AlertList::quickSort(Alert a[], int first, int last)
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(a, first, last);
		quickSort(a, first, pivotElement - 1);
		quickSort(a, pivotElement + 1, last);
	}
}

/**
* Find and return the index of pivot element.
* @param a - The array.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element
*/
int AlertList::pivot(Alert a[], int first, int last)
{
	int  p = first;
	int pivotElement = a[first].getfips().fipsToInt();
	for (int i = first + 1; i <= last; i++)
	{
		if (a[i].getfips().fipsToInt() <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}

	swap(a[p], a[first]);

	return p;
}

/**
* Swap the parameters.
* @param a - The first parameter.
* @param b - The second parameter.
*/
void AlertList::swap(Alert& a, Alert& b)
{
	Alert temp = a;
	a = b;
	b = temp;
}



void AlertList::findFips(string FIPS)
{
	Alert t;
	t.searchFipsCode(FIPS);
	cout << "county: " << t.getfips().getCounty() << endl
		<< "FIPS code: " << t.getfips().getFipsCode() << endl
		<< "State: " << t.getfips().getState() << endl
		<< "Population: " << t.getPop() << endl;
}