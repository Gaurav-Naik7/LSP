// Program which accepts file name from user and print all information about it

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	struct stat sobj;
	
	if(argc!=2)
	{
		printf("Invalid number of arguments\n");
		return -1;
	}
	
	stat(argv[1],&sobj);
	
	printf("File name : %s\n",argv[1]);
	printf("File size is : %ld\n",sobj.st_size);
	printf("Number of links : %ld\n",sobj.st_nlink);
	printf("Inode number : %ld\n",sobj.st_ino);
	printf("File system number : %ld\n",sobj.st_dev);
	printf("Number of blocks : %ld\n",sobj.st_blocks);
	
	return 0;
}

// ./Assignment1_4 Input.txt
