#include <string>
#include "quizItem.h"
#include "wordScramble.h"
#include "MathProblem.h"
#include "triviaQuestion.h"

using namespace std;
/**
*this is the quiz class
*the quiz class is what holds all of the quiz items,
*and calls the correct functions to ask the questions.
*/
class quiz
{
private:
	quizItem **QIArray; //pointer to a soon to be array of quiz items
	string *QIKarray;//pointer to a soon to be array of strings

	int size; //size of the array
public:
	quiz();//constructor
	~quiz();//destructor
	void popArray();//populates the array with quiz items
	int randArraySize();//randomly sets the array size
	string newQuestion();//makes a new questoin of random type
	void userIO();//where all user in and out is located.
};

