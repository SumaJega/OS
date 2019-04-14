#include<stdio.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main()
{
	int * a,ID,n,IPC_CREATE;
	int i,j,t,negativesum=0,positivesum=0,possum,negsum;
	printf("\n\tIPC USING SHARED MEMORY");
	printf("\nP1 Process starts");
	printf("\nEnter the how many numbers:");
	scanf("%d",&n);
	ID=shmget((key_t)161,((10+3)*sizeof(int)),0700|IPC_CREATE);
	if(ID==-1)
		printf("\nshm error");
	else
		printf("\nShared Memory is created");
		printf("\nShared Memory Id:%d",ID);
		a=(int*)shmat(ID,NULL,0700);
		if(a==NULL)
			printf("\nshm attached error");
		else
			printf("\nShm is attached");
		printf("\n Shared memory address is %u",a);
		
		*(a+n+1)=-1;
		*(a+0)=n;
		printf("\nEnter the elements:");
		for(i=1;i<=n;i++)
		{
			scanf("%d",(a+i));	
		}
		printf("\nP1 wait for P2");
		while(*(a+n+1)==-1);
		printf("\nP1 Process Output");
		printf("\nOdd count:%d",*(a+n+1));
		printf("\nEven count:%d",*(a+n+2));
		shmdt(a);
		t=shmctl(ID,IPC_RMID,NULL);
		if(t==0)
			printf("\nShrae Memory removed");
		else
			printf("\nError in removal of shared memory");
		
		printf("\nP1 Process ends");
	return 0;
}

