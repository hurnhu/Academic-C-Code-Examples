//author: Michael LaPan
//project: program 4
//discription: this program reads info about purchases
//from a file, parses the data, and then totals how 
//many of each transtion type for each week their was

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "transcation.h"
using namespace std;
int main()
{
	transcatoin weak;

	string inputLine;
	int i = 0, week = 0;
	ifstream inFile("rawdata.txt");

	if (inFile.fail())         // Test for file existence 
	{
		cout << "Problem opening file";
		//exit(-1);
	}
	//priming read
	getline(inFile, inputLine);
	while (!inFile.eof())
	{
		getline(inFile, inputLine); //continuation read
		weak.setToParse(inputLine);
		weak.parse();

		i++;
	}
	weak.display();
	system("pause");
	//system("pause");
	return 0;
}

