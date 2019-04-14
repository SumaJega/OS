#include<stdio.h>
struct Process
{
       int pid,art,bt,wt,tat,rnt;
};


void sortart(struct Process P[],int n)
{
       int i,j;
       struct Process temp;
       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if(P[i].art > P[j].art)
                     {
                           temp = P[i];
                           P[i] = P[j];
                           P[j] = temp;
                     }
              }
       }
       return;
}

int main()
{
       int i,j,n,time,remain,flag=0,ts;
       struct Process P[100];
       float avgwt=0,avgtt=0;
       printf("Round Robin Scheduling Algorithm\n");
       printf("Enter Number Of Processes : ");
       scanf("%d",&n);
       remain=n;
       for(i=0;i<n;i++)
       {
              printf("Enter arrival time and Burst time for Process P%d : ",i);
              scanf("%d%d",&P[i].art,&P[i].bt);
              P[i].pid = i;
              P[i].rnt = P[i].bt;
       }
       sortart(P,n);
       printf("Enter Time Quantum Number : ");
       scanf("%d",&ts);
       printf("\n***************************************\n");
       printf("Gantt Chart\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(P[i].rnt<=ts && P[i].rnt>0)
              {
                     time = time + P[i].rnt;
                     printf("  [P%d]\n%d",P[i].pid,time);
                     P[i].rnt=0;
                     flag=1;
              }
              else if(P[i].rnt > 0)
              {
                     P[i].rnt = P[i].rnt - ts;
                     time = time + ts;
                     printf(" 	[P%d]\n%d",P[i].pid,time);
              }
              if(P[i].rnt==0 && flag==1)
              {
                     remain--;
                     P[i].tat = time-P[i].art;
                     P[i].wt = time-P[i].art-P[i].bt;
                     avgwt = avgwt + time-P[i].art-P[i].bt;
                     avgtt = avgtt + time-P[i].art;
                     flag=0;
              }
              if(i==n-1)
                     i=0;
              else if(P[i+1].art <= time)
                     i++;
              else
                     i=0;
       }
       printf("\n\n");
       printf("***************************************\n");
       printf("Pro\tArTi\tBuTi\tTaTi\tWtTi\n");
       printf("***************************************\n");
       for(i=0;i<n;i++)
       {
              printf("P%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].art,P[i].bt,P[i].tat,P[i].wt);
       }
       printf("***************************************\n");
       avgwt = avgwt/n;
       avgtt = avgtt/n;
       printf("Average Waiting Time : %.2f\n",avgwt);
       printf("Average Turnaround Time : %.2f\n",avgtt);
       return 0;
}
