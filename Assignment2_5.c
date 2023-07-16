// Program which accept directory name from user and print name of file having largest size

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent * entry=NULL;
	struct stat sobj;
	char name[30];
	int iMax=0;
	char lmax[30];
	
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
			if(iMax<sobj.st_size)
			{
				iMax=sobj.st_size;
				strcpy(lmax,entry->d_name);
			}
		}
	}
	
	printf("Name of largest file : %s with size %d bytes \n",lmax,iMax);
	
	closedir(dp);
	return 0;
}

// ./Assignment2_5 Demo
