#include<iostream>
#include<mpi.h>

using namespace std;

int main(int argc, char* argv[])
{
	// unique rank is assigned to each process in a communicator
	int rank;

	//total num of ranks
	int size;

	//name of the machine
	char name[80];

	//len of the machine name
	int len;

	//Initialize the MPI execution environment
	MPI_Init(&argc, &argv);

	//Get the process rank
	//MPI_COMM_WORLD is the default communicator
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	//get the total num of ranks
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	//get the name of processor 
	//Implementation specific (may be hostname, uname or sysinfo)
	MPI_Get_processor_name(name, &len);
	
	//print
	cout<<"Hello, MPI Rank : "<<rank<<" Size : "<<size<<" on "<<name<<endl;

	//terminate MPI execution environment
	MPI_Finalize();

	return 0;
}
