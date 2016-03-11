/************************************************************/ 
/* This program demonstrates a bubble sort algorithm        */ 
/* to sort an unordered list read in from a data file       */ 
/* Author:  T. Klingler                                     */ 
/************************************************************/ 
#include <iostream> 
#include <string>
#include <fstream>
using namespace std; 


void sortArray(int Array[], int Elems); 
void DisplayList(int theList[],int listsize); 


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
	sortArray(InList,100); 
	cout<< swaps << " " << comps << endl;

	GetList(InList2,ListSize2,MAX_LIST_SIZE, "Inverse.txt"); 
	sortArray(InList2,100); 
	cout<< swaps << " " << comps << endl;

	GetList(InList3,ListSize3,MAX_LIST_SIZE, "Random.txt");	
	sortArray(InList3,100); 
	cout<< swaps << " " << comps << endl;   
     
     
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
/* item at a time.                                          */ 
/************************************************************/ 
void DisplayList(int theList[],int listsize) 
{ 
    for (int i = 0;i < listsize; i++) 
        cout << theList[i] << " "; 
    cout << endl; 
} 


/************************************************************/ 
/* This function receives a list of values of type int      */ 
/* as an array.  The function performs a bubble sort and    */ 
/* returns the list in ascending order.  The sorting is     */ 
/* halted if no swaps are made in any given pass.           */ 
/* Note:  elems is number of elements in list               */ 
/************************************************************/ 
void sortArray(int array[], int elems) 
{ 
    bool swap; 
    int temp; 
     
    int end = elems - 1;   // To control stopping point 

    do 
    { 
       swap = false;        // Assume no swap this pass 
       for (int count = 0; count < end; count++) 
       { 
		   comps++;
          if (array[count] > array[count + 1]) 
          { 
			  swaps++;
             temp = array[count]; 
             array[count] = array[count + 1]; 
             array[count + 1] = temp; 
             swap = true;   // Mark that swap occured   
          } 
       }      
       end--;    // Move stopping point up 
       
     // Continue if a swap occurred that pass 
   } while (swap);  
} 
