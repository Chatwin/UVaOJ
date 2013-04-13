#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 101;
int c[MAXN], G[MAXN][MAXN];
int topo[MAXN], t;
int n, m;

bool dfs(int u)
{
   c[u] = -1;
   for (int v = 1; v <= n; v++)
   {
      if (G[u][v])
      {
         if (c[v] < 0)
         {
            return false;
         }
         else if (! c[v] && !dfs(v))
         {
            return false;
         }
      }
   }
   c[u] = 1;
   topo[-- t] = u;
   return true;
}

bool toposort()
{
   t = n;
   memset(c, 0, sizeof(c));
   for (int i = 1; i <= n; i ++)
   {
      if (! c[i])
      {
         if (! dfs(i))
         {
            return false;
         }
      }
   }
   return true;
}
int main()
{
    while (cin>>n>>m)
    {
       int x, y;
       if (n == 0 && m== 0) {break;}
       memset(G, 0, sizeof(G));
       for (int i = 0; i < m; i ++)
       {
          cin>>x>>y;
          G[x][y] = 1;
       }
       if (toposort())
       {
          int i;
          for (i = 0; i < n - 1; i ++)
          {
             cout<<topo[i]<<" ";
          }
          cout<<topo[i]<<endl;
       }
    }
    return 0;
}
