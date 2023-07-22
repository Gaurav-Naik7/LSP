// Program which accept directory name from user and write information of all regular file in and then read the contents from that file.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#pragma pack(1)

struct FileInfo
{
	char FileName[20];
	int FileSize;
	int INo;
};
int main(int argc,char *argv[])
{
	int fd=0;
	DIR *dp=NULL;
	struct dirent * entry=NULL;
	struct stat sobj;
	struct FileInfo fobj;
	char name[30];
	
	
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
	
	fd=open(argv[2],O_RDWR);
	
	if(fd!=-1)
	{
		printf("File is existing\n");
	}
	else
	{
		fd=creat(argv[2],0777);
		if(fd!=-1)
		{
			printf("New file gets created\n");
		}
	}
	
	while((entry=readdir(dp))!=NULL)
	{
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		stat(name,&sobj);
		if(S_ISREG(sobj.st_mode))
		{
			printf("File name : %s \n",entry->d_name);
			strcpy(fobj.FileName,entry->d_name);
			fobj.FileSize=sobj.st_size;
			fobj.FileSize=sobj.st_ino;
			write(fd,&fobj,sizeof(fobj));
			read(fd,&fobj,sizeof(fobj));
			printf("Size of file : %ld\n",fobj.FileSize);
			printf("Inode number : %ld\n",fobj.INo);
			printf("\n");
		}	
	}

	
	
	closedir(dp);
	return 0;
}

// ./Assignment5_3 Text Data.txt
