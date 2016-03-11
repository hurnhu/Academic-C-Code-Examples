#include <string>
using namespace std;

/********************************************//**
*\class fips
*
* fips brief description.
*         this class hold info about the fipsCode
*
*this class hold info about the fips code, like
*the fipsCode, the county for that fipsCode,
*and the state the fips code is in.
***********************************************/
class fips
{
private:
	string fipsCode; //!< Holds the Fips code
	string county; //!< holds the county
	string state; //!< holdes the stae its in
public:

	/********************************************//**
	* getFipsCode function deff
	*return the fips code for the object.
	*@return [out] - returns the fipscode
	***********************************************/
	string getFipsCode();
	/********************************************//**
	* getCounty function deff
	*return the county for the object.
	*@return [out] - returns the county
	***********************************************/
	string getCounty();
	/********************************************//**
	*  getState function deff
	*return the state for the object.
	*@return [out] - returns the state
	***********************************************/
	string getState();

	/********************************************//**
	*  setFipsCode function deff
	*sets the fips code for the object.
	* @param[in] toSet Is the varible fipsCode will be set to
	***********************************************/
	void setFipsCode(string toSet);
	/********************************************//**
	*   setCounty function deff
	*sets the county for the object.
	* @param[in] toSet Is the varible county will be set to
	***********************************************/
	void setCounty(string toSet);
	/********************************************//**
	*   setState function deff
	*sets the state for the object.
	* @param[in] toSet Is the varible state will be set to
	***********************************************/
	void setState(string toSet);

	/********************************************//**
	* fipsToInt function deff
	* changes the fips code from a string to an int
	***********************************************/
	int fipsToInt();
};
