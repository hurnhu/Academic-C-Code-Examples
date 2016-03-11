#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "dynQueue.h"
using namespace std;

/*
*deff for the sim class
* holds everything needed to hold
*cars for 4 different roads and to
*processes (stoplight) though the cars
*waiting for a green light
*/
class sim

{

private:
	static DynQueue<char> north;
	static DynQueue<char> south;
	static DynQueue<char> east;
	static DynQueue<char> west;
	static char lightNS;
	static char lightEW;
	static bool isRunning;
	static int carN;
	static int carS;
	static int carE;
	static int carW;
	static int avgTimeNS;
	static int avgTimeEW;
	static int fullTime;


public:
	sim();
	void trafic();
	static void enqueue();
	static void dequeue();
	static void light(int n, int rNS, int rEW);
};
