#include <stdio.h>
#define SIZE 11
#define EMPTY -1
int linear[SIZE],quadratic[SIZE],doublehash[SIZE];
void initialize()
{
    int i;
    for(i=0;i<SIZE;i++)
    {
        linear[i]=EMPTY;
        quadratic[i]=EMPTY;
        doublehash[i]=EMPTY;
    }
}
int hashFunction(int key)
{
    return key%SIZE;
}
int linearSearch(int table[],int key)
{
    int index,i;
    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i)%SIZE;
        if(table[pos]==key)
            return pos;
        if(table[pos]==EMPTY)
            return -1;
    }
    return -1;
}
int quadraticSearch(int table[],int key)
{
    int index,i;
    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i*i)%SIZE;
        if(table[pos]==key)
            return pos;
        if(table[pos]==EMPTY)
            return -1;
    }
    return -1;
}
int doubleHashSearch(int table[],int key)
{
    int index,step,i;
    index=hashFunction(key);
    step=7-(key%7);
    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i*step)%SIZE;
        if(table[pos]==key)
            return pos;
        if(table[pos]==EMPTY)
            return -1;
    }
    return -1;
}
int linearInsert(int key)
{
    int index,i,pos;
    if(linearSearch(linear,key)!=-1)
        return linearSearch(linear,key);
    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        pos=(index+i)%SIZE;
        if(linear[pos]==EMPTY)
        {
            linear[pos]=key;
            return pos;
        }
    }
    return -1;
}
int quadraticInsert(int key)
{
    int index,i,pos;
    if(quadraticSearch(quadratic,key)!=-1)
        return quadraticSearch(quadratic,key);
    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        pos=(index+i*i)%SIZE;
        if(quadratic[pos]==EMPTY)
        {
            quadratic[pos]=key;
            return pos;
        }
    }
    return -1;
}
int doubleHashInsert(int key)
{
    int index,step,i,pos;
    if(doubleHashSearch(doublehash,key)!=-1)
        return doubleHashSearch(doublehash,key);
    index=hashFunction(key);
    step=7-(key%7);
    for(i=0;i<SIZE;i++)
    {
        pos=(index+i*step)%SIZE;
        if(doublehash[pos]==EMPTY)
        {
            doublehash[pos]=key;
            return pos;
        }
    }
    return -1;
}
void addMember()
{
    int id;
    printf("Enter Alumni Member ID: ");
    scanf("%d",&id);
    if(id<0 || id==EMPTY)
    {
        printf("Enter a valid positive Member ID\n");
        return;
    }
    if(linearSearch(linear,id)!=-1)
    {
        printf("Member ID already exists\n");
        return;
    }
    if(linearInsert(id)!=-1)
        printf("Linear Probing: Member inserted\n");
    else
        printf("Linear Probing: Hash table full\n");
    if(quadraticInsert(id)!=-1)
        printf("Quadratic Probing: Member inserted\n");
    else
        printf("Quadratic Probing: No available position in probe sequence\n");
    if(doubleHashInsert(id)!=-1)
        printf("Double Hashing: Member inserted\n");
    else
        printf("Double Hashing: Hash table full\n");
}
void searchMember()
{
    int key,pos;
    printf("Enter Member ID to search: ");
    scanf("%d",&key);
    pos=linearSearch(linear,key);
    if(pos!=-1)
        printf("Linear Probing: Member found at index %d\n",pos);
    else
        printf("Linear Probing: Member not found\n");
    pos=quadraticSearch(quadratic,key);
    if(pos!=-1)
        printf("Quadratic Probing: Member found at index %d\n",pos);
    else
        printf("Quadratic Probing: Member not found\n");
    pos=doubleHashSearch(doublehash,key);
    if(pos!=-1)
        printf("Double Hashing: Member found at index %d\n",pos);
    else
        printf("Double Hashing: Member not found\n");
}
void displayTable(int table[],char name[])
{
    int i;
    printf("\n%s:\n",name);
    for(i=0;i<SIZE;i++)
    {
        if(table[i]==EMPTY)
            printf("Index %d : Empty\n",i);
        else
            printf("Index %d : %d\n",i,table[i]);
    }
}
void display()
{
    displayTable(linear,"Linear Probing");
    displayTable(quadratic,"Quadratic Probing");
    displayTable(doublehash,"Double Hashing");
}
int main()
{
    int choice;
    initialize();
    printf("\n--- ALUMNI MEMBERSHIP VERIFICATION SYSTEM ---\n");
    printf("1. Add Member ID\n");
    printf("2. Search Member ID\n");
    printf("3. Display Linear Probing Table\n");
    printf("4. Display Quadratic Probing Table\n");
    printf("5. Display Double Hashing Table\n");
    printf("6. Display All Hash Tables\n");
    printf("7. Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addMember();
                break;
            case 2:
                searchMember();
                break;
            case 3:
                displayTable(linear,"Linear Probing");
                break;
            case 4:
                displayTable(quadratic,"Quadratic Probing");
                break;
            case 5:
                displayTable(doublehash,"Double Hashing");
                break;
            case 6:
                display();
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
