#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid,x;
	x=10;
	pid=fork();
	if(pid==0)
		printf("The value of x:%d",++x);	
	else
		printf("The value of x:%d",--x);	
	return 0;
}		
