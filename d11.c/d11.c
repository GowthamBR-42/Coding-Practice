#include<stdio.h>
#include<string.h>
#define MAX 20
#define INF 99999
char attraction[MAX][30];
int graph[MAX][MAX];
int n=0;
void addAttraction()
{
    char name[30];
    int i;
    if(n>=MAX)
    {
        printf("Maximum Attractions Reached!\n");
        return;
    }
    printf("Enter Attraction Name: ");
    scanf("%29s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(attraction[i],name)==0)
        {
            printf("Attraction Already Exists!\n");
            return;
        }
    }
    strcpy(attraction[n],name);
    n++;
    printf("Attraction Added Successfully!\n");
}
int findAttraction(char name[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(attraction[i],name)==0)
            return i;
    }
    return -1;
}
void addConnection()
{
    char a1[30],a2[30];
    int u,v,d;
    printf("Enter First Attraction: ");
    scanf("%29s",a1);
    printf("Enter Second Attraction: ");
    scanf("%29s",a2);
    printf("Enter Distance in KM: ");
    scanf("%d",&d);
    u=findAttraction(a1);
    v=findAttraction(a2);
    if(u==-1 || v==-1)
        printf("Attraction Not Found!\n");
    else if(u==v)
        printf("Cannot Connect an Attraction to Itself!\n");
    else if(d<=0)
        printf("Distance Must Be Positive!\n");
    else
    {
        graph[u][v]=d;
        graph[v][u]=d;
        printf("Connection Added Successfully!\n");
    }
}
void displayGraph()
{
    int i,j;
    if(n==0)
    {
        printf("No Attractions Available!\n");
        return;
    }
    printf("\n========== TOURIST ATTRACTION GRAPH ==========\n");
    for(i=0;i<n;i++)
    {
        printf("%-15s -> ",attraction[i]);
        for(j=0;j<n;j++)
        {
            if(graph[i][j]!=0)
                printf("%s(%d km) ",attraction[j],graph[i][j]);
        }
        printf("\n");
    }
}
void shortestPath(int source,int dest,int showPath)
{
    int dist[MAX],visited[MAX]={0},parent[MAX];
    int i,j,u,min,path[MAX],count=0,temp;
    for(i=0;i<n;i++)
    {
        dist[i]=INF;
        parent[i]=-1;
    }
    dist[source]=0;
    for(i=0;i<n;i++)
    {
        min=INF;
        u=-1;
        for(j=0;j<n;j++)
        {
            if(!visited[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        if(u==-1)
            break;
        visited[u]=1;
        for(j=0;j<n;j++)
        {
            if(graph[u][j]>0 && !visited[j])
            {
                if(dist[u]+graph[u][j]<dist[j])
                {
                    dist[j]=dist[u]+graph[u][j];
                    parent[j]=u;
                }
            }
        }
    }
    if(dist[dest]==INF)
    {
        printf("No Route Available!\n");
        return;
    }
    if(showPath)
    {
        temp=dest;
        while(temp!=-1)
        {
            path[count++]=temp;
            temp=parent[temp];
        }
        printf("Shortest Route Path: ");
        for(i=count-1;i>=0;i--)
        {
            printf("%s",attraction[path[i]]);
            if(i>0)
                printf(" -> ");
        }
        printf("\n");
    }
    printf("Shortest Distance: %d KM\n",dist[dest]);
}
void dijkstra()
{
    char s[30],d[30];
    int source,dest;
    if(n==0)
    {
        printf("No Attractions Available!\n");
        return;
    }
    printf("Enter Source Attraction: ");
    scanf("%29s",s);
    printf("Enter Destination Attraction: ");
    scanf("%29s",d);
    source=findAttraction(s);
    dest=findAttraction(d);
    if(source==-1 || dest==-1)
    {
        printf("Attraction Not Found!\n");
        return;
    }
    shortestPath(source,dest,1);
}
void floydWarshall()
{
    int dist[MAX][MAX];
    int i,j,k;
    if(n==0)
    {
        printf("No Attractions Available!\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else if(graph[i][j]!=0)
                dist[i][j]=graph[i][j];
            else
                dist[i][j]=INF;
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k]!=INF && dist[k][j]!=INF &&
                   dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    printf("\n========== FLOYD-WARSHALL DISTANCE MATRIX ==========\n");
    printf("%-15s"," ");
    for(i=0;i<n;i++)
        printf("%-12s",attraction[i]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%-15s",attraction[i]);
        for(j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
                printf("%-12s","INF");
            else
                printf("%-12d",dist[i][j]);
        }
        printf("\n");
    }
}
void routePath()
{
    char s[30],d[30];
    int source,dest;
    if(n==0)
    {
        printf("No Attractions Available!\n");
        return;
    }
    printf("Enter Source Attraction: ");
    scanf("%29s",s);
    printf("Enter Destination Attraction: ");
    scanf("%29s",d);
    source=findAttraction(s);
    dest=findAttraction(d);
    if(source==-1 || dest==-1)
    {
        printf("Attraction Not Found!\n");
        return;
    }
    shortestPath(source,dest,1);
}
void routeDistance()
{
    char s[30],d[30];
    int source,dest;
    if(n==0)
    {
        printf("No Attractions Available!\n");
        return;
    }
    printf("Enter Source Attraction: ");
    scanf("%29s",s);
    printf("Enter Destination Attraction: ");
    scanf("%29s",d);
    source=findAttraction(s);
    dest=findAttraction(d);
    if(source==-1 || dest==-1)
    {
        printf("Attraction Not Found!\n");
        return;
    }
    shortestPath(source,dest,0);
}
void searchAttraction()
{
    char name[30];
    int pos;
    printf("Enter Attraction to Search: ");
    scanf("%29s",name);
    pos=findAttraction(name);
    if(pos==-1)
        printf("Attraction Not Found!\n");
    else
        printf("Attraction Found: %s\n",attraction[pos]);
}
int main()
{
    int choice;
    printf("\n========== TOURIST ATTRACTION NAVIGATION ==========\n");
    printf("1. Add Attraction\n");
    printf("2. Add Road Connection\n");
    printf("3. Display Graph\n");
    printf("4. Dijkstra Shortest Path\n");
    printf("5. Floyd-Warshall Algorithm\n");
    printf("6. Display Shortest Route Path\n");
    printf("7. Display Shortest Route Distance\n");
    printf("8. Search Attraction\n");
    printf("9. Exit\n");
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addAttraction();
                break;
            case 2:
                addConnection();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                dijkstra();
                break;
            case 5:
                floydWarshall();
                break;
            case 6:
                routePath();
                break;
            case 7:
                routeDistance();
                break;
            case 8:
                searchAttraction();
                break;
            case 9:
                printf("Program Terminated Successfully!\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=9);
    return 0;
}
