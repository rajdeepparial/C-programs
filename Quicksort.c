#include <stdio.h>

void input(int a[], int n)
{
    int i;
    printf("ENTER THE ELEMENTS :");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int p = low, q = high;
    while (p < q)
    {
        while (A[p] <= pivot && p<=high )
        {
            p++;
        }
        while (A[q] > pivot)
        {
            q--;
        }
        if (p < q)
        {
            swap(&A[p], &A[q]);
        }
    }
    swap(&A[low], &A[q]);
    return q;
}

void quick_sort(int arr[], int lb, int ub)
{
    int pos;
    if (lb < ub)
    {
        pos = partition(arr, lb, ub);
        quick_sort(arr, lb, pos - 1);
        quick_sort(arr, pos + 1, ub);
    }
}

void output(int a[], int n)
{
    int i;
    printf("sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf(" %d", a[i]);
    }
}

void main()
{
    int a[50], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    input(a, n);
    quick_sort(a, 0, n - 1);
    output(a, n);
}
