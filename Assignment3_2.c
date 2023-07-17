// Program which accept directory name and file name from user and check whether that file is present in that directory

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
	
	if(argc!=3)
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
			if(strcmp(argv[2],entry->d_name)==0)
			{
				printf("%s file is present in the directory\n",argv[2]);
				break;	
			}
		}
		else
		{
			printf("File not present in the directory\n");
			break;
		}
	}

	closedir(dp);
	return 0;
}

// ./Assignment3_2 Demo Input.txt
