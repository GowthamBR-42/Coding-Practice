#include<stdio.h>
#include<string.h>
#define MAX 20
char station[MAX][30];
int graph[MAX][MAX];
int n=0;
void addStation()
{
    char name[30];
    int i;
    if(n>=MAX)
    {
        printf("Maximum Stations Reached!\n");
        return;
    }
    printf("Enter Station Name: ");
    scanf("%29s",name);
    for(i=0;i<n;i++)
    {
        if(strcmp(station[i],name)==0)
        {
            printf("Station Already Exists!\n");
            return;
        }
    }
    strcpy(station[n],name);
    n++;
    printf("Station Added Successfully!\n");
}
int findStation(char name[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(station[i],name)==0)
            return i;
    }
    return -1;
}
void addRoute()
{
    char s1[30],s2[30];
    int a,b;
    printf("Enter First Station: ");
    scanf("%29s",s1);
    printf("Enter Second Station: ");
    scanf("%29s",s2);
    a=findStation(s1);
    b=findStation(s2);
    if(a==-1 || b==-1)
        printf("Station Not Found!\n");
    else if(a==b)
        printf("Cannot Add Route to the Same Station!\n");
    else if(graph[a][b])
        printf("Route Already Exists!\n");
    else
    {
        graph[a][b]=1;
        graph[b][a]=1;
        printf("Route Added Successfully!\n");
    }
}
void displayGraph()
{
    int i,j;
    if(n==0)
    {
        printf("No Stations Available!\n");
        return;
    }
    printf("\n========== METRO GRAPH ==========\n");
    for(i=0;i<n;i++)
    {
        printf("%-15s -> ",station[i]);
        for(j=0;j<n;j++)
        {
            if(graph[i][j])
                printf("%s ",station[j]);
        }
        printf("\n");
    }
}
void bfs(int start)
{
    int visited[MAX]={0};
    int queue[MAX];
    int front=0,rear=0;
    int i,current;
    queue[rear++]=start;
    visited[start]=1;
    printf("BFS Traversal: ");
    while(front<rear)
    {
        current=queue[front++];
        printf("%s ",station[current]);
        for(i=0;i<n;i++)
        {
            if(graph[current][i] && !visited[i])
            {
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
    printf("\n");
}
void dfs(int start,int visited[])
{
    int i;
    visited[start]=1;
    printf("%s ",station[start]);
    for(i=0;i<n;i++)
    {
        if(graph[start][i] && !visited[i])
            dfs(i,visited);
    }
}
void performBFS()
{
    char name[30];
    int start;
    if(n==0)
    {
        printf("No Stations Available!\n");
        return;
    }
    printf("Enter Starting Station: ");
    scanf("%29s",name);
    start=findStation(name);
    if(start==-1)
        printf("Station Not Found!\n");
    else
        bfs(start);
}
void performDFS()
{
    char name[30];
    int start;
    int visited[MAX]={0};
    if(n==0)
    {
        printf("No Stations Available!\n");
        return;
    }
    printf("Enter Starting Station: ");
    scanf("%29s",name);
    start=findStation(name);
    if(start==-1)
        printf("Station Not Found!\n");
    else
    {
        printf("DFS Traversal: ");
        dfs(start,visited);
        printf("\n");
    }
}
void searchStation()
{
    char name[30];
    int pos;
    printf("Enter Station to Search: ");
    scanf("%29s",name);
    pos=findStation(name);
    if(pos==-1)
        printf("Station Not Found!\n");
    else
        printf("Station Found: %s\n",station[pos]);
}
int countRoutes()
{
    int i,j,routes=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(graph[i][j])
                routes++;
        }
    }
    return routes;
}
void countDetails()
{
    printf("Total Stations: %d\n",n);
    printf("Total Routes: %d\n",countRoutes());
}
void connectedStations()
{
    char name[30];
    int pos,i,found=0;
    printf("Enter Station Name: ");
    scanf("%29s",name);
    pos=findStation(name);
    if(pos==-1)
    {
        printf("Station Not Found!\n");
        return;
    }
    printf("Connected Stations of %s: ",station[pos]);
    for(i=0;i<n;i++)
    {
        if(graph[pos][i])
        {
            printf("%s ",station[i]);
            found=1;
        }
    }
    if(!found)
        printf("No Connected Stations");
    printf("\n");
}
void routeReport()
{
    int i,j;
    if(n==0)
    {
        printf("No Stations Available!\n");
        return;
    }
    printf("\n========== METRO ROUTE REPORT ==========\n");
    for(i=0;i<n;i++)
    {
        printf("%-15s : ",station[i]);
        for(j=0;j<n;j++)
        {
            if(graph[i][j])
                printf("%s ",station[j]);
        }
        printf("\n");
    }
    printf("---------------------------------------\n");
    printf("Total Stations : %d\n",n);
    printf("Total Routes   : %d\n",countRoutes());
    printf("=======================================\n");
}
int main()
{
    int choice;
    printf("\n========== METRO RAIL ROUTE EXPLORER ==========\n");
    printf("1. Add Station\n");
    printf("2. Add Route\n");
    printf("3. Display Graph\n");
    printf("4. Breadth First Search (BFS)\n");
    printf("5. Depth First Search (DFS)\n");
    printf("6. Search Station\n");
    printf("7. Count Stations and Routes\n");
    printf("8. Display Connected Stations\n");
    printf("9. Generate Route Report\n");
    printf("10. Exit\n");
    do
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addStation();
                break;
            case 2:
                addRoute();
                break;
            case 3:
                displayGraph();
                break;
            case 4:
                performBFS();
                break;
            case 5:
                performDFS();
                break;
            case 6:
                searchStation();
                break;
            case 7:
                countDetails();
                break;
            case 8:
                connectedStations();
                break;
            case 9:
                routeReport();
                break;
            case 10:
                printf("Program Terminated Successfully!\n");
                break;
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }while(choice!=10);
    return 0;
}
