#include<stdio.h>
int n;

void swap(int *a, int *b) 
{ 
    int temp;
	temp = *a; 
    *a = *b; 
    *b = temp; 
}

void sort(int AT[], int BT[], int index[]) 
{ 
   int i, j; 
   for (i=0; i<n-1; i++)       
   { 
       for (j=0; j<n-i-1; j++)  
       {
           if (AT[j] > AT[j+1])
		   {
			 
            swap(&AT[j], &AT[j+1]);
			swap(&BT[j], &BT[j+1]);
			swap(&index[j], &index[j+1]);
			}
        }
	}
}

void main()
{
	int i,AT[20],BT[20],index[20],WT[20]={0},TAT[20]={0}, t=0, x;
	float avwt, avtat;
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		index[i]=i;
		printf("\nEnter Arrival Time of process %d: ",i+1);
		scanf("%d",&AT[i]);
		printf("\nEnter Burst Time of process %d: ",i+1);
		scanf("%d",&BT[i]);
	} 
	sort(AT,BT,index);
	printf("\n\nProcess\tArrival Time\tBurst Time");
	for(i=0;i<n;i++)
	{
		printf("\np%d\t\t%d\t\t%d",index[i],AT[i],BT[i]);
	}
	for(i=0;i<n;i++)
	{
	 	x=index[i];
	 	if(i==0)
		{
		 	WT[x]=0;
		}
		else
		{
		 	WT[x]=t-AT[i];	
		}
		t=t+BT[i];
		TAT[x]=t-AT[i];
	}
	float tot=0, tot1=0;
	printf("\n\nProcess\tWaiting Time\tTurnaround Time");
	for(i=0;i<n;i++)
	{
		printf("\np%d\t\t%d\t\t%d",i+1,WT[i],TAT[i]);
		tot=tot+WT[i];
		tot1=tot1+TAT[i];
	}
	avwt=tot/n;
	avtat=tot1/n;
	printf("\nAverage waiting time is %f",avwt);
	printf("\nAverage turn around time time is %f",avtat);
}
