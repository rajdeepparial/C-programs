#include<stdio.h>
#include<conio.h>
int a[10][10],flag[10],n,cost=0;

void input()
{
	int i,j;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	printf("\nEnter weighted adjacency matrix: \n");
	for(i=0; i<n; i++)
	{
		printf("\nEnter Elements of Row %d : ",i+1);
		for( j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
		flag[i]=0;
	}
	printf("\n\nThe matrix you have taken:\n");
	for( i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
	}
}

int g(int c)
{
	int i,nextcity=999;
	int min=999,kmin;
	for(i=0; i<n; i++)
	{
		if(a[c][i]!=0 && flag[i]==0)
		{
			if(a[c][i] < min)
			{
				min=a[i][c];
				kmin=a[c][i];
				nextcity=i;
			}
		}
	}
	if(min!=999)
    {
        cost+=kmin;
    }	
	return nextcity;
}

void mincost(int ve)
{
	int i,ncity;
	flag[ve]=1;	
	printf("%d -->",ve+1);
	ncity=g(ve);
	if(ncity==999) //back to starting node
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=a[ve][ncity];
		return;
	}
	mincost(ncity);
}

void output()
{
	printf("\n\nMinimum cost:");
	printf("%d",cost);
}

void main()
{
	input();
	printf("\n\nPath is:\t");
	mincost(0);
	output();
	getch();
}
