#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int n;
int adj[MAX][MAX]; 
int status[MAX]; //0,1,2
int stack[MAX];
int top = -1;
void push(int v)
{
    if(top == (MAX-1))
    {
        printf("\nStack Overflow\n");
        return;
    }
    top=top+1;
    stack[top] = v;
}
int pop()
{
    int v;
    if(top == -1)
    {
    	printf("\nStack Underflow\n");
        exit(1);
    }
    else
    {
        v = stack[top];
        top=top-1;
        return v;
    }
}

int isEmpty( )
{
  if(top == -1)
  	return 1;
  else
    return 0;
}

void DFS(int v)
{
    int i;
    push(v);
    while(!isEmpty())
    {
        v=pop();
        if(status[v]==1)  //1=pushed
        {
            printf("%d ",v);
            status[v]=2;  //2=visited
        }
        for(i=n-1; i>=0; i--)
        {
            if(adj[v][i]==1 && status[i]==1)
            {
                push(i);
			}
        }
    }
}

void DF_Traversal()
{
    int v;
	for(v=0; v<n; v++)
	{
		status[v]=1;
	}            
    printf("\nEnter starting node for Depth First Search : ");
    scanf("%d",&v);
    DFS(v);
    printf("\n");
}

void main()
{
    int i,max_edges,source,dest;
    printf("\nEnter number of nodes : ");
    scanf("%d",&n);
    max_edges=n*(n-1);

    for(i=1;i<=max_edges;i++)
    {
        printf("\nEnter edge %d( 0 0 to quit ) : ",i);
        scanf("%d %d",&source, &dest);

        if( (source == 0) && (dest == 0) )
            break;

        if( source >= n || dest >= n || source<0 || dest<0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
        {
            adj[source][dest] = 1;
        }
    }
    DF_Traversal();
}

