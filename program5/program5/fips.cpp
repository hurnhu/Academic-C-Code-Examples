#include <string>
#include <sstream>
#include "fips.h"
using namespace std;

	/********************************************//**
	* **NOTE**
	* everything that has been clearly defined
	*through comments in the header will not be
	*redifined here. but some functions will have 
	*a little extra if they do something either 
	*hard to follow, or just need to clear them
	*up
	***********************************************/

string fips::getFipsCode()
{
	return fipsCode;
}
string fips::getCounty()
{
	return county;
}
string fips::getState()
{
	return state;
}

void fips::setFipsCode(string toSet)
{
	fipsCode = toSet;
}
void fips::setCounty(string toSet)
{
	county = toSet;
}
void fips::setState(string toSet)
{
	state = toSet;
}
	/********************************************//**
	*uses a string stream to change from 
	*an fipscode to an int. (string to int)
	***********************************************/
int fips::fipsToInt()
{
	istringstream ss(fipsCode);
	int i;
	ss >> i;
	return i;
}