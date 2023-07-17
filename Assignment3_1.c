// Program which accepts file name from user and copy contents of existing file into newly created file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
	int fd=0,fdDest=0;
	int Ret=0;
	char Buffer[BLOCKSIZE];
	
	if(argc!=3)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	if(fd==-1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	fdDest=creat(argv[2],0777);
	if(fdDest==-1)
	{
		printf("Unable to create destination file\n");
		close(fd);
		return -1;
	}
	
	while((Ret=read(fd,Buffer,sizeof(Buffer)))!=0)
	{
		write(fdDest,Buffer,Ret);
		memset(Buffer,0,sizeof(Buffer));
	}
	
	return 0;
}

// ./Assignment3_1 Input.txt Input1.txt
