#include<stdio.h>
#include<stdlib.h>
int linear_search(int A[],int n,int item)
{
	int i;
	for(i=0;i<n; i++)
		if(A[i]==item)
			return i;
		return -1;
}

int binary_search(int A[],int item,int low,int high)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(item==A[mid])
			return mid;
		else if(item<A[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void main()
{
	int A[10],n,ch,x,i,item, low, high;
	do{
		system("cls");
	printf("Press 1 for linear search \nPress 2 for binary search\nPress 0 to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: printf("\nEnter the size of your array: ");
				scanf("%d", &n);
				printf("\nEnter the elements: ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&A[i]);
				}
				printf("\nEnter the searching element: ");
				scanf("%d",&item);
				x=linear_search(A, n, item);
				if(x== -1)
					printf("\nItem not found");
				else
					printf("\nSearch successful in linear search method!! %d element is found at %d position", item, x+1);
				getch();
				break;
				
		case 2:	printf("\nEnter the size of your array: ");
				scanf("%d", &n);
				printf("\nEnter the elements in ascending order: ");
				for(i=0;i<n;i++)
				{
					scanf("%d",&A[i]);
				}
				printf("\nEnter the searching element: ");
				scanf("%d",&item);
				x=binary_search(A,item, 0, n-1);
				if(x== -1)
					printf("\nItem not found");
				else
					printf("\nSearch successful in binary search method!! %d element is found at %d position", item, x+1);
				getch();
				break;
		case 0: exit(0);
		
		default: printf("\nWrong choice");
				 getch();
	}
	}while(1);
}
