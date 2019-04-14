#include<stdio.h>
struct process
{
	int pid,bt,wt,tat;
};
struct process p[20];
int main()
{
	int i,j,n,temp1,temp2;
	float awt,atat,ttat,twt;
	printf("\nShortest Job First Serve Scheduling");
	printf("\n----------------------------------");
	printf("\nEnter number of process:");
    	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("\nEnter Burst Time for P[%d]:\n",(i+1));
		scanf("%d",&p[i].bt);
		p[i].wt=p[i].tat=0;
	}    
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i].bt<p[j].bt)
			{
				temp1=p[i].pid;p[i].pid=p[j].pid;p[j].pid=temp1;
				temp2=p[i].bt;p[i].bt=p[j].bt;p[j].bt=temp2;
				
			}
		}	
	}
	p[0].tat=p[0].bt;
	for(i=1;i<n;i++)
	{
		p[i].wt=p[i-1].wt+p[i-1].bt;
		p[i].tat=p[i].wt+p[i].bt;
	}
	twt=0;
	ttat=0;
	for(i=0;i<n;i++)
	{
		twt=twt+p[i].wt;
		ttat=ttat+p[i].tat;
	}
	
	awt=twt/n;
	atat=ttat/n;

	printf("\nPROCESS\tBURSTTIME\tWAITINGTIME\tTURNAROUNDTIME\n");
	printf("\n--------------------------------------------\n");
	for(i=0;i<n;i++)
	printf("%d\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
	printf("\naverage waiting time:%.2f\n",awt);
	printf("average turn around time:%.2f\n",atat);
	printf("\n--------------------------------------------\n");
	return 0;

}
