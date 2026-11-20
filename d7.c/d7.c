#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char course[30];
    struct Node *left,*right;
};
struct Node *root=NULL;
struct Node *createCourse(char course[])
{
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    strcpy(newNode->course,course);
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node *addCourse(struct Node *root,char course[])
{
    if(root==NULL)
        return createCourse(course);
    if(strcmp(course,root->course)<0)
        root->left=addCourse(root->left,course);
    else if(strcmp(course,root->course)>0)
        root->right=addCourse(root->right,course);
    else
        printf("Course Already Exists!\n");
    return root;
}
void inorder(struct Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%s ",root->course);
        inorder(root->right);
    }
}
void preorder(struct Node *root)
{
    if(root!=NULL)
    {
        printf("%s ",root->course);
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
        printf("%s ",root->course);
    }
}
void searchCourse(struct Node *root,char course[])
{
    if(root==NULL)
    {
        printf("Course Not Found!\n");
        return;
    }
    if(strcmp(root->course,course)==0)
    {
        printf("Course Found: %s\n",root->course);
        return;
    }
    if(strcmp(course,root->course)<0)
        searchCourse(root->left,course);
    else
        searchCourse(root->right,course);
}
int countCourses(struct Node *root)
{
    if(root==NULL)
        return 0;
    return 1+countCourses(root->left)+countCourses(root->right);
}
int treeDepth(struct Node *root)
{
    int left,right;
    if(root==NULL)
        return 0;
    left=treeDepth(root->left);
    right=treeDepth(root->right);
    return (left>right?left:right)+1;
}
int leafCourses(struct Node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return leafCourses(root->left)+leafCourses(root->right);
}
void displayPrerequisites(struct Node *root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            printf("%s -> %s\n",root->left->course,root->course);
        if(root->right!=NULL)
            printf("%s -> %s\n",root->right->course,root->course);
        displayPrerequisites(root->left);
        displayPrerequisites(root->right);
    }
}
void levelOrder(struct Node *root)
{
    struct Node *queue[100];
    int front=0,rear=0;
    if(root==NULL)
    {
        printf("Tree is Empty!\n");
        return;
    }
    queue[rear++]=root;
    while(front<rear)
    {
        struct Node *temp=queue[front++];
        printf("%s ",temp->course);
        if(temp->left!=NULL && rear<100)
            queue[rear++]=temp->left;
        if(temp->right!=NULL && rear<100)
            queue[rear++]=temp->right;
    }
}
void longestChain(struct Node *root,struct Node *path[],int level,struct Node *best[],int *max)
{
    int i;
    if(root==NULL)
        return;
    path[level]=root;
    if(root->left==NULL && root->right==NULL)
    {
        if(level+1>*max)
        {
            *max=level+1;
            for(i=0;i<=level;i++)
                best[i]=path[i];
        }
        return;
    }
    longestChain(root->left,path,level+1,best,max);
    longestChain(root->right,path,level+1,best,max);
}
void displayLongestChain(struct Node *root)
{
    struct Node *path[100],*best[100];
    int max=0,i;
    longestChain(root,path,0,best,&max);
    if(max==0)
    {
        printf("Tree is Empty!\n");
        return;
    }
    printf("Longest Course Chain: ");
    for(i=0;i<max;i++)
        printf("%s ",best[i]->course);
    printf("\nChain Length: %d\n",max);
}
void curriculumReport(struct Node *root)
{
    printf("\n========== CURRICULUM REPORT ==========\n");
    printf("Total Courses : %d\n",countCourses(root));
    printf("Tree Depth    : %d\n",treeDepth(root));
    printf("Leaf Courses  : %d\n",leafCourses(root));
    printf("Inorder       : ");
    inorder(root);
    printf("\nLevel Order   : ");
    levelOrder(root);
    printf("\n");
    displayLongestChain(root);
    printf("=======================================\n");
}
int main()
{
    int choice;
    char course[30];
    printf("\n====== UNIVERSITY COURSE TREE ======\n");
    printf("1. Add Course\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Search Course\n");
    printf("6. Count Courses\n");
    printf("7. Find Tree Depth\n");
    printf("8. Display Prerequisites\n");
    printf("9. Level Order Traversal\n");
    printf("10. Count Leaf Courses\n");
    printf("11. Longest Course Chain\n");
    printf("12. Curriculum Report\n");
    printf("13. Exit\n");
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Course Name: ");
                scanf("%29s",course);
                root=addCourse(root,course);
                printf("Course Added Successfully!\n");
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter Course to Search: ");
                scanf("%29s",course);
                searchCourse(root,course);
                break;
            case 6:
                printf("Total Courses: %d\n",countCourses(root));
                break;
            case 7:
                printf("Tree Depth: %d\n",treeDepth(root));
                break;
            case 8:
                printf("\nPrerequisite Relationships:\n");
                displayPrerequisites(root);
                break;
            case 9:
                printf("Level Order Traversal: ");
                levelOrder(root);
                printf("\n");
                break;
            case 10:
                printf("Leaf Courses: %d\n",leafCourses(root));
                break;
            case 11:
                displayLongestChain(root);
                break;
            case 12:
                curriculumReport(root);
                break;
            case 13:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=13);
    return 0;
}
