#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int reg,height;
    struct Node *left,*right;
};
int height(struct Node *n)
{
    return n==NULL?0:n->height;
}
int max(int a,int b)
{
    return a>b?a:b;
}
int balance(struct Node *n)
{
    return n==NULL?0:height(n->left)-height(n->right);
}
struct Node *createNode(int reg)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    n->reg=reg;
    n->height=1;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct Node *rightRotate(struct Node *y)
{
    struct Node *x=y->left;
    struct Node *t=x->right;
    x->right=y;
    y->left=t;
    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));
    return x;
}
struct Node *leftRotate(struct Node *x)
{
    struct Node *y=x->right;
    struct Node *t=y->left;
    y->left=x;
    x->right=t;
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    return y;
}
struct Node *insert(struct Node *root,int reg)
{
    int b;
    if(root==NULL)
        return createNode(reg);
    if(reg<root->reg)
        root->left=insert(root->left,reg);
    else if(reg>root->reg)
        root->right=insert(root->right,reg);
    else
        return root;
    root->height=1+max(height(root->left),height(root->right));
    b=balance(root);
    if(b>1 && reg<root->left->reg)
        return rightRotate(root);
    if(b<-1 && reg>root->right->reg)
        return leftRotate(root);
    if(b>1 && reg>root->left->reg)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(b<-1 && reg<root->right->reg)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct Node *minimum(struct Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
struct Node *maximum(struct Node *root)
{
    if(root==NULL)
        return NULL;
    while(root->right!=NULL)
        root=root->right;
    return root;
}
struct Node *search(struct Node *root,int reg)
{
    if(root==NULL || root->reg==reg)
        return root;
    if(reg<root->reg)
        return search(root->left,reg);
    return search(root->right,reg);
}
struct Node *deleteNode(struct Node *root,int reg)
{
    struct Node *temp;
    int b;
    if(root==NULL)
        return NULL;
    if(reg<root->reg)
        root->left=deleteNode(root->left,reg);
    else if(reg>root->reg)
        root->right=deleteNode(root->right,reg);
    else
    {
        if(root->left==NULL || root->right==NULL)
        {
            temp=root->left?root->left:root->right;
            free(root);
            return temp;
        }
        temp=minimum(root->right);
        root->reg=temp->reg;
        root->right=deleteNode(root->right,temp->reg);
    }
    root->height=1+max(height(root->left),height(root->right));
    b=balance(root);
    if(b>1 && balance(root->left)>=0)
        return rightRotate(root);
    if(b>1 && balance(root->left)<0)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(b<-1 && balance(root->right)<=0)
        return leftRotate(root);
    if(b<-1 && balance(root->right)>0)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->reg);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->reg);
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
        printf("%d ",root->reg);
    }
}
int countNodes(struct Node *root)
{
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
void displayBalance(struct Node *root)
{
    if(root!=NULL)
    {
        displayBalance(root->left);
        printf("%d(%d) ",root->reg,balance(root));
        displayBalance(root->right);
    }
}
int main()
{
    struct Node *root=NULL,*temp;
    int choice,reg;
    do
    {
        printf("\n====== STUDENT PLACEMENT AVL TREE ======\n");
        printf("1. Insert Registration Number\n");
        printf("2. Search Registration Number\n");
        printf("3. Delete Registration Number\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Minimum Registration Number\n");
        printf("8. Maximum Registration Number\n");
        printf("9. Count Registrations\n");
        printf("10. Display Tree Height\n");
        printf("11. Display Balance Factors\n");
        printf("12. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Registration Number: ");
                scanf("%d",&reg);
                if(search(root,reg)!=NULL)
                    printf("Registration Number Already Exists!\n");
                else
                {
                    root=insert(root,reg);
                    printf("Registration Added Successfully!\n");
                }
                break;
            case 2:
                printf("Enter Registration Number to Search: ");
                scanf("%d",&reg);
                if(search(root,reg)!=NULL)
                    printf("Registration Number %d Found!\n",reg);
                else
                    printf("Registration Number Not Found!\n");
                break;
            case 3:
                printf("Enter Registration Number to Delete: ");
                scanf("%d",&reg);
                if(search(root,reg)!=NULL)
                {
                    root=deleteNode(root,reg);
                    printf("Registration Deleted Successfully!\n");
                }
                else
                    printf("Registration Number Not Found!\n");
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
                temp=minimum(root);
                if(temp!=NULL)
                    printf("Minimum Registration Number: %d\n",temp->reg);
                else
                    printf("Tree is Empty!\n");
                break;
            case 8:
                temp=maximum(root);
                if(temp!=NULL)
                    printf("Maximum Registration Number: %d\n",temp->reg);
                else
                    printf("Tree is Empty!\n");
                break;
            case 9:
                printf("Total Registrations: %d\n",countNodes(root));
                break;
            case 10:
                printf("Tree Height: %d\n",height(root));
                break;
            case 11:
                if(root==NULL)
                    printf("Tree is Empty!\n");
                else
                {
                    printf("Registration(Balance Factor): ");
                    displayBalance(root);
                    printf("\n");
                }
                break;
            case 12:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=12);
    return 0;
}
