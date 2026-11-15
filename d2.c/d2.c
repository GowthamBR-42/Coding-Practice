#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int id;
    char name[50];
    struct node *next;
} *head = NULL;
struct node *createNode(int id, char name[])
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->next = NULL;
    return newnode;
}
void enrollStudent(int id, char name[])
{
    struct node *newnode = createNode(id, name);
    if (head == NULL)
        head = newnode;
    else
    {
        newnode->next = head;
        head = newnode;
    }
    printf("\n   Student Enrolled Successfully!\n");
}
void removeStudent(int id)
{
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("\n   Student Not Found!\n");
        return;
    }
    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("\n   Student Removed Successfully!\n");
}
void searchStudent(int id)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\n   Student Found!\n");
            printf("   -------------------------\n");
            printf("   Student ID   : %d\n", temp->id);
            printf("   Student Name : %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }
    printf("\n   Student Not Found!\n");
}
void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\n   No Students Available!\n");
        return;
    }
    printf("\n   ========================================\n");
    printf("              STUDENT DETAILS\n");
    printf("   ========================================\n");
    printf("   %-12s %-20s\n", "STUDENT ID", "STUDENT NAME");
    printf("   ----------------------------------------\n");
    while (temp != NULL)
    {
        printf("   %-12d %-20s\n", temp->id, temp->name);
        temp = temp->next;
    }
    printf("   ========================================\n");
}
void countStudents()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\n   Total Students Enrolled : %d\n", count);
}
void updateStudent(int id, char newname[])
{
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            strcpy(temp->name, newname);
            printf("\n   Student Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("\n   Student Not Found!\n");
}
void lastStudent()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("\n   List is Empty!\n");
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    printf("\n   LAST STUDENT DETAILS\n");
    printf("   -------------------------\n");
    printf("   Student ID   : %d\n", temp->id);
    printf("   Student Name : %s\n", temp->name);
}
void reverseList()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next = NULL;
    if (head == NULL)
    {
        printf("\n   List is Empty!\n");
        return;
    }
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("\n   List Reversed Successfully!\n");
}
int main()
{
    int choice, id;
    char name[50];
    printf("\n");
    printf("   =============================================\n");
    printf("          ONLINE COURSE ENROLLMENT SYSTEM\n");
    printf("   =============================================\n");
    printf("   1.  Enroll Student\n");
    printf("   2.  Remove Student\n");
    printf("   3.  Search Student\n");
    printf("   4.  Display Students\n");
    printf("   5.  Count Students\n");
    printf("   6.  Update Student\n");
    printf("   7.  Last Student\n");
    printf("   8.  Reverse List\n");
    printf("   9.  Exit\n");
    printf("   =============================================\n");
    do
    {
        printf("   Enter Your Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\n   Enter Student ID   : ");
                scanf("%d", &id);
                printf("   Enter Student Name : ");
                scanf(" %[^\n]", name);
                enrollStudent(id, name);
                break;
            case 2:
                printf("\n   Enter Student ID to Remove : ");
                scanf("%d", &id);
                removeStudent(id);
                break;
            case 3:
                printf("\n   Enter Student ID to Search : ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            case 4:
                display();
                break;
            case 5:
                countStudents();
                break;
            case 6:
                printf("\n   Enter Student ID to Update : ");
                scanf("%d", &id);
                printf("   Enter New Student Name     : ");
                scanf(" %[^\n]", name);
                updateStudent(id, name);
                break;
            case 7:
                lastStudent();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                printf("\n   Thank You! Exiting the System.\n");
                break;
            default:
                printf("\n   Invalid Choice! Please Try Again.\n");
        }
    } while (choice != 9);
    return 0;
}
