//Author: michael lapan
//assignment: program9
/*
*this program reads two files, loads both into BST
*and then allows the user to search for a user on a certin date
*/

#include <fstream> 
#include <iostream> 
using namespace std;

#include "wrap.h"
int main()
{
	//vars to hold user input.
	int custID = 0;
	string date;

	wrap BST;
	cout << "what is the customers id?" << endl;
	cin >> custID;
	cout << "the date to look up for the person? (format must be DD/MM/YYY)" << endl;
	cin >> date;

	//find this custID on this date
	BST.find(custID, date);
	system("pause");
}