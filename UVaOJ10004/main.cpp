#include <iostream>
#include <cstring>
using namespace std;

int G[200][200], paint[200 * 200];
int n, l;

bool dfs(int u, int color)
{
   for (int v = 0; v < n; v ++)
   {
      if (G[u][v] == 1)
      {
         if (paint[v] != -1 && paint[v] != color)
         {
            return false;
         }
         else if (paint[v] == -1)
         {
            paint[v] = color;
            if (! dfs(v, 1 - color))
            {
               return false;
            }
         }
      }
   }
   return true;
}

int main()
{
    int u, v;
    while (cin>>n)
    {
       if (n == 0)
       {
          break;
       }
       cin>>l;
       memset(G, 0, sizeof(G));
       for (int i = 0; i < l; i ++)
       {
          cin>>u>>v;
          G[u][v] = 1;
          G[v][u] = 1;
       }
       memset(paint, -1, sizeof(paint));
       paint[0] = 0;
       if (dfs(0, 1))
       {
          cout<<"BICOLORABLE."<<endl;
       }
       else
       {
          cout<<"NOT BICOLORABLE."<<endl;
       }
    }
    return 0;
}
