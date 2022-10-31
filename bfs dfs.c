#include <stdio.h>
#include <stdlib.h>

int f = 0, r = -1, q[10], t = -1, s[10];
void enque(int item)
{
    q[++r] = item;
}
int deque()
{
    return (q[f++]);
}
void push(int item)
{
    s[++t] = item;
}
int pop()
{
    return(s[t--]);
}
void dfs(int a[10][10],int s,int v)
{
    int visit[10] = {0};
    push(s);
    visit[s] = 1;
    while(t>=0)
    {
        int d = pop();
        printf("\t%d", d);
        for (int i = 0; i <v;i++)
        {
            if (a[d][i]&&!visit[i])
            {
                push(i);
                visit[i] = 1;
            }
        }
    }
}
void bfs(int a[10][10],int s ,int v)
{
    int visit[10] = {0};
    enque(s);
    visit[s] = 1;
    while(r>=f)
    {
        int d = deque();
        printf("\t%d", d);
        for (int i = 0; i < v;i++)
        {
            if(a[d][i]&&!visit[i])
            {
                enque(i);
                visit[i] = 1;
            }
        }
    }
}
void main()
{
    int v, a[10][10], s, ch;
    printf("Enter number of vertex : ");
    scanf("%d", &v);
    printf("Enter the adjacency matrix : ");
    for (int i = 0; i < v;i++)
    {
        for (int j = 0; j < v;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter starting vertex : ");
    scanf("%d", &s);
    printf("\nDFS : ");
    dfs(a, s, v);
    printf("\nBFS : ");
    bfs(a, s, v);
}