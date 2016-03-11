#include "project2.h"

using namespace std;
//class interact is basicly a bag type in a game.
//said bag has 4 things in it. the weight the bag
//can hold, the id of the bag, and the number
//of spaces the bag can hold and if the bag is broken
//or not.
class interact
{
private:
	int bagId;
	int invSpaces;
	double invMaxWeigt;
	int isBroken;

public:

	//zeros out the new obj
	interact();

	//sets the bag id
	void setBagId(int id);
	//sets the amt of inv spaces
	void setInvSpaces(int space);
	//set the max weight the bag can hold
	void setInvMaxWeight(double weight);
	//sets if the bag is broken or not.
	void setStateOfDecay(int isBkn);

	//returns the bag id
	int getBagId();
	//returns the amt of inv spaces
	int getInvSpaces();
	//returns the max weight this bag can hold
	double getInvMaxWeight();
	//returns a true or false, if the bag is broken
	int getStateOfDecay();
};
