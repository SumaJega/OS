#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	printf("Parent Process Id:%d\n",getppid());
	pid=fork();
	if(pid==0)
		printf("Child Process Id:%d\n",getpid());	
	return 0;
}
