#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("Child Process \n");
		printf("PId:%d",getpid());
		printf("Parent PId:%d\n",getppid());	
	}
	else
	{
		printf("Parent Process\n");
		printf("PId:%d",getpid());
		printf("Parent PId:%d\n",getppid());	
	}
	return 0;
}	
