// Write a program which creates two threads by using pthread API, where one thread count number of capital characters from Demo.txt and other thread counts number of small characters from the same file. 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
	char Buffer[512];
	int iCnt=0,iRet=0,i=0;
	
	lseek((int)ptr,0,SEEK_SET);
	
	while((iRet=read((int)ptr,Buffer,sizeof(Buffer)))!=0)
	{
		for(i=0;i<iRet;i++)
		{
		if ((Buffer[i]>='a')&&(Buffer[i]<='z'))
			{
				iCnt++;
			}
		}
	}
	
	printf("Number of small characters are : %d\n",iCnt);
	
	pthread_exit(NULL);
}

void * ThreadProc2(void *ptr)
{
	char Buffer[512];
	int iCnt=0,iRet=0,i=0;
	
	lseek((int)ptr,0,SEEK_SET);
	
	while((iRet=read((int)ptr,Buffer,sizeof(Buffer)))!=0)
	{
		for(i=0;i<iRet;i++)
		{
		if ((Buffer[i]>='A')&&(Buffer[i]<='Z'))
			{
				iCnt++;
			}
		}
	}
	
	printf("Number of capital characters are : %d\n",iCnt);
	
	pthread_exit(NULL);
}

int main()
{
	
	pthread_t TID1,TID2;
	int ret1=0,ret2=0,fd=0;
	
	fd=open("Demo.txt",O_RDONLY);
	
	ret1=pthread_create(&TID1,NULL,ThreadProc1,(int *)fd);
	
	if(ret1!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread1 is created with TID1 : %ld\n",TID1);
	
	ret2=pthread_create(&TID2,NULL,ThreadProc2,(int *)fd);
	
	if(ret2!=0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	
	printf("Thread2 is created with TID2 : %ld\n",TID2);
	
	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);
	
	close(fd);
	
	printf("End of main thread\n");
		
	pthread_exit(NULL);
	return 0;
}
