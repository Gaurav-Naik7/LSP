// Program which writes structure in a file. Structure should contain information of student

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#pragma pack(1)
struct Student
{
	char Name[20];
	int RollNo;
	float Marks;
	int Age;
};

int main(int argc,char *argv[])
{
	struct Student sobj;
	int fd=0;
	
	sobj.RollNo=7;
	sobj.Marks=95;
	sobj.Age=27;
	strcpy(sobj.Name,"Gaurav");
	
	if(argc!=2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	
	if(fd!=-1)
	{
		printf("File is existing\n");
	}
	else
	{
		fd=creat(argv[1],0777);
		if(fd!=-1)
		{
			printf("New file gets created\n");
		}
	}
	
	write(fd,&sobj,sizeof(sobj));
	
	close(fd);
	
	return 0;	
}

// ./Assignment5_1 Student.txt
