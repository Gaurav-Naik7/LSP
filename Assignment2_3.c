// Program which accept directory name from user and print all file names from that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent * entry=NULL;
	
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
	
	printf("-------------------------------------\n");
	printf("Entries from the directory file are : \n");
	printf("-------------------------------------\n");
	printf("File Names\n");
	
	while((entry=readdir(dp))!=NULL)
	{
		printf("%s\n",entry->d_name);
	}
	printf("-------------------------------------\n");
	
	closedir(dp);
	return 0;
}

// ./Assignment2_3 Input.txt
