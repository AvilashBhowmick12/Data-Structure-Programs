#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 50

void bubble_sort(int x[],int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(x[j]>x[j+1])
            {
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
            }
        }
    }
}
void insertion_sort(int x[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp = x[i];
        for(j=i-1;j>=0&&temp<x[j];j--)
        x[j+1] = x[j];
        x[j+1] = temp;
    }
}
int partition(int A[], int lb, int ub)
{
    int pivot = A[lb];
    int i = lb + 1;
    int j = ub;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } 
    while (i < j);
    temp = A[lb];
    A[lb] = A[j];
    A[j] = temp;
    return j;
}
void merge(int a[], int lb, int mid, int ub)
{
    int i,j,k, temp[20];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i=i+1;
        }
        else
        {
            temp[k]=a[j];
            j=j+1;
        }
        k=k+1;
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i=i+1;
        k=k+1;
    }
    while(j<=ub)
    {
        temp[k]=a[j];
        k=k+1;
        j=j+1;
    }
    for(i=lb;i<=ub;i++)
    a[i]=temp[i];
}
void merge_sort(int a[], int lb,int ub)
{
    int mid=0;
    if(lb<ub)
    {
        mid=floor((lb+ub)/2);
        merge_sort(a,lb,mid);
        merge_sort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}
void quick_sort(int A[], int lb, int ub)
{
    int q;
    if (lb < ub)
    {
        q = partition(A, lb, ub);
        quick_sort(A, lb, q - 1);
        quick_sort(A, q + 1, ub);
    }
}
void selection_sort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void heapify(int a[],int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && a[left]>a[largest])
    {
        largest = left;
    }
    if(right<n && a[right]>a[largest])
    {
        largest = right;
    }
    if(largest!=i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a,n,largest);
    }
}
void heap_sort(int a[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        heapify(a,i,0);
    }
}
void main()
{
    int arr[max];
    int ch,n;
    printf("Enter the size of the Array\n");
    scanf("%d",&n);
    printf("Enter The Elements of the Array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(1)
    {
        printf("Choose one option\n");
        printf("1. for Bubble sort\n");
        printf("2. for Insertion sort\n");
        printf("3. for Selection sort\n");
        printf("4. for Merge Sort\n");
        printf("5. for Quick Sort\n");
        printf("6. for Heap Sort\n");
        printf("7. for Exit\n\n");
        printf("Enter Your Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            bubble_sort(arr,n);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 2:
            insertion_sort(arr,n);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 3:
            selection_sort(arr,n);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 4:
            merge_sort(arr,0,n-1);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 5:
            quick_sort(arr,0,n-1);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 6:
            heap_sort(arr,n);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
            case 7:
            exit(1);
            break;
        }
    }
}
