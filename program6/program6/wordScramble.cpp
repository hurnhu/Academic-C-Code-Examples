#include "wordScramble.h"
#include <stdlib.h> 
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;
/*
*reads from the compWords file and places the words
*into an array
*/
void wordScramble::popArray()
{
	int i = 0;
	ifstream inFile("compWords.txt");
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
		ansArray[i] = inputLine;
		i++;
	}

}

/*
*gets the size of the file, so i can set the size of the array
*/
int wordScramble::getFileSize()
{
	int i = 0;
	ifstream inFile("compWords.txt");
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
/*
*generates the question, mostly just setting the 
*question and answer. it randomly picks a question
*and answer.
*/
void wordScramble::GenerateQuestion()
{
	int num = rand() % size;
	setQuestion("Unscramble this word");
	setAnswer(ansArray[num]);
	setAnswerScrambled(ansArrayScram[num]);
}
/*
*this function jumbles up a string in the ansArray
*and places it in to the scrammbled array.
*i jumble the string using random_shuffle from 
*algorithms
*/
void wordScramble::jumble()
{
	string temp ; 
	for (size_t i = 0; i < size - 1; i++)
	{
		temp = ansArray[i];
		random_shuffle(temp.begin(), temp.end());
		ansArrayScram[i] = temp;
	}
}
/*
*!!constructor!!
*this is where both arrays are given their sizes
*also all calls are made from here so everything
*is ready, and no other unnesscary calls need to
*be made
*/
wordScramble::wordScramble()
{
	size = getFileSize();
	ansArray = new string[size + 1];
	ansArrayScram = new string[size + 1];
	popArray();
	jumble();
}
/*
*HOUSE KEEPING!
*delete the arrays i made with new to free up ram
*/
wordScramble::~wordScramble()
{
	delete[] ansArray;
	delete[] ansArrayScram;
}