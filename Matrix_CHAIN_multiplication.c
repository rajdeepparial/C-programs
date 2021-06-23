#include<stdio.h>
int n;
int min(int m[n][n], int i, int  j, int p[])
{
	int k=i, cost, new_cost, arr[2];
	cost= m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
	k=i+1;
	while(k<j)
	{
		new_cost= m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
		if(new_cost < cost)
		{
			cost=new_cost;
		}
		k++;
	}
	arr[0]=cost;
	return arr;
}
void main()
{
	int i,j, inc, cost, p[10],*arr;
	printf("How many matrices do you want to multiply? ");
	scanf("%d", &n);
	printf("\nEnter their orders in an array (if 3 matrices have orders 2X4, 4X5, 5X3 Then enter 2,4,5,3): ");
	for(i=0; i<n+1; i++)
	{
		scanf("%d", &p[i]);
	}
	int m[n][n], s[n-1][n-1];
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(i==j)
			{
				m[i][j]=0;
			}
			else if(i>j)
			{
				m[i][j]=9999;
			}
			else
			{
				m[i][j]=1;
			}
		}
	}
	for(i=1; i<=n-1; i++)
	{
		for(j=2; j<=n; j++)
		{
			if(i==j)
			{
				s[i][j]=0;
			}
			else if(i>j)
			{
				s[i][j]=9999;
			}
			else
			{
				s[i][j]=1;
			}
		}
	}
			
	for(inc=1; inc<=n; inc++) //inc in just used to increament the value of j(column) by 1
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+inc;j<=n;j++)
			{
				arr=min(m,i,j,p);
				m[i][j]=arr[0];
				s[i][j]=arr[1];
			}
		}
	}
		
	printf("\n\nm matrix for matrix chain multiplication: \n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
	
	/*printf("\n\n");
	for(i=1; i<=n-1; i++)
	{
		for(j=2; j<=n; j++)
		{
			printf("%d\t", s[i][j]);
		}
		printf("\n");
	}*/
	printf("\n\nThe total cost of multiplication is: %d",m[1][n]);
	
}
