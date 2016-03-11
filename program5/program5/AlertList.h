#include<string>
#include "Alert.h"
using namespace std;

/********************************************//**
* \class AlertList
*
* AlertList brief description
*			this class manages all of the alert objects
*
*this class populates the list of alert objects,
*sorts them by fips code, outputs them sorted or 
*non sorted, and also can find by fips code and
* output all info about that fips code.
*sorting is done by quick sort
***********************************************/
class AlertList
{
private:
	int listSize; //!< is the size of the list? not needeD?
	Alert list[15]; //!<  array of alert objects
public:

	/********************************************//**
	*getListSize function deff
	*this function returns the size of the listSize
	*varible
	***********************************************/
	int getListSize();
	// Alert getList();
	

	/********************************************//**
	*setListSize function deff
	*@param[in] toSet sets the size of the list manualy
	***********************************************/
	void setListSize(int toSet);
	

	/********************************************//**
	*popList function deff
	*this function populates the list of alert objects
	*fills all alert objects with all the info they 
	*they need to make their alert
	***********************************************/
	void popList();
	

	/********************************************//**
	*getFileSize function deff
	*this function returns the size of the alerts.txt
	*file. witch is how many alert objects their are.
	***********************************************/
	int getFileSize();
	


	

	/********************************************//**
	*writeList function deff
	*writeList writes the unsorted list
	***********************************************/
	void writeList();

	/********************************************//**
	*writeSortedListByFips function deff
	*writes the sorted list of alert objects.
	*the list is sorted by fips code
	***********************************************/
	void writeSortedListByFips();

	/********************************************//**
	* Quicksort, taken from the internet, modified by
	*Michael LaPan to sort an array of objects by the 
	*fips code object in the array object.
	* @param [in,out] a - The array to be sorted.
	* @param [in] first - The start of the sequence to be sorted.
	* @param [in] last - The end of the sequence to be sorted.
	***********************************************/
	void quickSort(Alert a[], int first, int last);

	/********************************************//**
	* Find and return the index of pivot element.
	* @param [in, out] a - The array.
	* @param [in] first - The start of the sequence.
	* @param [in] last - The end of the sequence.
	* @return [out]- the pivot element
	***********************************************/
	int pivot(Alert a[], int first, int last);

	/********************************************//**
	* Swap the parameters.
	* @param [in,out] a - The first parameter.
	* @param [in,out] b - The second parameter.
	***********************************************/
	void swap(Alert& a, Alert& b);

	/********************************************//**
	*findFips function deff
	*finds the fips code and outputs the county, state
	*fips code, and population for the fipscode.
	* @param [in] FIPS fips code to find
	***********************************************/
	void findFips(string FIPS);
};
