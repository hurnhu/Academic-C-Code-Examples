// This program uses the selection sort algorithm to sort an  
// array in ascending order. 

#include <iostream> 
#include <string>
#include <fstream>
using namespace std; 

// Function prototypes 
void selectionSort(int array[], int elems); 
void showArray(int array[], int elems); 
void GetList(int[],int&,int,string); 
const int MAX_LIST_SIZE = 100;      // Max list size 
int swaps = 0, comps = 0;

int main(void) 
{ 
	int InList[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize;                   // Index of last list element 

	int InList2[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize2;                   // Index of last list element  

	int InList3[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize3;                   // Index of last list element 


	GetList(InList,ListSize,MAX_LIST_SIZE, "Almost.txt"); 
	selectionSort(InList,100); 
	cout<< swaps << " " << comps << endl;

	GetList(InList2,ListSize2,MAX_LIST_SIZE, "Inverse.txt"); 
	selectionSort(InList2,100); 
	cout<< swaps << " " << comps << endl;

	GetList(InList3,ListSize3,MAX_LIST_SIZE, "Random.txt");	
	selectionSort(InList3,100); 
	cout<< swaps << " " << comps << endl;
	// Display unsorted list 
	//cout << "The unsorted values are\n"; 
	//showArray(InList, 100); 

	// Sort values 
	// selectionSort(values, arraySize); 

	// Display sorted list 
	//cout << "The sorted values are\n"; 
	//showArray(values, arraySize); 
	system("pause");
	return 0; 
} 

void GetList(int inList[],int& listsize,int maxlistsize, string file) 
{ 
	ifstream InFile (file); 
	int ListElement; 

	int i = 0; 
	InFile >> ListElement; 
	while(InFile && i < maxlistsize) 
	{ 
		inList[i] = ListElement; 
		i++; 
		InFile >> ListElement; 
	} 
	listsize = i;        // Size of list 
} 
//************************************************************** 
// Definition of function selectionSort.                       * 
// This function performs an ascending order selection sort on * 
// array. elems is the number of elements in the array.        * 
//************************************************************** 
void selectionSort(int array[], int elems) 
{ 
	int startScan, minIndex, minValue; 

	for (startScan = 0; startScan < (elems - 1); startScan++) 
	{ 
		minIndex = startScan; 
		minValue = array[startScan]; 
		for(int index = startScan + 1; index < elems; index++) 
		{ 
			comps++;

			if (array[index] < minValue) 
			{ 
				swaps++;

				minValue = array[index]; 
				minIndex = index; 
			} 
		} 
		array[minIndex] = array[startScan]; 

		array[startScan] = minValue; 
	} 
} 

//************************************************************** 
// Definition of function showArray.                           * 
// This function displays the contents of array. elems is the  * 
// number of elements.                                         * 
//************************************************************** 
void showArray(int array[], int elems) 
{ 
	for (int count = 0; count < elems; count++) 
		cout << array[count] << " " << endl;; 
	cout << endl; 
} 