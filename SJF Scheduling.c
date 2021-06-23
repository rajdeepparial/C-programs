#include<stdio.h>
void swap(int *a, int *b) 
{ 
    int temp;
	temp = *a; 
    *a = *b; 
    *b = temp; 
}

void sort(int bt[], int p[], int n) 
{ 
   int i, j; 
   for (i=0; i<n-1; i++)       
   { 
       for (j=0; j<n-i-1; j++)  
       {
           if (bt[j] > bt[j+1])
		   {
			 
            swap(&bt[j], &bt[j+1]);
			swap(&p[j], &p[j+1]);
			}
        }
	}
}
void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
  
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
  
    sort(bt,p,n);
    wt[0]=0;            
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        {
        	wt[i]+=bt[j];
		}
        total+=wt[i];
    }
  
    avg_wt=(float)total/n;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
  
    avg_tat=(float)total/n;    
    printf("\n\nAverage waiting time: %f",avg_wt);
    printf("\nAverage turnaround time: %f\n",avg_tat);
}
