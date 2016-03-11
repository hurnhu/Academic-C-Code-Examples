#ifndef TRIVIAQUESTION_H 
#include <string>

#include "quizItem.h"
/**
*this is the triviaQuestion class
*this class is responsable for, generating a triva
*question, reading all questions and answers from a file
*providing both the question and answer. this class has
*a base class of quizItem
*/
using namespace std;

class triviaQuestion : public quizItem
{
private:
	string *qArray;//pointer to a string, to be turned into an dynamicly sized array
	string *aArray;//pointer to a string, to be turned into an dynamicly sized array
	int size;//size of the array
public:
	triviaQuestion();//constructor
	~triviaQuestion();//descructor


	void GenerateQuestion();//makes the question
	void popArray();//reades the file into the array
	int getFileSize();//gets the size of the file, and then sets array size to it.

};
#define TRIVIAQUESTION_H
#endif 