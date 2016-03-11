#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#include "fileStuff.h"

bool menu();
bool menuOptions(int option);
bool isUnique(interact * arryOfObj, int size, int idToCheck);
void listAll(interact * arryOfObj, int size);
int subOne(interact * arryOfObj, int size, int idToDel);
void shellsortAcendById(interact *arryOfObj, int n);
void shellsortDecendById(interact *arryOfObj, int n);
void shellsortAcendByWeight(interact *arryOfObj, int n);
void shellsortDecendByWeight(interact *arryOfObj, int n);

//setting max size of the array
const int MAXSIZE = 100;

int main()
{
	//isRunning will only be false if the user picks six in userOptions
	//this keeps user at the menu

	bool isRunning = true;
	while (isRunning)
	{
		isRunning = menu();
	}
	return 0;
}

/*********************************************************
* Function deff for menu								 *
* menu is where the user will pick what they want to do  *
* in the even of the user entering 6 to quit. menu will  *
* return false from menuOption.							 *
**********************************************************/
bool menu()
{
	int option = 0;
	cout << "1: add new backpack. " << endl
		<< "2: delete a backpack " << endl
		<< "3: sort ascending by id " << endl
		<< "4: sort descending by id " << endl
		<< "5: sort ascending by weight " << endl
		<< "6: sort descending by Weight " << endl
		<< "7: list all backpacks " << endl
		<< "8: quit" << endl;
	cin >> option;
	return menuOptions(option);
}
/************************************************************
* Function deff for menuOptions								*
*menuOption is where all calls to sorrting, adding, deleting*
*and listing are done. if this recives a 6 (quit) from menu *
*it will return false										*
*************************************************************/
bool menuOptions(int input)

