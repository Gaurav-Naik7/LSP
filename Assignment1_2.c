// Program which accepts file name and mode from user and opens that file in specified mode

#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int Mode=0;
	
	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"Read")==0)
	{
		Mode=O_RDONLY;
	}
	
	else if(strcmp(argv[2],"Write")==0)
	{
		Mode=O_WRONLY;
	}
	else
	{
		Mode=O_RDONLY;
	}
	
	fd=open(argv[1],Mode);
	
	if(fd==-1)
	{
		printf("Unable to open file\n");
	}
	else
	{
		printf("File sucessfully opened with file descriptor : %d\n",fd);
	}
	
	return 0;
}

// ./Assignment1_2 Input.txt Read





