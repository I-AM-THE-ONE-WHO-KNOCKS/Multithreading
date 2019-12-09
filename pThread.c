#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *v)
{
	sleep(1);
	printf("printing quiz from thread \n");
	return NULL;
}

int main()
{
	pthread_t t_id;
	printf("before thread\n");
	pthread_create(&t_id, NULL, myThreadFun, NULL);
	pthread_join(t_id, NULL);
	printf("after thread\n");
	exit(0);
}
