// Program which accept file name and position from user and read 20 bytes from that position

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd,Ret=0;
	char Buffer[20]={'\0'};
	
	if(argc!=3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	lseek(fd,atoi(argv[2]),0);
	
	Ret=read(fd,Buffer,20);
	if(Ret==0)
	{
		printf("Unable to read data from file\n");
		return -1;
	}
	
	printf("Data from file is :\n");
	write(1,Buffer,Ret);
	printf("\n");
	
	close(fd);
	
	return 0;	
}

// ./Assignment6_5 Text1.txt 10
