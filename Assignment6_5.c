// Program which accept file name from the user and offset,remove all data after that offset

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int fd,offset,Ret=0;
	
	if(argc!=3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDWR);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	offset=atoi(argv[2]);
	
	Ret=ftruncate(fd,offset);
	
	if(Ret==0)
	{
		printf("File sucessfully truncated\n");
	}
	

	close(fd);
	
	return 0;	
}

// ./Assignment6_5 Text1.txt 10
