#include <string>
#include <time.h>
#include <iostream>
#include "quizItem.h"
using namespace std;
/*
*does nothing 
*/
void quizItem::GenerateQuestion()
{ 
	cout << "in the gen questoin" << endl;
}

void quizItem::setQuestion(string toSet)
{
	questionQuiz = toSet;
}
void quizItem::setAnswer(string toSet)
{
	answerQuiz = toSet;
}
void quizItem::setAnswerScrambled(string toSet)
{
	answerScrambled = toSet;
}

string quizItem::getQuestion()
{
	return questionQuiz;
}
string quizItem::getAnswer()
{
	return answerQuiz;
}	
string quizItem::getAnswerScrambled()
{
	return answerScrambled;
}
/*
*outputs the question
*/
void quizItem::buildQ()
{
	cout <<  questionQuiz << "  " << answerScrambled << endl; 
}
