#include<iostream>
#include<thread>
#include<mutex>

using namespace std;
mutex mtx;
void call(int id)
{
	mtx.lock();
        cout<<"launching thread: "<<id<<endl;
	mtx.unlock();
}
int main()
{
        thread id[10];

        for(int i = 0; i < 10; i++)
        {
                id[i] = thread(call, i);
        }

	mtx.lock();
        cout<<"In main thread"<<endl;
	mtx.unlock();

        for(int i = 0; i < 10; i++)
        {
                id[i].join();
        }

        return 0;
}
/*
 * now you will see the synchronization of execution
 * see how we have used the mutex lock in the critical section.
 *
 * critical section is the section in code which is being accessed by multiple threads
 * An Important thing to be noted here is we just make sure that only one of the thread access the critical section but not which one.
 * What it means this not garunty that the threads will get executed sequencially. if you try the execution this code multiple times you might see the shift of one thread ahead of another one.
 *
 * /
