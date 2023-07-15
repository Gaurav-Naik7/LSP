// Program which accepts file name and number of bytes from user and read that many bytes from the file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int Ret=0;
	int Size=0;
	char *Buffer=NULL;
	
	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd==-1)
	{
		printf("Unable to open file\n");
	}
	
	Size=sizeof(atoi(argv[2]));
	Buffer=(char *)malloc(Size);
	
	Ret=read(fd,Buffer,atoi(argv[2]));
	if(Ret==0)
	{
		printf("Unable to read the data from file\n");
		return -1;
	}
	
	printf("Data from file is : %s\n",Buffer);
	return 0;
}

// ./Assignment1_5 Input.txt 10
