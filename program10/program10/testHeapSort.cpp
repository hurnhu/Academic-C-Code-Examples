// This program demonstrates the HeapSort algorithm on a list 
// of integers 

#include <iostream> 
#include <string>
#include <fstream>
using namespace std; 

#include "heapSort.cpp" 

// Function prototypes 
void DisplayList(int[],int); 

void GetList(int[],int&,int,string); 
const int MAX_LIST_SIZE = 100;      // Max list size 
int HPS() 
{ 
	int InList[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize;                   // Index of last list element 

	int InList2[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize2;                   // Index of last list element  

	int InList3[MAX_LIST_SIZE];   // Array of list elements 
	int ListSize3;                   // Index of last list element 

	//    HeapSort(InList,ListSize); 

	GetList(InList,ListSize,MAX_LIST_SIZE, "Almost.txt"); 
	HeapSort(InList,100); 

	GetList(InList2,ListSize2,MAX_LIST_SIZE, "Inverse.txt"); 
	HeapSort(InList2,100); 

	GetList(InList3,ListSize3,MAX_LIST_SIZE, "Random.txt");	
	HeapSort(InList3,100); 
    // Write list after sort 
    cout << endl << "AFTER" << endl; 
    DisplayList(InList,ListSize); 
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


/************************************************************/ 
/* This function writes a list to console output:  one list */ 
/* item at a time.                                  */ 
/************************************************************/ 
void DisplayList(int theList[],int listsize) 
{ 
   for (int i = 0;i < listsize; i++) 
      cout << theList[i] << ' '; 
   cout  << endl; 
} 
