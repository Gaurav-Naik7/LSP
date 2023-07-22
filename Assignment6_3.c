// Program which accept directory name and file name from user and create file in that directory 

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	int fd=0;
	char path[50];

	if(argc!=3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	sprintf(path,"%s/%s",argv[1],argv[2]);
	
	fd=creat(path,0777);
	
	if(fd==-1)
	{
		printf("Unable to create file\n");
		return -1;
	}
	else
	{
		printf("File %s is sucessfully created\n",argv[2]);
	}


	return 0;
}

// ./Assignment6_3 Demo Text5.txt
