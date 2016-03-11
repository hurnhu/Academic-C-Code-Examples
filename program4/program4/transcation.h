#include<string> 
using namespace std;
class transcatoin

	//this class will contain a breif discription for each method. for a 
	// more indepth disc please check the meathod in the cpp.
	// this is a class for holding and parsing data for number of transtaions
{
private:
	string toParse, weekArray[11000][3], max[4], min[4];
	int dayArray[72], row, col, weak;

public:
	transcatoin();//sets all to zero
	void setWeekArray(int type, int day, int place); //allows a user to manually set a place in the array
	void setToParse(string toParseTemp); //sets the string that needs to be parsed

	string getWeekArray(int col, int row); //will return what is at specified place
	string getToParse(); // will return the string that needs to be parsed

	void parse();//parses the string read from the file, removes the comma and inserts into 2D weekArray

	void display(); //calculates the totals for all transcatoins

	int stringToInt(string toConvert);// converts a string to and int using string streams

	int totals(int start); // displays the totals for each row
	void totalsCol(int t);// displays totals for each colum
	void minT();//finds the max transcatoin
	void maxT();//finds the min transcatoin
	string intToString(int toConvert);//converts a int to a string using string streams
};

