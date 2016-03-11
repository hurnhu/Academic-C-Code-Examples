#ifndef WORDSCRAMBLE_H 

#include <string>
#include "quizItem.h"
using namespace std;
/**
*this is the word scramble class
*this class is responsable for, reading all the words
*from thee comWords.txt, jumbleing them up, and making
*the question. this class has a base class of quizItem
*/
class wordScramble : public quizItem
{

private:
	string *ansArray; //pointer to a string, to be turned into an dynamicly sized array
	string *ansArrayScram; //pointer to a string, to be turned into an dynamicly sized array
	int size; //the size of the array

public:
	wordScramble();//constructor
	~wordScramble();//destructor
	void GenerateQuestion();//generates the question to ask
	void popArray();//populates the array
	int getFileSize();//gets the size to use for the array
	void jumble();//jumbles up the word

}; 
#define WORDSCRAMBLE_H
#endif 