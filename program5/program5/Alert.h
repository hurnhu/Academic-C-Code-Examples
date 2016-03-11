#include<string>
#include "dateTime.h"
#include "fips.h"
using namespace std;

/********************************************//**
* \class alert
*
* alert brief description
*			this class manages all of the alert objects
*
*this class populates the list of alert objects,
*sorts them by fips code, outputs them sorted or 
*non sorted, and also can find by fips code and
* output all info about that fips code.
*sorting is done by quick sort
***********************************************/
class Alert
{
private:
	string dateTimeString; //!< string to hold unparsed date and time
	fips fipsCode;  //!< object to hold info about fips code
	string code;  //!< holds the weather code
	string pop;  //!< hold the population
	dateTime dateTimeS;  //!< dateTime object for the starting date and time
	dateTime dateTimeE;  //!<  dateTime object for the ending date and time

public:
	

	/********************************************//**
	*getdateTimeString function deff
	*@return [out] - returns the dateTimeString
	***********************************************/
	string getdateTimeString();

	/********************************************//**
	*getfips function deff
	*@return [out] - returns the fips code object
	***********************************************/
	fips getfips();

	/********************************************//**
	*getCode function deff
	*@return [out] - returns the weather code
	***********************************************/
	string getCode();

	/********************************************//**
	*getDateTimeS function deff
	*@return [out] - returns the starting dateTime object
	***********************************************/
	dateTime getDateTimeS();

	/********************************************//**
	*getDateTimeE function deff
	*@return [out] - returns the ending dateTime object
	***********************************************/
	dateTime getDateTimeE();

	/********************************************//**
	*getParsedDateTime function deff
	*@return [out] - returns the parsed dateTime object
	***********************************************/
	dateTime getParsedDateTime();

	/********************************************//**
	*getPop function deff
	*@return [out] - returns the population
	***********************************************/
	string getPop();
	

	/********************************************//**
	* function deff
	* @param[in] toSet Is the varible
	***********************************************/
	void setdateTimeString(string toSet);


	/********************************************//**
	*setCode function deff
	* @param[in] toSet Is the varible code will be set to
	***********************************************/
	void setCode(string toSet);

	/********************************************//**
	*setDateTimeS function deff
	* @param[in] toSet Is the varible dateTimeS (s is for start)
	*will be set to
	***********************************************/
	void setDateTimeS(dateTime toSet);

	/********************************************//**
	* setDateTimeE function deff
	* @param[in] toSet Is the varible dateTimeE (e is for end)
	*will be set to
	***********************************************/
	void setDateTimeE(dateTime toSet);

	/********************************************//**
	* setParsedDateTime function deff
	* @param[in] toSet Is the object parsedDateTime 
	*will be set to
	***********************************************/
	void setParsedDateTime(dateTime toSet);

	/********************************************//**
	*setPop function deff
	* @param[in] toSet Is the varible population will
	*be set to
	***********************************************/
	void setPop(string toSet);
	

	/********************************************//**
	*writeAlert function deff
	*this quite franksl writes one alert, from 
	*all of the objects
	***********************************************/
	void writeAlert();

	/********************************************//**
	*parseDateTime function deff
	*parses the dateTime string from a number like
	*201502121300 to - 2015, feburary, 12, 1:00pm
	*is all done with math. I divide and truncate 
	*toget each number.
	*@param[in] se this number will determin weather
	*this datetime is the starting dateTime or the 
	*ending dateTime
	***********************************************/
	void parseDateTime(int se);

	/********************************************//**
	*parseCode function deff
	*parse code parses a weather code like wws
	*into something readable by humans. EG.
	*wws = Winter Storm Warning
	***********************************************/
	void parseCode();

	/********************************************//**
	*popFips function deff
	*finds and sets the population of a defined fips
	*code 
	*@param[in] toParse - the fips code to lookup 
	*and get and set pop of
	***********************************************/
	void popFips(string toParse);

	/********************************************//**
	*getPopByFips function deff
	*finds and set the population of a fips code 
	*from the file.
	***********************************************/
	void getPopByFips();

	/********************************************//**
	*searchFipsCode function deff 
	*searches for a fips code and then displays info
	*about fips code
	*@param[in] toFind - is the fips code to look for
	***********************************************/
	void searchFipsCode(string toFind);
};
