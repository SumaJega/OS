#include<stdio.h>
#include<stdlib.h>
struct Process
{
	int pid,bt,wt,tat;
};
int main()
{
	struct Process P[10];
	int n,i;
	float awt,atat,	twt=0,ttat=0 ;
	printf("\nFirst Come First Serve Scheduling");
	printf("\n----------------------------------");
	printf("\nEnter number of process:");
    scanf("%d",&n);
	printf("\nEnter Burst Time:\n");
	for(i=0;i<n;i++)
	{
		P[i].pid=i+1;
		printf("P[%d]:",i+1);
		scanf("%d",&P[i].bt);
		P[i].wt=P[i].tat=0;
	}    
	P[0].tat=P[0].bt;
	for(i=1;i<n;i++)
	{
		P[i].wt=P[i-1].wt+P[i-1].bt;
		P[i].tat=P[i].wt+P[i].bt;	
	}
	for(i=0;i<n;i++)
	{
		twt=twt+P[i].wt;
		ttat=ttat+P[i].tat;		
	}
	awt=twt/n;
	atat=ttat/n;
	printf("\n--------------------------------------------");
	printf("\nProcess\tBT\tWT\tTAT\n");
	printf("\n--------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",P[i].pid,P[i].bt,P[i].wt,P[i].tat);
	}
	printf("\n--------------------------------------------");
	printf("\nTotal Waiting Time=%.2fms\nTotal Turn Around Time:%.2fms\n",twt,ttat);
	printf("\nAverage Waiting Time=%.2fms\nAverage Turn Around Time:%.2fms\n",awt,atat);
	printf("\n--------------------------------------------\n");
	printf("\n\nGantt Chart\n");
	printf("\n----------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("|P%d\t",i+1);
	}
	printf("\n-----------------------------------------\n");
	printf("0");
	for(i=0;i<n;i++)
	{

		printf("\t%d",P[i].tat);
	}
	printf("\n");
	return 0;
}
