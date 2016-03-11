#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

#include "orderLinkedList.h"
#include "problem.h"

/*
*problemList class
*the problem list class holds all of the problems 
*and acts as sort of the manager class
*/
class ProblemList
{

private:
	OrderLinkedList<problem> head;        // List head pointer
public:
	ProblemList(string toRead);//constructor
	ProblemList ProblemList::operator+= (ProblemList& toAdd);//overloaded +=
	ProblemList ProblemList::operator-= (ProblemList& toAdd);//overloaded -=
	int getLen();//returns the len of the linked list
	void writeTop(int numToWrite);//writed the top
	void writeBottom(int numToWrite);//writed the bottem
	OrderLinkedList<problem> getHead();//returns the head
};

