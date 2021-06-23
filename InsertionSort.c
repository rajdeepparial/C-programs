#include<stdio.h>
void input (int a[],int n)
{
	int i;
	printf("ENTER ELEMENT NUMBER :");
	for (i=0;i<n;i++)
	{
	  scanf(" %d",&a[i]);
    }
}
void insertion_sort(int a[],int n)
{
	int i,j,key;
  for (j=1;j<n;j++)
  {
  	key=a[j];
  	i=j-1;
  	while(i>=0 && a[i]>key)
  	{
  		a[i+1]=a[i];
  		i=i-1;
	}
	a[i+1]=key;
  }
}

int output(int a[],int n)
{
int i;
printf("sorted array is:");
	for(i=0; i<n; i++)
	{
		printf(" %d",a[i]);
	}
}

int main()
{
		int a[100],n;
		printf("Enter the value of n:");
		scanf("%d",&n);
		input(a,n);
		insertion_sort(a,n);
		output(a,n);
		return 0;
}
