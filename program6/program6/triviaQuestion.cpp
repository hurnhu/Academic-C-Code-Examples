#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <time.h>  
#include "triviaQuestion.h"

using namespace std;


/*
*!!constructor!!
*i get the file size, and the create my two arrays
*with that file size. size/2 is becuase every other
*item in the file is the questoin. i them populate
*the array.
*/
triviaQuestion::triviaQuestion()
{
	size = getFileSize();
	qArray = new string[size / 2 + 1];
	aArray = new string[size / 2 + 1];
	popArray();
}
/*
*HOUSE KEEPING!
*delete the arrays i made with new
*/
triviaQuestion::~triviaQuestion()
{
	delete[] qArray;
	delete[] aArray;
}
/*
*reads from the file placeing itmes into the array
*in the patteren of every other. first item in file 
*is the question, second is answer.
*/
void triviaQuestion::popArray()
{
	int i = 0;
	ifstream inFile("trivia.txt");
	string inputLine;

	if (inFile.fail())         // Test for file existence
	{
		cout << "Problem opening file";
		system("pause");
		exit(-1);
	}

	while (!inFile.eof())
	{

		getline(inFile, inputLine); //continuation read
		qArray[i] = inputLine;

		getline(inFile, inputLine); //continuation read
		aArray[i] = inputLine;
		i++;
	}
}
/*
*randomly picks a question and answer from the
*question and answer array, thens sets them.
*/
void triviaQuestion::GenerateQuestion()
{
	int randAns = rand() % 36;
	setAnswer(aArray[randAns]);
	setQuestion(qArray[randAns]);
	
}
/*
*loops through the file getting the length of the file
*used in the creation of the arrays
*/
int triviaQuestion::getFileSize()
{
	int i = 0;
	ifstream inFile("trivia.txt");
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
		i++;
	}
	return i;
}