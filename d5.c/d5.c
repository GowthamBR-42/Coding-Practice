#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void addPlate(int plate)
{
    if(top == MAX - 1)
        printf("\n   Stack Overflow! Cannot Add Plate.\n");
    else
    {
        top++;
        stack[top] = plate;
        printf("\n   Plate %d Added Successfully!\n", plate);
    }
}
void removePlate()
{
    if(top == -1)
        printf("\n   Stack Underflow! No Plates Available.\n");
    else
    {
        printf("\n   Plate %d Removed Successfully!\n", stack[top]);
        top--;
    }
}
void displayStack()
{
    int i;
    if(top == -1)
        printf("\n   Stack is Empty!\n");
    else
    {
        printf("\n   =================================\n");
        printf("             PLATE STACK\n");
        printf("   =================================\n");
        printf("   TOP\n");
        for(i = top; i >= 0; i--)
            printf("   |       %d       |\n", stack[i]);
        printf("   |_______________|\n");
        printf("   =================================\n");
    }
}
void displayTop()
{
    if(top == -1)
        printf("\n   Stack is Empty!\n");
    else
        printf("\n   Top Plate ID : %d\n", stack[top]);
}
void countPlates()
{
    printf("\n   Total Plates : %d\n", top + 1);
}
void checkStatus()
{
    if(top == -1)
        printf("\n   Stack Status : Empty\n");
    else if(top == MAX - 1)
        printf("\n   Stack Status : Full\n");
    else
        printf("\n   Stack Status : Available\n");
}
void searchPlate(int plate)
{
    int i, found = 0;
    for(i = top; i >= 0; i--)
    {
        if(stack[i] == plate)
        {
            found = 1;
            break;
        }
    }
    if(found)
        printf("\n   Plate %d Found at Position %d!\n", plate, i + 1);
    else
        printf("\n   Plate %d Not Found!\n", plate);
}
void clearStack()
{
    top = -1;
    printf("\n   Stack Cleared Successfully!\n");
}
int main()
{
    int choice, plate;
	printf("\n");
    printf("   =========================================\n");
    printf("           PLATE STACK MANAGEMENT\n");
    printf("   =========================================\n");
    printf("    1. Add Plate\n");
    printf("    2. Remove Plate\n");
    printf("    3. Display Stack\n");
    printf("    4. Display Top Plate\n");
    printf("    5. Count Plates\n");
    printf("    6. Check Stack Status\n");
    printf("    7. Search Plate ID\n");
    printf("    8. Clear Stack\n");
    printf("    9. Exit\n");
    printf("   =========================================\n");
    do
    {
        printf("   Enter Your Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\n   Enter Plate ID : ");
                scanf("%d", &plate);
                addPlate(plate);
                break;
            case 2:
                removePlate();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                displayTop();
                break;
            case 5:
                countPlates();
                break;
            case 6:
                checkStatus();
                break;
            case 7:
                printf("\n   Enter Plate ID to Search : ");
                scanf("%d", &plate);
                searchPlate(plate);
                break;
            case 8:
                clearStack();
                break;
            case 9:
                printf("\n   Thank You! Program Ended.\n");
                break;
            default:
                printf("\n   Invalid Choice! Please Try Again.\n");
        }
    } while(choice != 9);
    return 0;
}
