#include<stdio.h>
int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("Child Process ID:%d",getpid());
		printf("Child-Parent Process ID:%d",getppid());	
	}
	else
	{
		printf("Process ID:%d",getpid());
		printf("Parent Process ID:%d",getppid());
	}
	return 0;
}
