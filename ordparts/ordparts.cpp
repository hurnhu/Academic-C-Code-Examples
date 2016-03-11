// This program manages a list of parts.

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Attributes for one part
struct partInfo
{
   int number;
   char name[30];
   double weight;
   double price;
};

const int MAX_LIST_SIZE = 100;

// Function prototypes
int menu();
void buildPartsList(partInfo partList[], int& listSize);
void searchParts(partInfo partList[], int numParts);
void listParts(partInfo partList[], int& numParts);
void insertPart(partInfo list[], int& numElems);
void deletePart(partInfo list[], int& numElems);
partInfo getPartInfo();
void writeColumnHeading();
void writeLineReport(partInfo aPart);
void writePartsList(partInfo partList[], int listSize);

//----------------------------------------------------------------------
// MAIN PROGRAM
int main()
{
   int action;                         // User menu choice
   partInfo partList[MAX_LIST_SIZE];   // Main list of parts
   int numParts;                       // Size of parts list

   buildPartsList(partList,numParts);  // Read parts list from file

   do
   {
      action = menu();                 // Prompt for user choice
      
      switch(action)                   // Take action on user choice
      {
         case 1:   searchParts(partList,numParts);  
                   break;
         case 2:   insertPart(partList,numParts);
                   break;
         case 3:   deletePart(partList,numParts);
                   break;
         case 4:   listParts(partList,numParts);  
                   break;
      };
   }   
   while (action != 5);                 // If not "quit" repeat

   // Otherwise exit
   writePartsList(partList,numParts);   // Write list to file
   cout << endl << "THANK YOU - Good Bye" << endl << endl;
   return 0;
}

//----------------------------------------------------------------------
// This function prints the menu, prompts the user for
// a choice, and returns the choice to the calling routine.
int menu()
{
   int choice;

   cout << "PART MANAGEMENT SYSTEM          " << endl;
   cout << "  1)  To FIND part information  " << endl;
   cout << "  2)  To ADD a new part         " << endl;
   cout << "  3)  To DELETE an existing part" << endl;
   cout << "  4)  To LIST entire part set   " << endl;
   cout << "  5)  To QUIT                   " << endl;

   do
   {
      cout << "ENTER choice: ";
      cin  >> choice;
   
      if (choice < 1 || choice > 5)
         cout << "Invalid selection - please re-enter" << endl << endl;
   } while (choice < 1 || choice > 5);
   
   return choice;
}

//----------------------------------------------------------------------
// This function reads a list of parts from a file and populates
// and array of part records 
void buildPartsList(partInfo partList[], int& listSize)
{
   // Declarations
   partInfo aPart;
   ifstream InFile ("partList.txt");
    
   if ( InFile.fail() )             // Test for file existence
   {
      cout <<  "Problem opening file";
      exit(-1);
   }

   int i = 0;
   InFile >> aPart.number >> aPart.name  >> aPart.weight >> aPart.price;
   while( !InFile.eof() && i < MAX_LIST_SIZE)
   {
      partList[i] = aPart;
      i++;
      InFile >> aPart.number >> aPart.name  >> aPart.weight >> aPart.price;
   }
   listSize = i;     // Size of list is number of parts
   
   InFile.close();
}

//----------------------------------------------------------------------
// This function searches the current parts list for a given part.
// The part number is passed as the key.  A linear search routine
// is utilized.
void searchParts(partInfo partList[], int numParts)
{
   int partNumberKey;

   cout << endl;
   cout << "Enter part number: ";     // Prompt for part number
   cin  >> partNumberKey;

    int index = 0;            // Used as a subscript to search array
    int position = -1;        // To record position of search value
    bool found = false;       // Flag to indicate if the value was found

    while (index < numParts && !found)
    {
        if (partList[index].number == partNumberKey)   // If the value is found
        {
            found = true;            // Set the flag
            position = index;        // Record the value's subscript
        }
        index++;                     // Go to the next element
    }
 
    if (position >= 0)
    {
       writeColumnHeading();                    // Print heading
       writeLineReport(partList[position]);
    }
    else
       cout << "Part Not Found" << endl;
       
    cout << endl;
}

//----------------------------------------------------------------------
// This function writes the current parts list to the console
void listParts(partInfo partList[], int& numParts)
{
   writeColumnHeading();                    // Print heading
   for (int i = 0; i < numParts; i++)
   {
      writeLineReport(partList[i]);         // Write line
   }
   cout << endl;
}

//----------------------------------------------------------------------
// This function inserts a new part record into the list 
void insertPart(partInfo list[], int& numElems)
{
   partInfo aPart;
   int index = 0;

   // Get info for new part
   aPart = getPartInfo();
      
	while (aPart.number > list[index].number)
	{
		index++;
	}

	for (int cindex = numElems; cindex > index; cindex--)
	{
		list[cindex] = list[cindex - 1];
	}

	list[index] = aPart;
      
   // Adjust number of elements in list  
   numElems++;                                 
}

//----------------------------------------------------------------------
// This function deletes an existing record from the list using part
// number as key.   
void deletePart(partInfo list[], int& numElems)
{
   partInfo aPart;

   // Prompt user for part number to delete
   cout << endl;
   cout << "Enter part number to delete: ";
   cin  >> aPart.number;

   // Search for and delete part
   int ptr = 0;                                   // Scan list for deletion target
   while (aPart.number != list[ptr].number && ptr < numElems)    
       ptr++;
               
   if (ptr < numElems)                       // If target found, then
   {
	   for (int index = ptr; index < numElems - 1; index++)
	   {
		   list[index] = list[index + 1];
	   }

      numElems--;                           // Decrement size of list                                 
   }

   // Notify user 
   cout << "Part " << aPart.number << " deleted" << endl << endl;                               
 }

//----------------------------------------------------------------------
// This function prompts a user for part information and returns a 
// record back to the calling routine
partInfo getPartInfo()
{
   partInfo aPart;
   cout << endl;
   cout << "Enter part number: ";          // Part number
   cin  >> aPart.number;
   cout << "Enter part name (one word): "; // Part number
   cin  >> aPart.name;
   cout << "Enter part weight: ";          // Part weight
   cin  >> aPart.weight; 
   cout << "Enter part price: ";           // Part price
   cin  >> aPart.price;
   
   cout << endl;
   
   return aPart;
}

//----------------------------------------------------------------------
// This function prints the column heading for a part summary report
void writeColumnHeading()
{
   cout << endl << "PART  NAME        WEIGHT  PRICE" << endl;  
}

//----------------------------------------------------------------------
// This function prints the column heading for a part summary report
void writeLineReport(partInfo aPart)
{
   // Set up for formatted output
   cout.setf(ios::fixed,ios::floatfield);   
   cout.setf(ios::showpoint);               
     
   cout << setw(4)  << aPart.number << "  ";
   cout.unsetf(ios::right);                    // Un-do default right justify
   cout.setf(ios::left);                       // Left-justify for name field   
   cout << setw(12) << aPart.name;
   cout.setf(ios::right);                     // Reset to right-justify for numbers  
   cout << setw(5)  << setprecision(1) << aPart.weight
        << setw(8)  << setprecision(2) << aPart.price
        << endl;
}

//----------------------------------------------------------------------
// This function writes the current parts list to an external text file.
void writePartsList(partInfo partList[], int listSize)
{
   ofstream outFile ("partListOut.txt");

   for (int i = 0; i < listSize; i++)         // Write all records to file
      outFile << partList[i].number << "  " 
              << partList[i].name   << "  " 
              << partList[i].weight << "  " 
              << setprecision(2) << partList[i].price  << endl;
              
   outFile.close();                           // Close file

} 