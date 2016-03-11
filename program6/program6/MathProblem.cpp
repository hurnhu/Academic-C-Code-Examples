#include <string>
#include <iostream>
#include <stdlib.h> 
#include "MathProblem.h"

using namespace std;


void mathProblem::setFirst(double toSet)
{
	first = toSet;
}
void mathProblem::setLast(double toSet)
{
	last = toSet;
}
void mathProblem::setOperand(char toSet)
{
	operand = toSet;
}

void mathProblem::setFirstPart(string toSet)
{
	firstPart = toSet;
}
void mathProblem::setSecondPart(string toSet)
{
	secondPart = toSet;
}

double mathProblem::getFirst()
{
	return first;
}
double mathProblem::getLast()
{
	return last;
}
char mathProblem::getOperand()
{
	return operand;
}

string mathProblem::getFirstPart()
{
	return firstPart;
}
string mathProblem::getSecondPart()
{
	return secondPart;
}

/*
*randomly generates, the first and second number.
*then generates a number from 0-4, and that is put in
*to the switch. depending on what the number was,
*itll assign and preform calc with that operand
*/
void mathProblem::randFirstSecondOp()
{
	first = rand() % 999 + 1;
	last = rand() % 999 + 1;
	firstPart = to_string((int)first);
	secondPart = to_string((int)last);
	int temp = rand() % 5;
	switch (temp)
	{
	case 0:
		operand = '+';
		answer = to_string((int)(first + last));
		break;
	case 1:
		operand = '-';
		answer = to_string((int)(first - last));
		break;
	case 2:
		operand = 'X';
		answer = to_string((int)(first * last));
		break;
	case 3:
		operand = '/';
		answer = to_string((first / last)) ;
		break;
	case 4:
		operand = '%';//wouldnt be programming w/o mod!
		answer = to_string(((int)first % (int)last));
		break;

	}
}
/*
*sets te question and answer
*/
void mathProblem::GenerateQuestion()
{
	setQuestion("Calculate " + firstPart + " " + operand + " " + secondPart + "\nfor division must include leading 0,\n need to calculate to sith decimal (0.######)");
	setAnswer(answer);
}
/*
*!!constructor!!
*calls the method to randomly make first second number and operator.
*/
mathProblem::mathProblem()
{
	randFirstSecondOp();
}

