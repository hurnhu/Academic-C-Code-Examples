#ifndef QUIZITEM_H 

#include <string>
/**
*this is the quizItem class
*this is the base class for most all other classes
*it is responsable for, holding the question's, and
*answers to the quiz, and also has a virtual function
*generateQuestoin
*/
using namespace std;

class quizItem

{
private:
	string questionQuiz;//quiz question
	string answerQuiz;//quis answer
	string answerScrambled;//answer to scrambled question
public:

	//GenerateQuestion is the virtual function that all classes have
	//this will generate the question for any of its class, that 
	//inherates quizItem
	virtual void GenerateQuestion();

	void buildQ();// outputs the question

	void setQuestion(string toSet);//set the question
	void setAnswer(string toSet);// set the answer
	void setAnswerScrambled(string toSet);//set the scrambled words answer
	string getQuestion();//get the question
	string getAnswer();//get the answer
	string getAnswerScrambled();//gets the scrambled words answer.
};
#define QUIZITEM_H 
#endif 