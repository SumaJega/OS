#include<stdio.h>
struct process
{
	int pid,bt,wt,tat,pri;
};
struct process p[20];
int main()
{
	int i,j,n,temp1,temp2,temp3;
	float awt,atat,ttat,twt;
	printf("\nPriority Scheduling");
	printf("\n----------------------------------");
	printf("\nEnter number of process:");
    scanf("%d",&n);
	printf("\nEnter Burst Time and priority for process:\n");
	for(i=0;i<n;i++)
	{
		p[i].pid=i+1;
		printf("P[%d]:",i+1);
		scanf("%d%d",&p[i].bt,&p[i].pri);
		p[i].wt=p[i].tat=0;
	}  
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i].pri<p[j].pri)
			{
				temp1=p[i].pid;p[i].pid=p[j].pid;p[j].pid=temp1;
				temp2=p[i].bt;p[i].bt=p[j].bt;p[j].bt=temp2;
				temp3=p[i].pri;p[i].pri=p[j].pri;p[j].pri=temp3;
				
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

	printf("---------------Priority Scheduling--------------------\nPROCESS\tBURSTTIME\tPRIORITY\tWAITINGTIME\tTURNAROUNDTIME\n");
	for(i=0;i<n;i++)
	printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].bt,p[i].pri,p[i].wt,p[i].tat);
	printf("\naverage waiting time:%.2f\n",awt);
	printf("average turn around time:%.2f\n",atat);
	
	return 0;

}
