
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ProblemList.h"

/*
*********************
*MADE BY MICHAEL LApAN
*********************
*this program is a help desk mock up
*it proccesses helkp desk tickets,
*sorts and stores them. then shows top
*25 then bottem 25
*/
int main()
{
	ProblemList problems("problems.txt");
	
	ProblemList newProblems("newproblems.txt");

	ProblemList solvedProblems("resolvedproblems.txt");

		problems += newProblems;
		problems -= solvedProblems;
		//couldnt easily incorporate this into class
		cout << "Priority  Submitted     By       Description" << endl;
		problems.writeTop(25);
		system("pause");
		//couldnt easily incorporate this into class
		cout << "Priority  Submitted     By       Description" << endl;
		problems.writeBottom(25);
	system("pause");
}