// Program which accept directory name from user and create new directory of that name

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	int Ret=0;
	
	if(argc!=2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	Ret=mkdir(argv[1],0777);
	
	if(Ret!=0)
	{
		printf("Unable to create directory");
	}
	
	return 0;	
}

// ./Assignment4_2 Demo
