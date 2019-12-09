#include<iostream>
#include<thread>

using namespace std;

int main()
{
	unsigned int c = std::thread::hardware_concurrency();
	std::cout <<"num of cores: "<< c <<endl;
	return 0;
}
