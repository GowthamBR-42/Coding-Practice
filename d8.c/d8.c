#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int id;
    struct Node *left,*right;
};
struct Node *createNode(int id)
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    newNode->id=id;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node *insert(struct Node *root,int id)
{
    if(root==NULL)
        return createNode(id);
    if(id<root->id)
        root->left=insert(root->left,id);
    else if(id>root->id)
        root->right=insert(root->right,id);
    else
        printf("Booking ID Already Exists!\n");
    return root;
}
struct Node *search(struct Node *root,int id)
{
    if(root==NULL || root->id==id)
        return root;
    if(id<root->id)
        return search(root->left,id);
    return search(root->right,id);
}
struct Node *smallest(struct Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct Node *largest(struct Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
        root=root->right;
    return root;
}
struct Node *deleteNode(struct Node *root,int id)
{
    struct Node *temp;
    if(root==NULL)
        return NULL;
    if(id<root->id)
        root->left=deleteNode(root->left,id);
    else if(id>root->id)
        root->right=deleteNode(root->right,id);
    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=smallest(root->right);
        root->id=temp->id;
        root->right=deleteNode(root->right,temp->id);
    }
    return root;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->id);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->id);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->id);
    }
}
int main()
{
    struct Node *root=NULL,*temp;
    int choice,id;
    printf("\n====== MOVIE TICKET BOOKING SYSTEM ======\n");
    printf("1. Insert Booking ID\n");
    printf("2. Search Booking ID\n");
    printf("3. Delete Booking ID\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Smallest Booking ID\n");
    printf("8. Largest Booking ID\n");
    printf("9. Exit\n");
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Booking ID: ");
                scanf("%d",&id);
                if(search(root,id)!=NULL)
                    printf("Booking ID Already Exists!\n");
                else
                {
                    root=insert(root,id);
                    printf("Booking ID Inserted Successfully!\n");
                }
                break;
            case 2:
                printf("Enter Booking ID to Search: ");
                scanf("%d",&id);
                temp=search(root,id);
                if(temp!=NULL)
                    printf("Booking ID %d Found!\n",id);
                else
                    printf("Booking ID Not Found!\n");
                break;
            case 3:
                printf("Enter Booking ID to Delete: ");
                scanf("%d",&id);
                if(search(root,id)!=NULL)
                {
                    root=deleteNode(root,id);
                    printf("Booking ID Deleted Successfully!\n");
                }
                else
                    printf("Booking ID Not Found!\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                if(root==NULL)
                    printf("Tree is Empty!");
                else
                    inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                if(root==NULL)
                    printf("Tree is Empty!");
                else
                    preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                if(root==NULL)
                    printf("Tree is Empty!");
                else
                    postorder(root);
                printf("\n");
                break;
            case 7:
                temp=smallest(root);
                if(temp!=NULL)
                    printf("Smallest Booking ID: %d\n",temp->id);
                else
                    printf("Tree is Empty!\n");
                break;
            case 8:
                temp=largest(root);
                if(temp!=NULL)
                    printf("Largest Booking ID: %d\n",temp->id);
                else
                    printf("Tree is Empty!\n");
                break;
            case 9:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=9);
    return 0;
}
