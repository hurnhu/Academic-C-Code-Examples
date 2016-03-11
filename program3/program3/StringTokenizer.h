#ifndef STRING_TOKENIZER_H 
#define STRING_TOKENIZER_H 

// This class is designed to manage a line of "tokenized" data  
// (comma-separated files).  The primary class data member is a 
// string object.  It includes the ability to reset the delimiter 
// from a comma to a different character. 

// Strategy: programmer must "reset" the token "pointer" to begin. 
// Then, by calling one of the "get" function, they can return the 
// next data token separated by the current and next comma (or endline). 

// Precondition:  Class user has knowledge of number and types 
// of tokens in data. 

#include<string> 
using namespace std; 

class StringTokenizer 
{ 
   private: 
      string theLine;        // String containing raw data 
      int currIndex;         // Index of current token in focus 
      string tempString;     // Temporary holding string for token work 
      char delimiterChar;    // Character that is delimiter (default: comma) 
       
      void get_a_Token();    // Utility function to extract string tokens 

   public: 
      // Default constructor - accepts comma-delimited string to parse 
      StringTokenizer(string); 

      // Parameterized constructor - accepts a character other than a comma 
      // as delimiter. 
      // Precondition: separator is a single character (non-space) 
      StringTokenizer(char); 

      // Parameterized constructor - accepts an initial string to parse and 
      // a character other than a comma as delimiter. 
      // Precondition: separator is a single character (non-space) 
      StringTokenizer(string, char); 

      // "Set" and "Get" functhions 
      void setLine(string); 
      string getLine(); 
       
      // Iterator to reset token sequence to first token 
      void reset(); 
       
      // Returns total number of tokens in line (number of commas + 1) 
      int numberTokens(); 
       
      // Observes if pointer to current token is at end of string 
      bool atEnd(); 
       
      // Functions to return data tokens based on type 
      string getStringToken(); // Returns a string token being referenced 
      char getCharToken();     // Returns an character value being referenced 
      double getDoubleToken(); // Returns a double value being referenced 
      int getIntToken();       // Returns an integer value being referenced 
}; 

#endif 
