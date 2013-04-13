#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define Maxn 65
int n, sum, goal;
int sticks[Maxn];
bool visit[Maxn];

bool cmp (const int &a, const int &b)
{
   return a > b;
}

bool dfs(int now, int index, int cnt)
{
   if (goal * cnt == sum)  {return true;}
   for (int i = index; i < n; i ++)
   {
      if (visit[i] || (i && !visit[i - 1] && sticks[i] == sticks[i - 1]))
      {
         continue;
      }
      if (now + sticks[i] == goal)
      {
         visit[i] = true;
         if (dfs(0, 0, cnt + 1))   {return true;}
         visit[i] = false;
         return false;
      }
      else if (now + sticks[i] < goal)
      {
         visit[i] = true;
         if (dfs(now + sticks[i], i + 1, cnt)) {return true;}
         visit[i] = false;
         if (now == 0)
         {
            return false;
         }
      }
   }
   return false;
}
int solve()
{
   sort(sticks, sticks + n, cmp);
   for (goal = sticks[0]; goal < sum; goal ++)
   {
      if (sum % goal != 0) continue;
      memset(visit, false, sizeof(visit));
      if (dfs(0, 0, 0))
      {
         break;
      }
   }
   return goal;
}
int main()
{
    while (cin>>n)
    {
       if (n == 0) break;
       sum = 0;
       for (int i = 0; i < n; i ++)
       {
          cin>>sticks[i];
          sum += sticks[i];
       }
       cout<<solve()<<endl;
    }
    return 0;
}
