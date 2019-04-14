#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\n\nChild Process");
	execlp("/bin/ls","ls",NULL);
	printf("Kamaraj\n");
	return 0;
}
