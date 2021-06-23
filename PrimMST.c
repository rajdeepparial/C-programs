#include<stdio.h>
#include<conio.h>
#define inf 9999
#define N 20
void input(int adj[N][N], int n)
{
    int u, v, dist, i, j, dir;
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
	printf("\n\n\tPress 1 for directed graph, 2 for undirected graph: ");
    scanf("%d",&dir);
    do{
        printf("\n\n\tEnter source, destination, distance: ");
        scanf("%d %d %d", &u, &v, &dist);
        if(dir==2)
        {
        	adj[v][u]=dist;
		}
        adj[u][v]=dist;
        printf("Do you want to continue? Yes->Any key, No->n: ");
        ch=getche();
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

int MSTprim(int adj[N][N], int f[], int key[], int p[], int n) 
{
	int v,j,u,parent;
	for(j=1;j<=n;j++)
	{
		u=extract_min(f,key,n);
		f[u]=1;
		for(v=1;v<=n;v++)
		{
			if(adj[u][v] && f[v]!=1 && adj[u][v]<key[v])
			{
				p[v]=u;
				key[v]=adj[u][v];
			}
		}
	}
}

void main()
{
    int adj[20][20], d[20], f[20], p[20], i, n, cost=0;
    printf("Enter the no of vertices: ");
    scanf("%d", &n);
    for(i=0;i<=n;i++)
    {
    	f[i]=0; //flag
		p[i]=0; //parent array
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
    MSTprim(adj,f,d,p,n);
    printf("\nThe minimum spanning tree is: ");
    printf("\nParent\tChild\tWeight");
    for(i=1;i<=n;i++)
    {
    	printf("\n%d\t%d\t%d",p[i],i,d[i]);
	}
    for(i=1;i<=n;i++)
    {
    	cost+=d[i];
	}
	printf("\n\n\nMinimum cost is: %d", cost);
}
