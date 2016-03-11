// Class to manage "tokenized" data (comma-separated files) 

#include<iostream> 
#include<string> 
using namespace std; 

#include "StringTokenizer.h" 

// Constructor 
// Receive line of comma-delimited data and set index of current 
// token to zero 
StringTokenizer::StringTokenizer(string line) 
{ 
   theLine = line; 
   currIndex = 0; 
   delimiterChar = ',';     // Default delimiter is comma 
} 

// Parameterized constructor - accepts a character other than a comma 
// as delimiter. 
// Precondition: separator is a single character (non-space) 
// Postcondtion: data string NOT initialized 
StringTokenizer::StringTokenizer(char newDelimiter) 
{ 
   currIndex = 0; 
   delimiterChar = newDelimiter;    // Set delimiter to programmer choice 
} 

// Parameterized constructor - accepts an initial string to parse and 
// a character other than a comma as delimiter. 
// Precondition: separator is a single character (non-space) 
StringTokenizer::StringTokenizer(string line, char newDelimiter) 
{ 
   theLine = line; 
   currIndex = 0; 
   delimiterChar = newDelimiter;   // Set delimiter to programmer choice 
} 

// "Set" and "Get" functhions 
void StringTokenizer::setLine(string line) 
{ 
   theLine = line; 
} 

string StringTokenizer:: getLine() 
{ 
   return theLine; 
} 

// Reset index of current token to zero 
void StringTokenizer::reset() 
{ 
   currIndex = 0; 
} 

// Return number of tokens in current string 
int StringTokenizer::numberTokens() 
{ 
   int lineLength = theLine.length(); 
   int count = 0; 
      
   for (int i = 0; i < lineLength; i++) 
      if (theLine.at(i) == delimiterChar) 
         count++; 
          
   return count + 1;    // Return number of tokens as number of commas + 1 
} 

// To observe if token pointer is at end of string 
bool StringTokenizer::atEnd() 
{ 
   if (currIndex == theLine.length()) 
      return true; 
   else 
      return false; 
} 

// Return next token as a string object 
// Precondition: Token pointer is not at end of string 
string StringTokenizer::getStringToken() 
{ 
   get_a_Token(); 
   return tempString; 
} 

// Return next token as a character object 
// Precondition: Token pointer is not at end of string 
char StringTokenizer::getCharToken() 
{ 
   char outChar; 
    
   get_a_Token();                 
   outChar = tempString[0];                   // Extract one char from string 
    
   return outChar; 
} 

// Return next token as a double value 
// Precondition: Token pointer is not at end of string 
double StringTokenizer::getDoubleToken() 
{ 
   double outValue; 
    
   get_a_Token(); 

   outValue = atof(tempString.data());     // Convert to number 
   return outValue; 
} 

// Returns an integer value being referenced 
int StringTokenizer::getIntToken() 
{ 
   int outInt; 
    
   get_a_Token(); 

   outInt = atoi(tempString.data());        // Convert to number 
   return outInt; 
}     

// This utility function retrieves the next token and returns it to 
// be correctly typed before the final return from the object function call 
void StringTokenizer::get_a_Token() 
{ 
   int newIndex = theLine.find(delimiterChar,currIndex); 
     
   if (newIndex >= 0)   // If not last token 
   { 
      tempString = theLine.substr(currIndex,newIndex - currIndex); 
      currIndex = newIndex + 1;        // Advance to position after next comma 
   } 
   else    // If last token 
   { 
      tempString =  theLine.substr(currIndex,theLine.length() - currIndex); 
      currIndex = theLine.length();    // Set current index to end 
   } 
} 
