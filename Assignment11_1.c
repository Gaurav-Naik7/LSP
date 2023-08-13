// Program which creates four threads and our main thread waits till all the threads terminate

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
	printf("Inside thread 1\n");
}

void * ThreadProc2(void *ptr)
{
	printf("Inside thread 2\n");
}

void * ThreadProc3(void *ptr)
{
	printf("Inside thread 3\n");
}

void * ThreadProc4(void *ptr)
{
	printf("Inside thread 4\n");
}

int main()
{
	
	pthread_t TID1,TID2,TID3,TID4;
	int ret1,ret2,ret3,ret4=0;
	
	ret1=pthread_create(&TID1,NULL,ThreadProc1,NULL);
	
	if(ret1!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread1 is created with ID : %ld\n",TID1);
	
	ret2=pthread_create(&TID2,NULL,ThreadProc2,NULL);
	
	if(ret2!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread2 is created with ID : %ld\n",TID2);
	
	ret3=pthread_create(&TID3,NULL,ThreadProc3,NULL);
	
	if(ret3!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread3 is created with ID : %ld\n",TID3);
	
	ret4=pthread_create(&TID4,NULL,ThreadProc4,NULL);
	
	if(ret4!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread4 is created with ID : %ld\n",TID4);
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	pthread_join(TID3,NULL);
	pthread_join(TID4,NULL);
	
	printf("End of main thread\n");
	
	pthread_exit(NULL);
	return 0;
}
