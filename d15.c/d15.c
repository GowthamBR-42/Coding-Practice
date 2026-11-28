#include <stdio.h>
#define MAX 20
#define INF 9999
int main()
{
    int graph[MAX][MAX],visited[MAX]={0};
    int n,i,j,edges=0,min,u=-1,v=-1,total=0,choice;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    if(n<=0 || n>MAX)
    {
        printf("Invalid number of vertices\n");
        return 0;
    }
    printf("Enter adjacency matrix (0 for no edge):\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
            if(i==j)
                graph[i][j]=INF;
            else if(graph[i][j]==0)
                graph[i][j]=INF;
        }
    }
    do
    {
        printf("\n--- PRIM'S ALGORITHM ---\n");
        printf("1. Display Graph\n");
        printf("2. Find Minimum Spanning Tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nAdjacency Matrix:\n");
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        if(graph[i][j]==INF)
                            printf("0 ");
                        else
                            printf("%d ",graph[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                for(i=0;i<n;i++)
                    visited[i]=0;
                visited[0]=1;
                edges=0;
                total=0;
                printf("\nMinimum Spanning Tree:\n");
                printf("Edge\tWeight\n");
                while(edges<n-1)
                {
                    min=INF;
                    u=-1;
                    v=-1;
                    for(i=0;i<n;i++)
                    {
                        if(visited[i])
                        {
                            for(j=0;j<n;j++)
                            {
                                if(!visited[j] && graph[i][j]<min)
                                {
                                    min=graph[i][j];
                                    u=i;
                                    v=j;
                                }
                            }
                        }
                    }
                    if(u==-1)
                    {
                        printf("Graph is disconnected. MST not possible.\n");
                        break;
                    }
                    printf("%d - %d\t%d\n",u,v,min);
                    visited[v]=1;
                    total+=min;
                    edges++;
                }
                if(edges==n-1)
                    printf("Total Minimum Cost = %d\n",total);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=3);
    return 0;
}
