#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[50][100], n;
char b[100];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
   int newx, newy;
   for (int i = 0; i < 4; i ++)
   {
      newx = x + dx[i];
      newy = y + dy[i];
      if (a[newx][newy] == 1)
      {
         a[newx][newy] = 3;
         dfs(newx, newy);
      }
   }
}

int main()
{
    int i, j, k, t;
    gets(b);
    sscanf(b, "%d", &t);
    while (t --)
    {
       memset(a, -1, sizeof(a));
       n = 0;
       while (1)
       {
          gets(b);
          if (b[0] == '_')
          {
             break;
          }
          k = strlen(b);
          for (i = 0; i < k; i ++)
          {
             if (b[i] == 'X')
             {
                a[n][i] = 0;
             }
             else if (b[i] == ' ')
             {
                a[n][i] = 1;
             }
             else if (b[i] == '*')
             {
                a[n][i] = 2;
             }
          }
          n ++;
       }
       for (i = 0; i < n; i ++)
       {
          for (j = 0; a[i][j] != -1; j ++)
          {
             if (a[i][j] == 2)
             {
                a[i][j] = 3;
                dfs(i, j);
             }
          }
       }
       for (i = 0; i < n; i ++)
       {
          for (j = 0; a[i][j] != -1; j ++)
          {
             if (a[i][j] == 0)
             {
                cout<<"X";
             }
             else if (a[i][j] == 1)
             {
                cout<<" ";
             }
             else if (a[i][j] == 3)
             {
                cout<<"#";
             }
          }
          cout<<endl;
       }
       cout<<b<<endl;
    }
    return 0;
}
