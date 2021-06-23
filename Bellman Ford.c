#include<stdio.h>
#include<stdlib.h>
#define inf 99999
int adj[50][50];
int d[100],parent[100];
int u,v;
int flag;
int input(int ve)
{
  int dist;
	char ch;
    for(u=1;u<=ve;u++)
     {
       for(v=1;v<=ve;v++)
       {
         if(u==v)
          {
            adj[u][v]=0;
          }
         else
          {
            adj[u][v]=inf;
          }
       }
    }
 do
    {
        printf(" Enter Source, destination and distance: ");
        scanf("%d%d%d",&u,&v,&dist);
        adj[u][v]=dist;

        printf("\nWant to continue?y/n: ");
        scanf(" %c",&ch);
    }while(ch!='n' && ch!='N');

	printf("\nYour adjacency matrix  is: \n");
   	for(u=1; u<=ve; u++)
    {
      	for(v=1;v<=ve;v++)
      	{
         	printf("%d\t", adj[u][v]);
      	}
      	printf("\n");
   	}

}

int Relax(int u,int v)
{
    if(d[v]>d[u]+adj[u][v])
    {
        d[v]=d[u]+adj[u][v];
        parent[v]=u;
    }
}

int initialize(int ve,int source)
{
  for(u=1;u<=ve;u++)
  	{
      	if(u==source)
      	{
         	d[u]=0;
      	}
      	else
      	{
         	d[u]=inf;
      	}
	}
  	for(v=1;v<=ve;v++)
  	{
    	parent[v]=0;
  	}
}

int bellman_ford(int source,int ve)
 {
     int s,i;
     initialize(ve,source);

       for(i=1;i<=ve-1;i++)
       {
        	for(u=1;u<=ve;u++)        //edge relaxtation
         	{
            	for(v=1;v<=ve;v++)
            	{
               		Relax(u,v);
            	}
         	}
        flag=1;
       }
       for(u=1;u<=ve;u++)
       {
        for(v=1;v<=ve;v++)
          {
            if(d[v]>d[u]+adj[u][v])
                {
                  flag=0;
                }
           }
        }
        return flag;
 }
int main()
{
   	int ve,des,i;
  	int source=1;
  	printf("Enter the no of vertices: ");
    scanf("%d",&ve);
   	input(ve);
   	bellman_ford(source,ve);
   if(flag==0)
   {
       printf("Negative Edge Cycle Detected!!!\n\n");
   }
   else
   {
       printf("No Negative Edge Cycle Detected!!!\n\n");
       for(i=1;i<=ve;i++)
       {
           printf("\t Minimum Distance From Source to %d is:%d\n",i,d[i]);
       }
   		printf("Enter The Destination:");
   		scanf("%d",&des);
   		printf("\n Minimum Distance from source to %d is:%d\n",des,d[des]);
   		printf("\n Shortest Path from source to %d is\n",des);
   		printf("%d ",des);
   		while(des!=0)
   		{
   			des=parent[des];
   			if(des==0)
   				break;
       		printf("<--%d ",des);
  		}
   		printf("\n");
	}
}
