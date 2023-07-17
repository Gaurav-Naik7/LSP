// Program which accept two directory names from user and move allfiles from source directory to destination directory

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
	char oldname[50];
	char newname[50];
	
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
		sprintf(oldname,"%s/%s",argv[1],entry->d_name);
		sprintf(newname,"%s/%s",argv[2],entry->d_name);
		
		rename(oldname,newname);
	}

	closedir(dp);
	return 0;
}

// ./Assignment3_3 Demo Hello
