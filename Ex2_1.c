#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid;
	printf("Parent Process Id:%d\n",getppid());
	fork();
	fork();
	fork();
	printf("Jegadeeswari\n");
	return 0;
}
