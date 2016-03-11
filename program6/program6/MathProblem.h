#ifndef MATHPORBLEM_H 

#include <string>
#include "quizItem.h"
using namespace std;
/**
*this is the math problem class
*this class is responsable for generating a math question
*for the quiz. it also has a base class of quizItem.
*/
class mathProblem : public quizItem
{
private:
	double first;//first part of the math eq, (used to calc ans)
	double last;//last part of the math eq, (used to calc ans)
	char operand;//the randomly chosen operand
	string answer;//answer in string form
	string firstPart;//first part in string form
	string secondPart;//last part in string form
public:
	mathProblem();//constructor

	void setFirst(double toSet);//sets the first part
	void setLast(double toSet);//sets the second part
	void setOperand(char toSet);//sets the operand
	void setFirstPart(string toSet);//sets the first part as string
	void setSecondPart(string toSet);//sets the second part as string

	double getFirst( );//returns the first part
	double getLast( );//returns the second part
	char getOperand( );//returns the operand
	string getFirstPart( );//returns the first part as string
	string getSecondPart( );//returns the second part as string

	void randFirstSecondOp();//randomly chooses the first and second number, and their operand
	void GenerateQuestion();//makes the question
};
#define MATHPORBLEM_H
#endif 