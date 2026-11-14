#include <stdio.h>
#define Max 100
int a[Max] = {10,20,30,40,50};
int n = 5;
int i, pos, ele;
void insertbeg()
{
    if(n == Max)
    {
        printf("List is full");
        return;
    }
    printf("Enter element:");
    scanf("%d",&ele);
    for(i=n;i>0;i--)
    {
        a[i] = a[i-1];
    }
    a[0] = ele;
    n++;
    printf("Element is inserted successfully");
}

void insertend()
{
    if(n == Max)
    {
        printf("List is full");
        return;
    }
    printf("Enter element:");
    scanf("%d",&ele);
    a[n] = ele;
    n++;
    printf("Element is inserted successfully");
}

void insertspecpos()
{
    if(n == Max)
    {
        printf("List is full");
        return;
    }
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos < 1 || pos > n+1)
    {
        printf("Invalid position");
        return;
    }
    printf("Enter element:");
    scanf("%d",&ele);
    for(i=n;i>=pos;i--)
    {
        a[i] = a[i-1];
    }
    a[pos-1] = ele;
    n++;
    printf("Element is inserted in specified position");
}

void deletebeg()
{
    if(n == 0)
    {
        printf("List is empty");
        return;
    }
    for(i=0;i<n-1;i++)
    {
        a[i] = a[i+1];
    }
    n--;
    printf("Delete element");
}

void deleteend()
{
    if(n == 0)
    {
        printf("List is empty");
        return;
    }
    n--;
    printf("Delete Element");
}

void deletespecpos()
{
    if(n == 0)
    {
        printf("List is empty");
        return;
    }
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos < 1 || pos > n)
    {
        printf("Invalid position");
        return;
    }
    for(i=pos-1;i<n-1;i++)
    {
        a[i] = a[i+1];
    }
    n--;
}

void search()
{
    int found = 0;
    printf("Enter element to search:");
    scanf("%d",&ele);
    for(i=0;i<n;i++)
    {
        if(a[i] == ele)
        {
            printf("Element found %d\n",i+1);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Element is not found\n");
}

void update()
{
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos < 1 || pos > n)
    {
        printf("Invalid position");
        return;
    }
    printf("Enter new element:");
    scanf("%d",&ele);
    a[pos-1] = ele;
}

void display()
{
    if(n == 0)
    {
        printf("List is empty");
        return;
    }
    printf("Array elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}

void size()
{
    printf("Size:%d\n",n);
}

void empty()
{
    if(n == 0)
    {
        printf("List is empty\n");
    }
    else
        printf("List is not empty\n");
}

int main()
{
    int choice;
    printf("\n-----LIST ADT USING ARRAY-----");
    printf("\n1. Insert Beginning");
    printf("\n2. Insert End");
    printf("\n3. Insert Specified position");
    printf("\n4. Delete Beginning");
    printf("\n5. Delete End");
    printf("\n6. Delete Specified position");
    printf("\n7. Search");
    printf("\n8. Update");
    printf("\n9. Display");
    printf("\n10. Size");
    printf("\n11. Empty");
    printf("\n12. Exit");

    do
    {
        printf("\nEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertbeg();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertspecpos();
                break;
            case 4:
                deletebeg();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                deletespecpos();
                break;
            case 7:
                search();
                break;
            case 8:
                update();
                break;
            case 9:
                display();
                break;
            case 10:
                size();
                break;
            case 11:
                empty();
                break;
            case 12:
                printf("Program is exited\n");
                break;
            default:
                printf("Invalid case");
        }
    }
    while(choice != 12);

    return 0;
}
