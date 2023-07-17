// Program to demonstrate concept of I/O redirection

#include<stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns = iNo1 * iNo2;

    printf("Multiplication is : %d\n",iAns);

    return 0;
}

//./Assignment4_1 < Input.txt > Output.txt
