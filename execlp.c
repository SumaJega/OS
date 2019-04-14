#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid,cpid;
	pid=fork();
	if(pid==0)
	{
		printf("Child Process");
		execlp("/bin/ls","ls",NULL);
		printf("Kamaraj\n");
	}	
	else
	{
		cpid=wait(10000);
		printf("Parent Process");
		execlp("/bin/who","who",NULL);
		printf("Jegadeeswari\n");
	}
	return 0;
}
