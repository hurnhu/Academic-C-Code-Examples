#include <string>
#include <iostream>
#include <thread>
#include <future>         // std::async, std::future
using namespace std;

//The function we want to make the thread run.
void task1(string msg)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "task1 says: " << msg << endl;

	}
}
//The function we want to make the thread run.
void task2(string msg)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "task2 says: " << msg << endl;

	}
}


int main ()
{
	// call is_prime(313222313) asynchronously:
	future<void> fut = async (task1,"1");
	future<void> fut2 = async (task2,"2");
	for (int i = 0; i < 10; i++)
	{

		cout << "3" << endl;		
		fut.wait();
		fut2.wait();

	}

	// std::cout << "Checking whether 313222313 is prime.\n";
	// ...

	// bool ret = fut.get();      // waits for is_prime to return

	// if (ret) std::cout << "It is prime!\n";
	// else std::cout << "It is not prime.\n";
	system("pause");
	return 0;
}
