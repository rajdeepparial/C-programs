#include <stdio.h>
#include <math.h>
int X[10],count=0;
void NQueen(int k, int n);
int place(int k,int i);
void printChessboard(int n);

void main()
{
	int i,q;
	printf("\t\t~~~~ N QUEEN PROBLEM ~~~~\n\n");
	printf("\nEnter number of queens: ");
	scanf("%d",&q);
	NQueen(1,q);
}

void NQueen(int k, int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		if(place(k,i))
		{
			X[k]=i; //n-tuple solution
			if(k==n)
			{
				printf("\nThe n-tuple solution is:\n");
				for(i=1; i<=n; i++)
				{
					printf("%d   ",X[i]);
				}
				printChessboard(n);		
			}
			else
			{
				NQueen(k+1,n);
			}
		}
	}
}

int place(int k,int i)
{
	int j;
	for(j=1; j<=k-1; j++)
	{
		if((X[j]==i)||(abs(X[j]-i)==abs(j-k)))
		{
			return 0;
		}		
	}
	return 1;
}

void printChessboard(int n)
{     
	int i,j;
    printf("\n\n\tSolution %d:\n",++count);
    for(i=1; i<=n; i++)
    {    
		for(j=1; j<=n; j++)
        {
            if(X[i]==j)
                printf("\tQ%d",i);
            else
                printf("\t*");
        }
        printf("\n");
    }
}
