// This program demonstrates the QuickSort Algorithm 
#include <iostream> 
#include <string>
#include <fstream>
using namespace std; 

// Function prototypes 
void quickSort(int [], int, int); 
int partition(int [], int, int); 
void swap(int &, int &); 
void GetList(int[],int&,int,string); 

const int MAX_LIST_SIZE = 100;      // Max list size 

int swaps = 0, comps = 0;

int main() 
{ 

	int InList[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize;                   // Index of last list element 

	int InList2[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize2;                   // Index of last list element  

	int InList3[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize3;                   // Index of last list element 

	GetList(InList,ListSize,MAX_LIST_SIZE, "Almost.txt"); 
	quickSort(InList, 0, 99); 
		cout<< swaps << " " << comps << endl;

	GetList(InList2,ListSize2,MAX_LIST_SIZE, "Inverse.txt"); 
	quickSort(InList2, 0, 99); 
		cout<< swaps << " " << comps << endl;

	GetList(InList3,ListSize3,MAX_LIST_SIZE, "Random.txt");	
	quickSort(InList2, 0, 99); 
		cout<< swaps << " " << comps << endl;



	for (ListSize = 0; ListSize < 100; ListSize++) 
		cout << InList[ListSize] << " " << endl; 
	cout << endl; 

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
//************************************************ 
// quickSort uses the quicksort algorithm to     * 
// sort set, from set[start] through set[end].   * 
//************************************************ 
void quickSort(int set[], int start, int end) 
{ 
	int pivotPoint; 

	if (start < end) 
	{ 
		// Get the pivot point 
		pivotPoint = partition(set, start, end); 

		// Sort the first sub list 
		quickSort(set, start, pivotPoint - 1); 

		// Sort the second sub list 
		quickSort(set, pivotPoint + 1, end); 
	} 
} 

//********************************************************** 
// partition selects the value in the middle of the        * 
// array set as the pivot. The list is rearranged so       * 
// all the values less than the pivot are on its left      * 
// and all the values greater than pivot are on its right. * 
//********************************************************** 
int partition(int set[], int start, int end) 
{ 
	int pivotValue, pivotIndex, mid; 

	mid = (start + end) / 2; 
	swap(set[start], set[mid]); 
	pivotIndex = start; 
	pivotValue = set[start]; 

	for (int scan = start + 1; scan <= end; scan++) 
	{ 
		if (set[scan] < pivotValue) 
		{ 
			comps++;
			pivotIndex++; 
			swap(set[pivotIndex], set[scan]); 
		} 
	} 
	swap(set[start], set[pivotIndex]); 

	return pivotIndex; 
} 

//********************************************** 
// swap simply exchanges the contents of       * 
// value1 and value2.                          * 
//********************************************** 
void swap(int &value1, int &value2) 
{ 
	int temp = value1; 
	swaps++;
	value1 = value2; 
	value2 = temp; 
} 