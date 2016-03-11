#include <string>
using namespace std;

/********************************************//**
* \class dateTime
*
* dateTime brief description
*			this class hold the date and military time
*
*this class holds the month, day, year, and time
* for a given date. it can also parse the month
* in to its worded format, and change the time
* from military to normal
***********************************************/

class dateTime
{
private:
	int month; //!< holds the months number
	int day; //!< holds the day number
	int year; //!< holds the year
	int hr; //!< holds only the hour of the time
	int min; //!<  holds only the minute of the time

	string monthP; //!< holds the month changed to worded format
	string timeP; //!< holds the time changed from military time

public:

	/********************************************//**
	* getMonth function deff
	* returns the numberd month
	*@return [out] - returns the numbered month
	***********************************************/
	int getMonth();

	/********************************************//**
	* getDay function deff
	* returns the numbered day
	*@return [out] - returns the day
	***********************************************/
	int getDay();

	/********************************************//**
	* getYear function deff
	* returns the year
	*@return [out] - returns the year
	***********************************************/
	int getYear();

	/********************************************//**
	* getHr function deff
	* returns the hours in military time
	*@return [out] - returns the hr in military time
	***********************************************/
	int getHr();

	/********************************************//**
	* getMin function deff
	* returns the mins
	*@return [out] - returns the minutes
	***********************************************/
	int getMin();

	/********************************************//**
	* getTimeP function deff
	* returns the parsed time, changes time from
	*military time to normal
	*@return [out] - returns the parsed time
	***********************************************/
	string getTimeP();

	/********************************************//**
	* getMonthP function deff
	*returns the parsed month, changes the month from
	* a number to worded format
	*@return [out] - returns the parswed month
	***********************************************/
	string getMonthP();

	/********************************************//**
	*  setMonth function deff
	*sets the month for the object.
	* @param[in] toSet Is the varible month will be set to
	***********************************************/
	void setMonth(int toSet);

	/********************************************//**
	*  setDay function deff
	*sets the day for the object.
	* @param[in] toSet Is the varible day will be set to
	***********************************************/
	void setDay(int toSet);

	/********************************************//**
	*  SetYear function deff
	*sets the year for the object.
	* @param[in] toSet Is the varible year will be set to
	***********************************************/
	void SetYear(int toSet);

	/********************************************//**
	*  setHr function deff
	*sets the hour for the object.
	* @param[in] toSet Is the varible hr will be set to
	***********************************************/
	void setHr(int toSet);

	/********************************************//**
	*  setMin function deff
	*sets the minute for the object.
	* @param[in] toSet Is the varible min will be set to
	***********************************************/
	void setMin(int toSet);

	/********************************************//**
	* parseMonth function deff
	*changes the month from a number to words.
	*throws numbered month into switch. then sets
	*the parsed month to monthP
	***********************************************/
	void parseMonth();

	/********************************************//**
	* parseTime function deff
	*changes the time from military time into normal
	*time. if hours is over 12 it subtracts 12
	*to get time in the afternoon, if the number is
	* 0 after 12 is selected. it sets the hour
	*to noon. this also combines hours and minutes
	*into one string.
	***********************************************/
	void parseTime();

	//dateTime(double m, double d, double y);
};
