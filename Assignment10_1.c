// Program which is used to create simple thread by using pthread library

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	printf("Inside thread\n");
}

int main()
{
	
	pthread_t TID;
	int ret=0;
	
	ret=pthread_create(&TID,NULL,ThreadProc,NULL);
	
	if(ret!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID : %ld\n",TID);
	
	pthread_join(TID,NULL);
	
	printf("End of main thread\n");
	
	return 0;
}
