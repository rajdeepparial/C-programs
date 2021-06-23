#include<stdio.h>
#define inf 9999
int dist[10][10], path[10][10];

void initialize(int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			path[i][j]=0;
			if(i==j)
			{
				dist[i][j]=0;
			}
			else
			{
				dist[i][j]=inf;				
			}
		}
	}
}
void input(int n)
{
	int u,v, dis, dir;
	char ch;
	printf("\n\n1. Directed Graph\n2. Undirected Graph : ");
	scanf("%d",&dir);
	do{
        printf("\n\n\tEnter source, destination, distance respectively: ");
        scanf("%d %d %d", &u, &v, &dis);
        if(dir==2)
        {
        	dist[v][u]=dis;
		}
        dist[u][v]=dis;
        printf("Do you want to continue? Yes->Any key, No->n: ");
        ch=getche();
    }while(ch!='n' && ch!='N');
}


void display_input(int n)
{
	int i,j;
	printf("\n\nInput distance matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
	printf("\nInput path matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",path[i][j]);
		}
		printf("\n");
	}
}

void floyd_warshall(int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=k;
				}
			}
		}
	}
}

void display(n)
{
	int i,j;
	printf("\n\n~~~~~APPLYING FLOYD WARSHALL~~~~~\n");
	printf("\n\nFinal distance matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
	printf("\nFinal path matrix is:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",path[i][j]);
		}
		printf("\n");
	}
}
void printPath(int i,int j)
{
	if(dist[i][j]!=inf)
	{
    	if(path[i][j]==0)
    	{
    		return;
		}
		printPath(i,path[i][j]);
		printf("%d ->", path[i][j]);
	}
	else
	{
		printf("NO PATH ->");
	}
}


void main()
{
	int n, start, end;
	char choice;
	printf("\nEnter the number of vertices: ");
	scanf("%d",&n);
	initialize(n);
	input(n);
	display_input(n);
	floyd_warshall(n);
	display(n);
	do{
	printf("\n\nEnter the starting vertex and end vertex to calculate path: ");
	scanf("%d %d", &start, &end);
	printf("\n\n--------PATH IS--------\n");
	printf("%d->",start);
	printPath(start,end);
	printf("%d",end);
	printf("\n\nDo you want to continue? Yes->Any key, No->n: ");
    choice=getche();
	}while(choice!='n' && choice!='N');
}
