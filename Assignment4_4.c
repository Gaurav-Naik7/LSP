// Program which accept directory name from user and copy first 10 bytes from all regular files into newly created file

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *dp = NULL;
	struct dirent * entry = NULL;
	struct stat sobj;
	char name[30];
	int fdsource, fd, Ret=0;
	char *Buffer=NULL;
	char filename[9];
	
	if(argc!=2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	dp=opendir(argv[1]);
	if(dp==NULL)
	{
		printf("Unable to open directory\n");
		return -1;	
	}
	
	strcpy(filename,"Demo.txt");

	fd=creat(filename,0777);
	if(fd==-1)
	{
		printf("Unable to open Demo.txt\n");
		return -1;
	}
	
	Buffer=(char*)malloc(10);
	
	while((entry = readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			fdsource=open(name,O_RDONLY);
			if(fd==-1)
			{
				printf("Unable to open %s",name);
				return -1;
			}
			Ret=read(fdsource,Buffer,10);
			write(fd,Buffer,10);
		}
	}
}

// ./Assignment4_2 Demo
