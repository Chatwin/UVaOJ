#include<stdio.h>
#include<string.h>
int G[110][110],w[110],d[110],n;
int q[110],inq[110],inedq[110];
int vis[110],reach[110];
void dfs(int v)
{
    int u;
    for(u=1;u<=n;u++)
        if(G[u][v]&&!vis[u])
        {
            vis[u]=1;
            reach[u]=1;
            dfs(u);
        }
}
int main()
{
    int i,u,v,num,front,rear,flag;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            break;
        memset(G,0,sizeof(G));
        for(u=1;u<=n;u++)
        {
            scanf("%d",&w[u]);
            scanf("%d",&num);
            for(i=0;i<num;i++)
            {
                scanf("%d",&v);
                G[u][v]=1;
            }
        }
        memset(vis,0,sizeof(vis));
        memset(reach,0,sizeof(reach));
        reach[n]=1;
        dfs(n);
        if(!reach[1])
        {
            printf("hopeless\n");
            continue;
        }
        memset(inq,0,sizeof(inq));
        memset(inedq,0,sizeof(inedq));
        memset(d,0,sizeof(d));
        front=rear=0;
        d[1]=100;
        q[rear++]=1;
        inq[1]=1;
        inedq[1]++;
        flag=0;
        while(front!=rear)
        {
            u=q[front++];
            if(front>n)
                front=0;
            inq[u]=0;
            for(v=1;v<=n;v++)
                if(G[u][v]&&reach[v]&&d[u]+w[v]>d[v])
                {
                    d[v]=d[u]+w[v];
                    if(!inq[v])
                    {
                        q[rear++]=v;
                        if(rear>n)
                            rear=0;
                        inq[v]=1;
                        if(inedq[v]++>n)
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            if(d[n]>0||flag)
                break;
        }
        if(d[n]>0||flag)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}
