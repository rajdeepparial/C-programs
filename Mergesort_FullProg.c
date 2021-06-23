#include <stdio.h>

 void merge(int arr[],int low,int mid,int high)
{ 
	
	int i = low, j = mid+1, k = low; 
  	int c[30];
   
    while (i<=mid && j <=high) 
    { 
      
        if (arr[i] < arr[j]) 
        {
        	c[k] = arr[i]; 
        	i++;
		}
        else
        {
            c[k] = arr[j]; 
            j++;
        }
        k++;
    } 
    while (i <= mid) 
	{
		c[k] = arr[i];
		i++;
		k++; 
	}
	
    while (j <= high) 
        {
        	c[k] = arr[j];
        	j++;
			k++;
		} 
		
	for(i=low;i<=high;i++)
	{
		arr[i]=c[i];
	}	
} 


void mergesort(int arr[],int low,int high)
{
    int mid;
 
    if(low < high)
    {
        mid = (low + high) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[10];
    int i, n;
 
    printf("Enter number of elements:");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
    {
         scanf("%d", &arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("After merge sort sorted elements are:  ");
    for(i = 0;i < n; i++)
    {
         printf("%d   ",arr[i]);
    }
 
   return 0;
}
