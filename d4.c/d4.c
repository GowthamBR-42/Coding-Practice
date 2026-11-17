#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createCircle(int n)
{
    struct Node *head = NULL;
    struct Node *temp, *newNode;
    int i;
    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
            return head;
        newNode->data = i;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            newNode->next = head;
            temp = newNode;
        }
    }
    return head;
}
int josephus(struct Node *head, int k)
{
    struct Node *ptr = head, *prev = head;
    int count;
    while (prev->next != head)
        prev = prev->next;

    printf("\n   ELIMINATION PROCESS\n");
    printf("   -------------------------\n");
    while (ptr->next != ptr)
    {
        count = 1;
        while (count < k)
        {
            prev = ptr;
            ptr = ptr->next;
            count++;
        }
        printf("   Eliminated : %d\n", ptr->data);
        prev->next = ptr->next;
        free(ptr);
        ptr = prev->next;
    }
    count = ptr->data;
    free(ptr);
    return count;
}
int main()
{
    int n, k, survivor;
    struct Node *head;
    printf("\n");
    printf("   =====================================\n");
    printf("          JOSEPHUS PROBLEM\n");
    printf("       CIRCULAR LINKED LIST\n");
    printf("   =====================================\n");
    printf("\n   Enter Number of People (N) : ");
    scanf("%d", &n);
    printf("   Enter Step Count (K)       : ");
    scanf("%d", &k);
    if (n <= 0 || k <= 0)
    {
        printf("\n   Invalid Input! Enter Positive Values.\n");
        return 0;
    }
    head = createCircle(n);
    if (head == NULL)
    {
        printf("\n   Memory Allocation Failed!\n");
        return 0;
    }
    survivor = josephus(head, k);
    printf("\n");
    printf("   =====================================\n");
    printf("             FINAL RESULT\n");
    printf("   =====================================\n");
    printf("   Last Surviving Person : %d\n", survivor);
    printf("   =====================================\n");
    return 0;
}
