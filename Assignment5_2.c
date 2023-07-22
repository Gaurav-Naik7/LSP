// Program which accepts file name from user which contains information of employee and reads contents from that file.

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#pragma pack(1)
struct Employee
{
	char Name[20];
	int Salary;
	int Age;
};

int main(int argc,char *argv[])
{
	struct Employee eobj;
	int fd=0;
	
	if(argc!=2)
	{
		printf("Insufficient arguments\n");
		return -1;
	}
	
	fd=open(argv[1],O_RDONLY);
	
	read(fd,&eobj,sizeof(eobj));
	
	printf("Name of employee is : %s\n",eobj.Name);
	printf("Salary of employee is : %d\n",eobj.Salary);
	printf("Age of employee is : %d\n",eobj.Age);
	
	return 0;	
}

// ./Assignment5_1 Employee.txt
