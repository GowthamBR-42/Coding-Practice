#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int id;
    char name[20];
    char category[20];
    int urgent;
    int time;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void createTicket(int id, char name[], char category[], int urgent, int time)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("\n   Memory Allocation Failed!\n");
        return;
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->category, category);
    newNode->urgent = urgent;
    newNode->time = time;
    newNode->next = NULL;
    if(rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n   Ticket Created Successfully!\n");
}
void resolveTicket()
{
    struct Node *temp;
    if(front == NULL)
    {
        printf("\n   Queue is Empty!\n");
        return;
    }
    temp = front;
    printf("\n   Ticket %d Resolved Successfully!\n", temp->id);
    front = front->next;
    if(front == NULL)
        rear = NULL;
    free(temp);
}
void displayPending()
{
    struct Node *temp = front;
    if(temp == NULL)
    {
        printf("\n   No Pending Tickets!\n");
        return;
    }
    printf("\n   =============================================\n");
    printf("               PENDING SUPPORT TICKETS\n");
    printf("   =============================================\n");
    printf("   ID       NAME          CATEGORY\n");
    printf("   ---------------------------------------------\n");
    while(temp != NULL)
    {
        printf("   %-8d %-13s %s\n", temp->id, temp->name, temp->category);
        temp = temp->next;
    }
    printf("   =============================================\n");
}
void viewNext()
{
    if(front == NULL)
        printf("\n   No Next Ticket Available!\n");
    else
        printf("\n   Next Ticket : %d - %s\n", front->id, front->name);
}
void viewLatest()
{
    if(rear == NULL)
        printf("\n   No Tickets Available!\n");
    else
        printf("\n   Latest Ticket : %d - %s\n", rear->id, rear->name);
}
void countTickets()
{
    struct Node *temp = front;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\n   Total Pending Tickets : %d\n", count);
}
void queueStatus()
{
    if(front == NULL)
        printf("\n   Queue Status : EMPTY\n");
    else
        printf("\n   Queue Status : NOT EMPTY\n");
}
void searchTicket(int id)
{
    struct Node *temp = front;
    while(temp != NULL)
    {
        if(temp->id == id)
        {
            printf("\n   Ticket Found!\n");
            printf("   Ticket ID : %d\n", temp->id);
            printf("   Name      : %s\n", temp->name);
            printf("   Category  : %s\n", temp->category);
            return;
        }
        temp = temp->next;
    }
    printf("\n   Ticket Not Found!\n");
}
void supportReport()
{
    struct Node *temp = front;
    int count = 0, urgent = 0;
    while(temp != NULL)
    {
        count++;
        if(temp->urgent == 1)
            urgent++;
        temp = temp->next;
    }
    printf("\n   =====================================\n");
    printf("              SUPPORT REPORT\n");
    printf("   =====================================\n");
    printf("   Pending Tickets : %d\n", count);
    printf("   Urgent Tickets  : %d\n", urgent);
    printf("   Normal Tickets  : %d\n", count - urgent);
    printf("   =====================================\n");
}
void resolutionTime()
{
    struct Node *temp = front;
    if(temp == NULL)
    {
        printf("\n   No Pending Tickets!\n");
        return;
    }
    printf("\n   TICKET RESOLUTION TIME\n");
    printf("   -----------------------------\n");
    while(temp != NULL)
    {
        printf("   Ticket %d : %d Minutes\n", temp->id, temp->time);
        temp = temp->next;
    }
}
void categorizeTickets()
{
    struct Node *temp = front;
    if(temp == NULL)
    {
        printf("\n   No Tickets Available!\n");
        return;
    }
    printf("\n   TICKET CATEGORIES\n");
    printf("   -----------------------------\n");
    while(temp != NULL)
    {
        printf("   Ticket %d : %s\n", temp->id, temp->category);
        temp = temp->next;
    }
}
void urgentTickets()
{
    struct Node *temp = front;
    int found = 0;
    printf("\n   URGENT TICKETS\n");
    printf("   -----------------------------\n");
    while(temp != NULL)
    {
        if(temp->urgent == 1)
        {
            printf("   Ticket %d - %s - URGENT\n", temp->id, temp->name);
            found = 1;
        }
        temp = temp->next;
    }
    if(!found)
        printf("   No Urgent Tickets!\n");
}
int main()
{
    int choice, id, urgent, time;
    char name[20], category[20];
    printf("\n");
    printf("   =============================================\n");
    printf("          ONLINE CUSTOMER SUPPORT SYSTEM\n");
    printf("   =============================================\n");
    printf("    1.  Create Support Ticket\n");
    printf("    2.  Resolve Ticket\n");
    printf("    3.  Display Pending Tickets\n");
    printf("    4.  View Next Ticket\n");
    printf("    5.  View Latest Ticket\n");
    printf("    6.  Count Pending Tickets\n");
    printf("    7.  Check Queue Status\n");
    printf("    8.  Search Ticket\n");
    printf("    9.  Support Report\n");
    printf("    10. Resolution Time\n");
    printf("    11. Categorize Tickets\n");
    printf("    12. Display Urgent Tickets\n");
    printf("    13. Exit\n");
    printf("   =============================================\n");
    do
    {
        printf("   Enter Your Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("\n   Enter Ticket ID      : ");
                scanf("%d", &id);
                printf("   Enter Customer Name  : ");
                scanf("%19s", name);
                printf("   Enter Category       : ");
                scanf("%19s", category);
                printf("   Is Urgent (1-Yes, 0-No): ");
                scanf("%d", &urgent);
                printf("   Enter Resolution Time: ");
                scanf("%d", &time);
                if((urgent != 0 && urgent != 1) || time < 0)
                    printf("\n   Invalid Input!\n");
                else
                    createTicket(id, name, category, urgent, time);
                break;
            case 2:
                resolveTicket();
                break;
            case 3:
                displayPending();
                break;
            case 4:
                viewNext();
                break;
            case 5:
                viewLatest();
                break;
            case 6:
                countTickets();
                break;
            case 7:
                queueStatus();
                break;
            case 8:
                printf("\n   Enter Ticket ID to Search : ");
                scanf("%d", &id);
                searchTicket(id);
                break;
            case 9:
                supportReport();
                break;
            case 10:
                resolutionTime();
                break;
            case 11:
                categorizeTickets();
                break;
            case 12:
                urgentTickets();
                break;
            case 13:
                printf("\n   Thank You! Program Ended.\n");
                break;
            default:
                printf("\n   Invalid Choice! Please Try Again.\n");
        }
    }while(choice != 13);
    return 0;
}
