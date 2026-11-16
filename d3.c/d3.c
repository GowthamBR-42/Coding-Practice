#include <stdio.h>
#include <stdlib.h>
struct node
{
    int id;
    struct node *prev;
    struct node *next;
} *head = NULL;
struct node *createNode(int id)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->id = id;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void addMember(int id)
{
    struct node *newnode = createNode(id);
    struct node *temp;
    if (head == NULL)
    {
        head = newnode;
        printf("\n   Member Added Successfully!\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    printf("\n   Member Added Successfully!\n");
}
void deleteMember(int id)
{
    struct node *temp = head;
    while (temp != NULL && temp->id != id)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n   Member Not Found!\n");
        return;
    }
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }
    free(temp);
    printf("\n   Member Deleted Successfully!\n");
}
void searchMember(int id)
{
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\n   Member Found!\n");
            printf("   Alumni ID : %d\n", temp->id);
            printf("   Position  : %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\n   Member Not Found!\n");
}
void displayForward()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\n   Directory Empty!\n");
        return;
    }
    printf("\n   =====================================\n");
    printf("             FORWARD DIRECTORY\n");
    printf("   =====================================\n");
    while (temp != NULL)
    {
        printf("   [%d] <-> ", temp->id);
        temp = temp->next;
    }

    printf("NULL\n");
    printf("   =====================================\n");
}
void displayBackward()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\n   Directory Empty!\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    printf("\n   =====================================\n");
    printf("            BACKWARD DIRECTORY\n");
    printf("   =====================================\n");
    while (temp != NULL)
    {
        printf("   [%d] <-> ", temp->id);
        temp = temp->prev;
    }
    printf("NULL\n");
    printf("   =====================================\n");
}
void insertPosition(int pos, int id)
{
    struct node *newnode;
    struct node *temp = head;
    int i;
    if (pos < 1)
    {
        printf("\n   Invalid Position!\n");
        return;
    }
    newnode = createNode(id);
    if (pos == 1)
    {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
        printf("\n   Member Inserted Successfully!\n");
        return;
    }
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n   Invalid Position!\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    printf("\n   Member Inserted Successfully!\n");
}
void deletePosition(int pos)
{
    struct node *temp = head;
    int i;
    if (head == NULL)
    {
        printf("\n   Directory Empty!\n");
        return;
    }
    if (pos < 1)
    {
        printf("\n   Invalid Position!\n");
        return;
    }
    if (pos == 1)
    {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("\n   Member Deleted Successfully!\n");
        return;
    }
    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("\n   Invalid Position!\n");
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    printf("\n   Member Deleted Successfully!\n");
}
void countMembers()
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\n   Total Alumni Members : %d\n", count);
}
int main()
{
    int ch, id, pos;
    do
    {
        printf("\n");
        printf("   =============================================\n");
        printf("             ALUMNI DIRECTORY SYSTEM\n");
        printf("   =============================================\n");
        printf("    1. Add Alumni Member\n");
        printf("    2. Delete Alumni Member\n");
        printf("    3. Search Alumni Member\n");
        printf("    4. Display Forward\n");
        printf("    5. Display Backward\n");
        printf("    6. Insert Member at Position\n");
        printf("    7. Delete Member at Position\n");
        printf("    8. Count Total Members\n");
        printf("    9. Exit\n");
        printf("   =============================================\n");
        printf("   Enter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("\n   Enter Alumni ID : ");
                scanf("%d", &id);
                addMember(id);
                break;
            case 2:
                printf("\n   Enter Alumni ID to Delete : ");
                scanf("%d", &id);
                deleteMember(id);
                break;
            case 3:
                printf("\n   Enter Alumni ID to Search : ");
                scanf("%d", &id);
                searchMember(id);
                break;
            case 4:
                displayForward();
                break;
            case 5:
                displayBackward();
                break;
            case 6:
                printf("\n   Enter Position  : ");
                scanf("%d", &pos);
                printf("   Enter Alumni ID : ");
                scanf("%d", &id);
                insertPosition(pos, id);
                break;
            case 7:
                printf("\n   Enter Position to Delete : ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            case 8:
                countMembers();
                break;
            case 9:
                printf("\n   Thank You! Exiting the System.\n");
                break;
            default:
                printf("\n   Invalid Choice! Please Try Again.\n");
        }
    } while (ch != 9);
    return 0;
}
