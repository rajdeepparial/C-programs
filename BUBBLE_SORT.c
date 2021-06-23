#include <stdio.h> 

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
  
void sort(int arr[], int n) 
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
    int arr[20],n;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    input(arr, n);
    sort(arr, n); 
    output(arr, n); 
    return 0; 
} 
