#include<iostream>
#include<thread>

using namespace std;

void call(int id)
{
	cout<<"launching thread: "<<id<<endl;
}
int main()
{
	thread id[10];

	for(int i = 0; i < 10; i++)
	{
		id[i] = thread(call, i);
	}

	cout<<"In main thread"<<endl;

	for(int i = 0; i < 10; i++)
	{
		id[i].join();
	}

	return 0;
}

/*
 * The reason you see the result of cout something unexpected is because cout is not thread safe it puts the result on the output immedeatly.
 * Also, this is totally dependent on how scheduling is done
 * This makes the debugging and understanding the result difficult
 *
 * These are the reasons we go for synchronization in threading.
 *
 * There are couple of things here:
 * Concurrency and Parallelism 
 *
 * Concurrency: means different things executing at the multiple stage at the same time that does not necessarily  means they are running at the same time. Means threads are at different stage of execution.
 *
 * Parallelism: means running multiple things at the same time
 */
