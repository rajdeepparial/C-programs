#include<stdio.h>
#include<conio.h>
#define inf 9999
#define N 20

int extract_min(int f[], int d[], int n)
  {
      int i, loc, min=99999;
      for(i=1; i<=n; i++)
        {
            if(f[i]!=1 && d[i]<min)
              {
                min=d[i];
                loc=i;
              }
        }
    return loc;
}

void dijkstra(int adj[N][N], int f[], int d[], int p[], int n) 
{
	int i,j,x,count=0, parent;
	while(count!=n)
	{
		x=extract_min(f,d,n);
		f[x]=1;
        for(j=1;j<=n;j++)
        {
            if(adj[x][j]!=0 && adj[x][j]!=inf)    //edge relaxation
            {
                if(d[j] > d[x] + adj[x][j])
                { 
                    d[j] = d[x] + adj[x][j];
                    p[j] = x;
                }
            }
        }
    count++;
	}	
	printf("\nShortest distance from 1st node to node %d is: %d", n, d[n]);
	printf("\nPath is: %d ", n);
	for(i=n;i>1;i--)
	{
		parent=p[n];
		if(parent!=0)
			printf("<--%d ", parent);
		n=parent;
	}
}

void input(int adj[N][N], int n)
{
    int u, v, dist, i, j;
    char ch;
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(i==j)
    		{
    			adj[i][j]=0;
			}
			else
			{
				adj[i][j]=inf;
			}
		}
	}
    do{
        printf("\n\n\tEnter source, destination, distance: ");
        scanf("%d %d %d", &u, &v, &dist);
        adj[u][v]=dist;
        printf("Do you want to continue? Yes->Any key, No->n: ");
        scanf(" %c",&ch);
    }while(ch!='n' && ch!='N');
}

int display_input(int adj[N][N], int n)
{
	int i,j;
	printf("\n\nWeighted adjacency matrix of input graph is:\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d\t", adj[i][j]);
		}
		printf("\n");
	}
}

void main()
{
    int adj[20][20], d[20], f[20], p[20], i, n;
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    for(i=0;i<=n;i++)
    {
    	p[i]=0;
		f[i]=0; 
    	if(i==0 || i==1)
    	{
    		d[i]=0; //1st two value of distance
		}
		else
		{
			d[i]=inf; //other distances initially infinity
		}
	}
	
	printf("\n\tInitially Distance array is:\t");
	for(i=1;i<=n;i++)
    {
		printf("%d\t", d[i]);
	}
	printf("\n\tInitially Flag array is:\t");
	for(i=1;i<=n;i++)
    {
		printf("%d\t", f[i]);
	}
	printf("\n\tInitially Parent array is:\t");
	for(i=1;i<=n;i++)
    {
		printf("%d\t", p[i]);
	}	
    input(adj,n);
    display_input(adj,n);
    dijkstra(adj,f,d,p,n);
}
