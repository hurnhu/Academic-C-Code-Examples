#include "listManager.h"
#include <iostream>
#include <string>
using namespace std;
//zeros out the new obj
interact::interact()
{
	bagId = 0;
	invSpaces = 0;
	invMaxWeigt = 0;
	isBroken = 0;
}
//sets the bag id
void interact::setBagId(int id)
{
	bagId = id;
}
//sets the amt of inv spaces
void interact::setInvSpaces(int spaces)
{
	invSpaces = spaces;
}
//set the max weight the bag can hold
void interact::setInvMaxWeight(double weight)
{
	invMaxWeigt = weight;
}
//sets if the bag is broken or not.
void interact::setStateOfDecay(int isBkn)
{
	isBroken = isBkn;
}
//returns the bag id
int interact::getBagId()
{
	return bagId;
}
//returns the amt of inv spaces
int interact::getInvSpaces()
{
	return invSpaces;
}
//returns the max weight this bag can hold
double interact::getInvMaxWeight()
{
	return invMaxWeigt;
}
//returns the stae of decay for the bag
int interact::getStateOfDecay()
{
	return isBroken;
}