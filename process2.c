#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>x
#include<sys/ipc.h>
int main()
{
	int *a,ID,n,evencount=0,oddcount=0;
	int i,j,positivesum=0,negativesum=0,oddsum;
	printf("\nP2 process starts");
	ID=shmget((key_t)161,(13*sizeof(int)),0700);
	if(ID==-1)
		printf("\nshm creation error");
	else
		printf("\nShm is created");
		printf("\n Shared memory id:%d",ID);
		a=(int*)shmat(ID,NULL,0700);
		if(a==NULL)
			printf("\nshm can't attached");
		else
			printf("\nshm is attached");
			printf("\n Shared memory address is %u",a);
			n=*(a+0);
			
			for(i=1;i<=n;i++)
			{
				if(*(a+i)%2==0)
					evencount++;
				else
					oddcount++;
			}
			
			printf("\nP2 writes the result in the shared memory");
			*(a+n+1)=oddcount;
			*(a+n+2)=evencount;
			printf("\n%d",oddcount);
			printf("\n%d",evencount);
			i=shmdt(a);
			if(i==-1)
				printf("\n Shm can't detached");
			else
				printf("\n Shm is detached");
			
			printf("\nP2 process ends");
	
	return 0;
}

