#include <stdio.h>
#include <stdlib.h>

int a[100][100],n,visited[100];
int q[100],front=-1,rear=-1;
int s[100],top=-1;
int temp=0;

void adjmatrix()
{
    int i,j;

    printf("Enter The Number Of Vertices\n");
    scanf("%d",&n);
    printf("Enter The Elements Into Adjacency Matrix Of Order %d*%d\n",n,n);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    printf("Adjacency Matrix Created Successfully\n");
}

void bfs(int v)
{
    int i,cur;
    visited[v]=1;
    q[++rear]=v;

    while(front!=rear)
    {
        cur=q[++front];

        for(i=1;i<=n;i++)
        {
            if((a[cur][i]==1)&&(visited[i]==0))
            {
                q[++rear]=i;
                visited[i]=1;
                printf("%d Reachable From %d\n",i,v);
            }
        }
    }
}

void dfs(int v)
{
    int i;
    visited[v]=1;
    s[++top]=v;

    for(i=1;i<=n;i++)
    {
        if((a[v][i]==1)&&(!visited[i]))
        {
            printf("%d Reachable From %d\n",i,v);
            dfs(i);
            temp=temp+1;
        }
    }
}

void main()
{
    int ch,i,start;
    adjmatrix();

    for(;;)
    {
        printf("Enter 1: BFS Traversal\nEnter 2: DFS Traversal\nEnter 3: Exit\nEnter Your Choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                for(i=1;i<=n;i++)
                    visited[i]=0;
                printf("Enter The Starting Vertex\n");
                scanf("%d",&start);
                bfs(start);
                for(i=1;i<=n;i++)
                {
                    if(visited[i]==0)
                        printf("%d Not Reachable From %d\n",i,start);
                }
                break;
            case 2:
                for(i=1;i<=n;i++)
                    visited[i]=0;
                printf("Enter The Starting Vertex\n");
                scanf("%d",&start);
                dfs(start);
                if(temp==0)
                {
                    for(i=1;i<=n;i++)
                    {
                        if(i==start)
                            continue;
                        printf("%d Not Reachable From %d\n",i,start);
                    }
                }
                break;
            case 3:
                printf("Thank You\n");
                exit(0);
            default:
                printf("Invalid Input Entered..Please Try Again\n");

        }
    }
}