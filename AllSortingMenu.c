#include <stdio.h> 
#include <stdlib.h>
void input(int arr[], int n)
{
	int i;
	printf("\nEnter %d values of array: ",n);
    for(i=0;i<n;i++)  
    {  
        scanf("%d", &arr[i]);  
    }
}
void swap(int *a, int *b) 
{ 
    int temp;
	temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
void bubble_sort(int arr[], int n) 
{ 
   int i, j; 
   for (i=0; i<n-1; i++)       
   { 
       for (j=0; j<n-i-1; j++)  
       {
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
        }
	}
} 

void selection_sort(int arr[], int n) 
{ 
   int i, j,loc; 
   for (i=0; i<n; i++)       
   { 
   		loc=i;
       for (j=i+1; j<n; j++)  
       {
           if (arr[j] < arr[loc]) 
              loc=j; 
        }
        swap(&arr[i],&arr[loc]);
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

void output(int arr[], int n) 
{ 
    int i;
	printf("Sorted array: \n"); 
    for (i=0; i<n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{  
    int arr[20],n,ch;
    do{
    	printf("\nEnter the size of array: ");
    	scanf("%d",&n);
    	input(arr, n);
    	printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n0.Exit\n\nEnter your choice:- ");
    	scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1: bubble_sort(arr,n);
    			break;
    		case 2: selection_sort(arr,n);
    			break;
    		case 3: insertion_sort(arr,n);
    			break;
    		case 0: exit(0);
		}
    	output(arr, n); 
	}while(1);
    return 0; 
} 
