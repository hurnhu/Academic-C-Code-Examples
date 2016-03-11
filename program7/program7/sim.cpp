#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <future>

#include "sim.h"
using namespace std;

/*
*below are all static varibles used in this class.
*static varibles has some major quarks in c++, you can
*have there defined in the header. BUT have to be declared
*outside of the header. this is to avoid having multiple
*static varibles for a class. next, you may ask why are 
*all of these static? the reason for that would be, to use
*a varible that is declared in the header in a async thread
*it has to be static. becuase all functions that are going
*to be ran by a new thread have to be static. i found a libaray
* called boost that i think fixes a lot of these quarks, but i digress
*/

char sim::lightNS = *"r";
char sim::lightEW = *"g";
bool sim::isRunning = true;
DynQueue<char> sim::north;
DynQueue<char> sim::east;
DynQueue<char> sim::south;
DynQueue<char> sim::west;
double CAR_NS = 1.0 / 5.0;  // Probability of new arrival each minute 
double CAR_EW = 1.0 / 25.0;  // Probability of new departure each minute 
int sim::carN = 0;
int sim::carS = 0;
int sim::carE = 0;
int sim::carW = 0;
int sim::avgTimeNS = 0;
int sim::avgTimeEW = 0;
int sim::fullTime = 0;



/*
*First thing is first, in the realm of the program
*1 hour = 1 sec, 1 min = ~16 milliseconds (16.667),
*1 sec = ~16 nanoseconds (16.667).
*/


const int HOUR = 1, MIN = 16, SEC = 16;


/*
*class deff light
*this function is a stop light function
*this flicks two "lights" from green to red
*only one at a time can be green.
*/
void sim::light(int n, int rNS, int rEW)
{


	while (isRunning)
	{

		if (lightNS == *"r")
		{
			lightNS = *"g";
			lightEW = *"r";

			//change light timing for rush hour, more time for ns
			if (fullTime >= 2 && fullTime <= 8)
			{
				this_thread::sleep_for( chrono::milliseconds(rNS));

			}
			else
			{
				this_thread::sleep_for( chrono::milliseconds(n));

			}

		}
		else if (lightNS == *"g")
		{
			lightNS = *"r";
			lightEW = *"g";
			//change light timing for rush hour, less time for ns
			if (fullTime >= 2 && fullTime <= 8)
			{
				this_thread::sleep_for( chrono::milliseconds(rEW));

			}
			else
			{
				this_thread::sleep_for( chrono::milliseconds(n));

			}
		}
	}
}

/*
*deff for dequeue
*the dequeue function will dequeue cars if their light is
*green. cars from north and south or east and west. can 
*deque at the same tie. 2 sec must pass befour next car can go
*/
void sim::dequeue()
{
	while (isRunning)
	{

		if (lightEW == *"g")
		{


			if (!east.isEmpty())
			{
				cout << "\r" << "LOADING \\\\";//use carrage return to "animate" spinner
				east.dequeue();
			}
			if (!west.isEmpty())
			{
				cout << "\r" << "LOADING ||";//use carrage return to "animate" spinner
				west.dequeue();
			}

			this_thread::sleep_for( chrono::nanoseconds(SEC * 2));


		}

		if (lightNS == *"g")
		{
			if (!south.isEmpty())
			{
				cout << "\r" << "LOADING --";//use carrage return to "animate" spinner
				south.dequeue();
			}
			if (!north.isEmpty())
			{
				cout << "\r" << "LOADING //";//use carrage return to "animate" spinner
				north.dequeue();
			}
			this_thread::sleep_for( chrono::nanoseconds(SEC * 2));

		}
	}

}

/*
*deff for enqueue
*this function will que up a car if ther
*light is green
*/
void sim::enqueue()
{
	double v2 = 0;

	while (isRunning)
	{
		int v1 = rand() % 2;
		int v3 = rand() % 1 + 1;

		v2 = (rand()) / double(RAND_MAX);

		//tests if it is probable for a car to arrive
		//if it is randomly choose what direction it came
		//from and que it on to the queue.
		//ALL THREADS NEED SOME SORT OF SLEEP IN THEM OR 
		//THEY WILL RUN RAMPANT, LEAVING A FEW THOUSAND CARS
		//UNPROCESSED. so it wait for 1/16th of a second or 62.5 miliseconds.

		if (v2 <= CAR_NS)
		{
			//cars are enqueue with the code "C", this would be used if this was expanded
			//to deal with c (cars), t (trucks), v (van). but right now this program only
			//deals with cars
			if (v1 == 0)
			{
				carN++;
				north.enqueue('c');
				this_thread::sleep_for( chrono::nanoseconds(v3));

			}
			else if (v1 == 1)
			{
				carS++;
				south.enqueue('c');
				this_thread::sleep_for( chrono::nanoseconds(v3));
			}
		}

		if (v2 <= CAR_EW)
		{

			if (v1 == 0)
			{
				carE++;
				east.enqueue('c');
				this_thread::sleep_for( chrono::nanoseconds(v3));
			}
			else if (v1 == 1)
			{
				carW++;
				west.enqueue('c');
				this_thread::sleep_for( chrono::nanoseconds(v3));
			}
		}
	}
}

/*
*deff traffic 
*this is the driver of this programm, this
*is where all threads are launched, and time
*is kept.
*/
void sim::trafic()
{
	//light timing, n = normal, rNS = rush hour north south, rEW = rush hour east west
	int normal = 1, RH_NS = 10, RH_EW = 1;

	this_thread::sleep_for( chrono::seconds(HOUR));
	
	//start all the threads
	auto trafficLight = async(launch::async, light, normal* MIN, RH_NS* MIN, RH_EW* MIN);
	auto leftRight =  async( launch::async, enqueue);
	auto upDown =  async( launch::async, dequeue);


	//depending on the random, you can have 10 cars
	//left over in north or south after ten hours.
	//due to the sudden stop of time. 
	while (fullTime != 10)
	{

		if (fullTime == 3)
		{
			CAR_NS = 1.0 / 10.0;//prob for car to show
			CAR_EW = 1.0 / 30.0;//prob for car to show
		}
		if (fullTime == 9)
		{
			CAR_NS = 1.0 / 5.0;//prob for car to show
			CAR_EW = 1.0 / 25.0;//prob for car to show
		}
		this_thread::sleep_for( chrono::seconds(HOUR));
		fullTime++;

	}
	isRunning = false;//stop all threads
	this_thread::sleep_for(chrono::nanoseconds(100));//wait so you dont get any output from a thread
	cout << endl << "cars processed " << carN << ", " <<
		carS << ", " << carE << ", " << carW << endl
		<< "cars left over after ten hours: " << endl;
	
	if (!north.isEmpty())
	{
		cout << "North: " << north.size() << endl;
	}
	if (!south.isEmpty())
	{
		cout << "south: " << south.size() << endl;
	}
	if (!east.isEmpty())
	{
		cout << "east: " << east.size() << endl;
	}
	if (!west.isEmpty())
	{
		cout << "west: " << west.size() << endl;
	}

	double t1 = (RH_NS + normal) /2.0, t2 = (RH_EW + normal) /2.0;
	cout << "\navg wait time for east/west " << t2 << ". avg wait time for nourth south " << t1 << endl;
	cout << "light timing for non rush hour. \n NS: " << normal << "\n EW: " << normal << endl;
	cout << "light timing for  rush hour. \n NS: " << RH_NS << "\n EW: " << RH_EW << endl;


}

sim::sim()
{
	srand(time(0));            // Set seed for random number to clock
}



