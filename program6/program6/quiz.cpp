#include <string>
#include <iostream>
#include "quiz.h"
#include <time.h>

using namespace std;
/*
*!!constructor!!
*this is where i get the arrays size,
*and create the quiz array, and the quiz key array
*and then i populate both arrays
*/
quiz::quiz()
{
	srand(time(NULL));//sets the seed for a little more random
	size = randArraySize();
	QIArray = new quizItem *[size];
	QIKarray = new string[size];
	popArray();
}
/*
*HOUSEKEEPING!
*deletes the arrays made with new
*/
quiz::~quiz()
{
	delete[] QIArray;
	delete[] QIKarray;
}

/*
*this is where the questions are asked and the user
*has a chance to get it right. if he doesnt get it
*it will ask if they want to try again. also has option
*to show keey while taking the quiz
*/
void quiz::userIO()
{
	string sToC;
	int i = 0, again = 0, tp = 0;
	cout << "see key with test? (enter teacher pass)" << endl << endl; 
	cin >> tp;
	do
	{
		if (tp==42)//answer to everything
		{
			//clear the cin buffer. getline was getting skipped
			//due to random return in the buffer, have to clear
			//for getline to be encountered
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			QIArray[i]->buildQ();
			cout << "  Answer: " << QIKarray[i] << endl;;
			getline(cin, sToC);
			if (sToC == QIKarray[i])
			{
				cout << "good job!! you got the question right!\n" << endl;
				i++;
			}
			else
			{
				cout << "your answer is wrong, try again? (1 for yes, 0 for no)\n" << endl;
				cin >> again;
				if (again == 0)
				{
					i++;
				}
			}
		}
		else
		{			
			//clear the cin buffer. getline was getting skipped
			//due to random return in the buffer, have to clear
			//for getline to be encountered
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			QIArray[i]->buildQ();
			getline(cin, sToC);
			if (sToC == QIKarray[i])
			{
				cout << "good job!! you got the question right!\n" << endl;
				i++;
			}
			else
			{
				cout << "your answer is wrong, try again? (1 for yes, 0 for no)\n" << endl;
				cin >> again;
				if (again == 0)
				{
					i++;
				}
			}
		}
	} while (i != size);
}
/*
*populates the array with random questions
*/
void quiz::popArray()
{
	string randAns;	


	for (size_t i = 0; i < size; i++)
	{
		randAns = newQuestion();
		if (randAns == "w")
		{
			QIArray[i] = new wordScramble();
			QIArray[i]->GenerateQuestion();
			QIKarray[i] = QIArray[i]->getAnswer();

		}
		else if (randAns == "m")
		{
			QIArray[i] = new mathProblem();
			QIArray[i]->GenerateQuestion();
			QIKarray[i] = QIArray[i]->getAnswer();

		}
		else if (randAns == "t")
		{
			QIArray[i] = new triviaQuestion();
			QIArray[i]->GenerateQuestion();
			QIKarray[i] = QIArray[i]->getAnswer();
		}
	}
	userIO();
}
//randomly makes the array size
int quiz::randArraySize()
{
	return rand() % 20 + 10;
}
/*
*randomly picks the type of question
*returns what the random type should be
*/
string quiz::newQuestion()
{
	int randQ = rand() % 3;
	switch (randQ)
	{
	case 0:
		return "m";
		break;
	case 1:
		return "t";
		break;
	case 2:
		return "w";
		break;
	}
}
