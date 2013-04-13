#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 60
struct node
{
   int x, y;
};
queue<struct node> q;
char s[N][N];
int vis[N][N];
int w, h;
int dx[5] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, -1, 1};
int ccount;

void input()
{
   memset(s, 0, sizeof(s));
   memset(vis, 0, sizeof(vis));

   for (int i =1; i <= h; i ++)
   {
      gets(s[i] + 1);
   }
   for (int i = 0; i <= h + 1; i ++)
   {
      vis[i][0] = vis[i][w + 1] = 1;
   }
   for (int i = 0; i <= w + 1; i ++)
   {
      vis[0][i] = vis[h + 1][i] = 1;
   }
}

void BFS(int i, int j)
{
   int xx, yy;
   struct node tmp, ttmp;
   while (! q.empty())
   {
      q.pop();
   }
   s[i][j] = '*';
   tmp.x = i;
   tmp.y = j;
   q.push(tmp);
   while (! q.empty())
   {
      tmp = q.front();
      q.pop();
      for (int k = 1; k <= 4; k ++)
      {
         xx = tmp.x + dx[k];
         yy = tmp.y + dy[k];
         if (! vis[xx][yy] && s[xx][yy] == 'X')
         {
            s[xx][yy] = '*';
            ttmp.x = xx;
            ttmp.y = yy;
            q.push(ttmp);
         }
      }
   }

   return;
}

void DFS(int i, int j)
{
   int xx, yy;

   if (s[i][j] == 'X')
   {
      ccount ++;
      BFS(i, j);
   }
   vis[i][j] = 1;
   for (int k = 1; k <= 4; k ++)
   {
      xx = i + dx[k];
      yy = j + dy[k];
      if (!vis[xx][yy] && (s[xx][yy] == '*' || s[xx][yy] == 'X'))
      {
         DFS(xx, yy);
      }
   }

   return;
}

int main()
{
    int T = 0, c, num[N * N];
    while (cin>>w>>h)
    {
       getchar();
       T ++;
       if (w == 0 && h == 0)
       {
          break;
       }
       input();
       c = 0;
       for (int i = 1; i <= h; i ++)
       {
          for (int j = 1; j <= w; j ++)
          {
             if (((vis[i][j] && s[i][j] == 'X') || s[i][j] == '*'))
             {
                ccount = 0;
                DFS(i, j);
                if (ccount > 0 && ccount <= 6)
                {
                   num[c ++] = ccount;
                }
             }
          }
       }
       sort(num, num + c);
       cout<<"Throw "<<T<<endl;
       cout<<num[0];
       for (int i = 1; i < c; i ++)
       {
          cout<<" "<<num[i];
       }
       cout<<endl<<endl;
    }
    return 0;
}
