#include<stdio.h>	
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int pid,stat;
	pid=fork();
	if(pid==0)
	{
		exit(1);
	}
	else 
	{	
		wait(&stat);
	}	
	if(WIFEXITED(stat))
	{
		printf(" Exit Status:%d",WEXITSTATUS(stat));
	}
	return 0;
}

