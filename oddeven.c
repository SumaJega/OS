#include<stdio.h>	
#include<unistd.h>
#include<stdlib.h>
int main()
{
	int pid,i,n,cpid;
	//printf("Enter the no. elements:");
	//scanf("%d",&n);
	pid=fork();
	
	if(pid==0)
	{
		printf("Child Process\n");
		printf("Odd Numbers\n");
		for(i=0;i<10;i++)
		{	
			if(i%2!=0)
				printf("%d\n",i);
		}	
		exit(0);
	}
	else
	{
		cpid=wait(NULL);
		printf("Parent Process\n");
		printf("Even Numbers\n");
		for(i=0;i<1000;i++)
		{	
			if(i%2==0)
				printf("%d\n",i);
		}	
	}
	return 0;
}