{
	static int rSize = 0;
	//made static to keep array contents inbetween
	//function calls.
	static interact arryOfObj[MAXSIZE];

	fileStuff fileIOStuff;

	int tempBagId = 0, tempInvSpaces = 0, idToReplace = 0;

	int bkn = 0;

	double tempInvMaxWeight = 0.0;

	//checks to see if it should load from file first.
	int temp = fileIOStuff.shouldLoad();

	if (temp > 0)
	{
		fileIOStuff.readFromFile(arryOfObj, rSize);
		//if the first line is 0 0 0 it means the file is empty
		//start at 0 for array.
		if (arryOfObj[0].getBagId() == 0 && arryOfObj[0].getInvMaxWeight() == 0 && arryOfObj[0].getInvSpaces() == 0)
		{
			rSize = 0;
		}
	}
	switch (input)
	{
		//get input from user about the bag, and then set the info
		// increase the real array size
	case 1:
		cout << "bagId? ";
		cin >> tempBagId;
		cout << "How many inv spaces? ";
		cin >> tempInvSpaces;
		cout << "How much weight can the bag hold? ";
		cin >> tempInvMaxWeight;
		cout << "how degraded is the bag? ";
		cin >> bkn;

		if (isUnique(arryOfObj, rSize, tempBagId) == true)
		{
			arryOfObj[rSize].setBagId(tempBagId);
			arryOfObj[rSize].setInvSpaces(tempInvSpaces);
			arryOfObj[rSize].setInvMaxWeight(tempInvMaxWeight);
			arryOfObj[rSize].setStateOfDecay(bkn);
			fileIOStuff.writeToFile(arryOfObj, rSize);
			rSize++;
		}
		else
		{
			cout << "You must enter a unique id for the bag try again." << endl;
			system("pause");
		}

		break;
		//remove an item from the array, move all other items up to
		//fill gap, also set new array size
	case 2:
		cout << "Id to Delete? " << endl;
		cin >> idToReplace;
		rSize = subOne(arryOfObj, rSize, idToReplace);
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);
		break;
		//sorts the array, lists the sorted array
		// writes the new format for array to file
	case 3:
		shellsortAcendById(arryOfObj, rSize);
		listAll(arryOfObj, rSize);
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);

		break;
		//sorts the array, lists the sorted array
		// writes the new format for array to file
	case 4:
		shellsortDecendById(arryOfObj, rSize);
		listAll(arryOfObj, rSize);
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);

		break;
		//sorts the array, lists the sorted array
		// writes the new format for array to file
	case 5:
		shellsortAcendByWeight(arryOfObj, rSize);
		listAll(arryOfObj, rSize);
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);
		break;
		//sorts the array, lists the sorted array
		// writes the new format for array to file
	case 6:
		shellsortDecendByWeight(arryOfObj, rSize);
		listAll(arryOfObj, rSize);
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);
		break;
		//calls list all, to list all items in array.
	case 7:
		//list all
		listAll(arryOfObj, rSize);
		break;
		//quits by saving one last time to ensure nothing lost.
		//return false to menu, that inturn returns false to main.
		//quiting the program
	case 8:
		fileIOStuff.writeToFile(arryOfObj, rSize - 1);
		return false;
		break;
	default:
		break;
	}
}
/************************************************************
* Function deff for isUnique								*
*check to see if the id the user is trying to enter is in	*
*array already. to avoid delete issues, all ids must be		*
*unique														*
*************************************************************/
bool isUnique(interact * arryOfObj, int size, int idToCheck)
{
	for (int i = 0; i < size; i++)
	{
		if (arryOfObj[i].getBagId() == idToCheck)
		{
			return false;
		}
	}
	return true;
}
/************************************************************
* Function deff for listAll									*
*listAll takes the array and the current size of the array	*
*this just outputs everything in the array up to curr size	*
*************************************************************/
void listAll(interact * arryOfObj, int size)
{
	int i = 0;
	for (i; i < size; i++)
	{
		cout << "bag ID: " << arryOfObj[i].getBagId() << " " << endl
			<< "Inv spaces: " << arryOfObj[i].getInvSpaces() << " " << endl
			<< "Max bag carry weight: " << arryOfObj[i].getInvMaxWeight() << " " << endl
			<< "bag degradation: " << arryOfObj[i].getStateOfDecay() << "%" << endl << endl;
	}
}
/************************************************************
* Function deff for subOne									*
*subOne will take the array, current size of the array and  *
*the id you want to delete. it will delete that id and move *
*everything up in to that blank space.						*
*************************************************************/
int subOne(interact * arryOfObj, int size, int idToDel)
{
	bool found = false;
	//checks to see if number is in array, to avoid
	//accidental deletion of numbers over the one
	// you wanted to delete
	for (int i = 0; i < size; i++)
	{
		if (arryOfObj[i].getBagId() == idToDel)
		{
			found = true;
		}
	}
	//loop through array looking for number to delete
	//if found mover everything behind it up one space
	shellsortAcendById(arryOfObj, size);
	if (found)
	{
		for (int i = 0; i < size; i++)
		{
			if (arryOfObj[i].getBagId() >= idToDel)
			{
				arryOfObj[i].setBagId(arryOfObj[i + 1].getBagId());
				arryOfObj[i].setInvSpaces(arryOfObj[i + 1].getInvSpaces());
				arryOfObj[i].setInvMaxWeight(arryOfObj[i + 1].getInvMaxWeight());
				arryOfObj[i].setStateOfDecay(arryOfObj[i + 1].getStateOfDecay());
			}
		}
		return size - 1;
	}
	else
	{
		return size;
	}
}
/************************************************************
* Function deff for shellsortAcendByWeight					*
*shellsortAcendByWeight is where the array is sorted by		*
*bag weight. this uses the shell sort algorthim (template	*
for	algorthrim taken from online, was tweaked by Michael	*
*LaPan to be used to sort an array of objects by id)		*
*************************************************************/
void shellsortAcendByWeight(interact *arryOfObj, int n)
{
	int gap, i, j;

	interact temp;

	for (gap = n / 2; gap > 0; gap /= 2)

		for (i = gap; i < n; i++)

			for (j = i - gap; j >= 0 && arryOfObj[j].getInvMaxWeight() > arryOfObj[j + gap].getInvMaxWeight(); j -= gap)
			{
		temp = arryOfObj[j];

		arryOfObj[j] = arryOfObj[j + gap];

		arryOfObj[j + gap] = temp;
			}
}
/************************************************************
* Function deff for shellsortDecendByWeight					*
*shellsortDecendByWeight is where the array is sorted by	*
*bag weight. this uses the shell sort algorthim (template	*
for	algorthrim taken from online, was tweaked by Michael	*
*LaPan to be used to sort an array of objects by Weight	)	*
*************************************************************/
void shellsortDecendByWeight(interact *arryOfObj, int n)
{
	int gap, i, j;
	interact temp;

	for (gap = n / 2; gap > 0; gap /= 2)

		for (i = gap; i < n; i++)

			for (j = i - gap; j >= 0 && arryOfObj[j].getInvMaxWeight() < arryOfObj[j + gap].getInvMaxWeight(); j -= gap)
			{
		temp = arryOfObj[j];

		arryOfObj[j] = arryOfObj[j + gap];

		arryOfObj[j + gap] = temp;
			}
}
/************************************************************
* Function deff for shellsortDecendById						*
*shellsortDecendById is where the array is sorted by		*
*bag id. this uses the shell sort algorthim (template		*
for	algorthrim taken from online, was tweaked by Michael	*
*LaPan to be used to sort an array of objects by id	)		*
*************************************************************/
void shellsortDecendById(interact *arryOfObj, int n)
{
	int gap, i, j;
	interact temp;

	for (gap = n / 2; gap > 0; gap /= 2)

		for (i = gap; i < n; i++)

			for (j = i - gap; j >= 0 && arryOfObj[j].getBagId() < arryOfObj[j + gap].getBagId(); j -= gap)
			{
		temp = arryOfObj[j];

		arryOfObj[j] = arryOfObj[j + gap];

		arryOfObj[j + gap] = temp;
			}
}
/************************************************************
* Function deff for shellsortAcendById						*
*shellsortAcendById is where the array is sorted by			*
*bag id. this uses the shell sort algorthim (template		*
for	algorthrim taken from online, was tweaked by Michael	*
*LaPan to be used to sort an array of objects by id	)		*
*************************************************************/
void shellsortAcendById(interact *arryOfObj, int n)

{
	int gap, i, j;
	interact temp;

	for (gap = n / 2; gap > 0; gap /= 2)

		for (i = gap; i < n; i++)

			for (j = i - gap; j >= 0 && arryOfObj[j].getBagId() > arryOfObj[j + gap].getBagId(); j -= gap)
			{
		temp = arryOfObj[j];

		arryOfObj[j] = arryOfObj[j + gap];

		arryOfObj[j + gap] = temp;
			}
}