#include "wrap.h"
#include <fstream> 
#include <iostream> 
#include <string> 
#include <sstream>
using namespace std;


//on obj creation call makeBST, to make the trees
wrap::wrap()
{
	makeBST();
}

/*
*this will populate the transation BST. this has to be 
*called after the people tree is populated. becuase i do
*a look up for each of the peoples names and match, then store 
*them in the amatrans obj as it goes into this tree
*/
void wrap::popTransBST()
{
	//my temp vars
	string aWord;
	amazonTrans temp;
	person tempP;
	int i = 0;

	// Open word list file 
	ifstream wordFile("transactions.txt");
	if (wordFile.fail())
	{
		cout << "Problem opening document file";
		exit(-1);
	}
	int q = 0;

	// Build list of words in document 
	wordFile >> aWord;                // Get first word 
	while (!wordFile.eof())
	{
		stringstream ss(aWord);
		string s;

		//split word appart at the comma
		while (getline(ss, s, ',')) 
		{
			//split the word and then place it into the obj
			if (i == 0)
			{
				temp.setCustomerID(atoi(s.c_str()));
			}
			else if (i == 1)
			{
				temp.setTransactionAmount(atoi(s.c_str()));
			}
			else if (i == 2)
			{

				//convert the day from YY-MM-DD to MM/DD/YYY
				string month, day, year;
				stringstream sss(s);
				string ll;
				int po = 0;

				//break the string apart at the - 
				while (getline(sss, ll, '-'))
				{
					if (po == 0)
					{
						year = ll;
					}
					else if (po == 1)
					{
						month = ll;
					}
					else if (po == 2)
					{
						day = ll;
						po = -1;
					}
					po++;
				}

				//build the new date string
				temp.setDate(month+"/"+day+"/"+year);
				i = -1;
			}

			i++;
		}

		//set the temp persons transid
		tempP.setTransID(temp.getCustomerID());

		//check to see if the person is in the tree
		if (personTree.searchNode(tempP))
		{
			//if they are it returns that person
			//then sets the name of the person in the
			//temp transction
			tempP = personTree.get(tempP);
			temp.setFName(tempP.getFName());
			temp.setLName(tempP.getLName());

		}
		else
		{
			//did not find
			//profound error would go here in
			//business world
		}

		// add the temp transtion to the trans tree

		transTree.insertNode(temp);    

		//move to next word
		wordFile >> aWord;            
	}

	//after all is done close
	wordFile.close();
}

//this will find a transction in the bst
void wrap::find(int toFind, string findIt)
{
	amazonTrans temp;
	amazonTrans temp2;

	//build temp transction
	temp.setCustomerID(toFind);
	temp.setTransID(toFind);
	temp.setDate(findIt);
	transTree.findme(temp);
}

//this will call the populate bst's
//they have to be called in this order
void wrap::makeBST()
{
	popPepsBST();
	popTransBST();
}

/*
*this will populate the people BST. read info in
*from the file puts it into people objs, then to tree
*/
void wrap::popPepsBST()
{
	//temp things to hold info
	string aWord;
	person temp;
	int i = 0;
	// Open word list file 
	ifstream wordFile("nameid.txt");
	if (wordFile.fail())
	{
		cout << "Problem opening document file";
		exit(-1);
	}

	// Get first word 
	wordFile >> aWord;               
	while (!wordFile.eof())
	{
		stringstream ss(aWord);
		string s;
		//split word appart at the comma
		while (getline(ss, s, ',')) 
		{
			//build the new person 
			//everything is being split at the comma
			if (i == 0)
			{
				temp.setFName(s);

			}
			else if (i == 1)
			{
				temp.setLName(s);
			}
			else if (i == 2)
			{
				temp.setTransID(atoi(s.c_str()));

				i = -1;
			}
			i++;

		}
		//add the new person to the tree
		personTree.insertNode(temp);   

		// Get next word 
		wordFile >> aWord;             
	}
	//close the file
	wordFile.close();
}



