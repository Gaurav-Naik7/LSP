// Program which accept directory name from user and delete all file names whose size is greater than 100 bytes

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
			if(sobj.st_size>100)
			{
				printf("%s deleted\n",entry->d_name);
				remove(name);
			}
		}
	}


	closedir(dp);
	return 0;
}

// ./Assignment6_4 Demo
