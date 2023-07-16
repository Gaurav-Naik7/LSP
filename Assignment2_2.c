// Program which accepts file name from user and write string in that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int Ret=0;
	int fdest=0;
	int Size=0;
	char *Buffer=NULL;

	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	Size=atoi(argv[2]);
	
	Buffer=(char*)malloc(Size);
	
	strcpy(Buffer,argv[2]);
	
	fdest=creat(argv[1],0777);
	
	if(fdest==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	printf("%s\n",Buffer);
	printf("%ld",strlen(Buffer));

	write(fdest,Buffer,strlen(Buffer));

	return 0;
}

// ./Assignment2_2 Input.txt
