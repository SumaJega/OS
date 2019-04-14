#include<stdio.h>	
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,cpid;
	pid=fork();
	if(pid==0)
	{
		exit(0);
	}
	else 
	{	
		cpid=wait(NULL);
	}	
	printf("Child ID:%d",cpid);
	printf("Parent Process ID:%d\n",getpid());

	return 0;
}

