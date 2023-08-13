// Program which is used to get thread id inside its thread function

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	pthread_t TID = pthread_self();
	printf("Thread ID of the thread is %ld\n",TID);
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
