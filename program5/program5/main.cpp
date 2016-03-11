#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "AlertList.h"
using namespace std;
/********************************************//**
*\class main
*
* fips brief description.
*         this is the main driver
*
*drives the program witch user input, and apporate function calls
***********************************************/
int main() {
	AlertList al; //!< make the alertlist
	al.popList();
	int intUserIO; //!< user input
	string stringUserIO;  //!< fips code user input
	cout << " 1: write unsorted list \n 2: write sorted list"
		<< "\n 3: find a fips code \n 4: exit " << endl;
	cin >> intUserIO;
	while (intUserIO != 4)
	{

		if (intUserIO == 1)
		{
			al.writeList();
		}
		else if (intUserIO == 2)
		{
			al.writeSortedListByFips();
		}
		else
		{
			cout << "find what fips?" << endl;
			cin >> stringUserIO;
			al.findFips(stringUserIO);
		}
		cout << "1: write unsorted list \n 2: write sorted list"
			<< "\n 3: find a fips code \n 4: exit " << endl;
		cin >> intUserIO;
	}

	system("pause");
	return 0;
}
