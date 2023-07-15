// Program which accepts file name and mode from user and opens that file in specified mode 
// Check whether our process can access that file in accepted mode or not

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	int fd=0;
	int Ret=0;
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
	
	printf("File name: %s\n",argv[1]);
	printf("Mode: %d\n",Mode);
	
	
	fd=open(argv[1],Mode);
	
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	Ret=access(argv[1],Mode);
	
	if(Ret==-1)
	{
		printf("Unable to open the file in %s mode\n",argv[2]);
	}
	else
	{
		printf("File sucessfully opened in %s mode\n",argv[2]);
	}
	
	return 0;
}

// ./Assignment1_4 Input.txt Write





