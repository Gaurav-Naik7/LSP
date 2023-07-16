// Program which accept directory name from user and print all file names and it's types from that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent * entry=NULL;
	struct stat sobj;
	char name[30];
	
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
	
	
	while((entry=readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			printf("File name : %s \n",name);
			printf("It is a regular file\n");
		}
		else if(S_ISDIR(sobj.st_mode))
		{
			printf("File name : %s \n",name);
			printf("It is a directory\n");
		}
		else if(S_ISLNK(sobj.st_mode))
		{
			printf("File name : %s \n",name);
			printf("It is a symbolic link\n");
		}
	}

	
	closedir(dp);
	return 0;
}

// ./Assignment2_4 Demo
