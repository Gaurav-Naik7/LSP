// Program which is used to create simple thread and it accepts one value from user and return some value to caller thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void * ThreadProc(void *ptr)
{
	int no=0;
	printf("Enter a number: \n");
	scanf("%d",&no);
	pthread_exit(++no);
}

int main()
{
	
	pthread_t TID;
	int ret=0;
	int value=0;
	
	ret=pthread_create(&TID,NULL,ThreadProc,NULL);
	
	if(ret!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread is created with ID : %ld\n",TID);
	
	pthread_join(TID,&value);
	
	printf("Value received from thread is %d\n",value);
	
	printf("End of main thread\n");
	
	return 0;
}
