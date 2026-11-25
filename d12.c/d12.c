#include <stdio.h>
#define MAX 50
void display(int a[],int n)
{
    int i;
    if(n==0)
    {
        printf("No membership records available\n");
        return;
    }
    printf("\nMembership IDs:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
void addID(int a[],int *n)
{
    if(*n==MAX)
    {
        printf("Membership list is full\n");
        return;
    }
    printf("Enter membership ID: ");
    scanf("%d",&a[*n]);
    (*n)++;
    printf("Membership ID added successfully\n");
}
void linearSearch(int a[],int n)
{
    int key,i,found=0;
    printf("Enter membership ID to search: ");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("ID found at position %d\n",i+1);
            found=1;
            break;
        }
    }
    if(!found)
        printf("ID not found\n");
}
void selectionSort(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
void binarySearch(int a[],int n)
{
    int key,low=0,high=n-1,mid,found=0;
    selectionSort(a,n);
    printf("Enter membership ID to search: ");
    scanf("%d",&key);
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==key)
        {
            printf("ID found at sorted position %d\n",mid+1);
            found=1;
            break;
        }
        else if(key<a[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    if(!found)
        printf("ID not found\n");
}
void heapify(int a[],int n,int i)
{
    int largest=i,left=2*i+1,right=2*i+2,temp;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
int main()
{
    int a[MAX],n,i,choice;
    printf("Enter number of alumni membership IDs: ");
    scanf("%d",&n);
    if(n<0 || n>MAX)
    {
        printf("Invalid number of membership IDs\n");
        return 0;
    }
    printf("Enter membership IDs:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    do
    {
        printf("\n--- ALUMNI MEMBERSHIP MANAGEMENT ---\n");
        printf("1. Add Membership ID\n");
        printf("2. Display Membership Records\n");
        printf("3. Linear Search\n");
        printf("4. Binary Search\n");
        printf("5. Selection Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addID(a,&n);
                break;
            case 2:
                display(a,n);
                break;
            case 3:
                linearSearch(a,n);
                break;
            case 4:
                binarySearch(a,n);
                break;
            case 5:
                selectionSort(a,n);
                printf("After Selection Sort:");
                display(a,n);
                break;
            case 6:
                heapSort(a,n);
                printf("After Heap Sort:");
                display(a,n);
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=7);
    return 0;
}
