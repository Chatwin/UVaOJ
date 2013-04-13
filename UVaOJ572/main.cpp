#include <iostream>

using namespace std;

char gird[105][105];

int Maxn(int a, int b)
{
   return a > b ? a : b;
}

int Minn(int a, int b)
{
   return a < b ? a : b;
}

bool isSame(char gird[][105], int x, int y, int m, int n)
{
   for (int i = Maxn(x - 1, 0); i <= Minn(x + 1, m - 1); i ++)
   {
      for (int j = Maxn(y - 1, 0); j <= Minn(y + 1, n - 1); j ++)
      {
         if (! (i == x && j == y) && gird[i][j] == '@')
         {
            return false;
         }
      }
   }

   return true;
}

void dfs(char gird[][105], int x, int y, int m, int n)
{
   gird[x][y] = '*';

   if (isSame(gird, x, y, m, n))
   {
      return;
   }
   for (int i = Maxn(x - 1, 0); i <= Minn(x + 1, m - 1); i ++)
   {
      for (int j = Maxn(y - 1, 0); j <= Minn(y + 1, n - 1); j ++)
      {
         if (! (i == x && j == y) && gird[i][j] == '@')
         {
            dfs(gird, i, j, m, n);
         }
      }
   }
}
int main()
{
    int m, n;
    while (cin>>m>>n)
    {
       if (m == 0)
       {
          break;
       }
       for (int i = 0; i < m; i ++)
       {
          for (int j = 0; j < n; j ++)
          {
             gird[i][j] = ' ';
          }
       }
       for (int i =0; i < m; i ++)
       {
          cin>>gird[i];
       }
       int deposit = 0;
       for (int i = 0; i < m; i ++)
       {
          for (int j = 0; j < n; j ++)
          {
             if (gird[i][j] == '@')
             {
                deposit ++;
                dfs(gird, i, j, m, n);
             }
          }
       }
       cout<<deposit<<endl;
    }
    return 0;
}
