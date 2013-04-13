#include <iostream>
#include <cstring>
using namespace std;

#define MAXD 160
#define MID 80
int first, f[MAXD];

void dfs(int cur)
{
   int k;
   cin>>k;
   if (k == -1)
   {
      return;
   }
   else if (f[cur] == -1)
   {
      f[cur] = k;
   }
   else
   {
      f[cur] += k;
   }
   dfs(cur - 1);
   dfs(cur + 1);
}

void solve()
{
   int i;
   memset(f, -1, sizeof(f));
   f[MID] = first;
   dfs(MID - 1);
   dfs(MID + 1);
   for (i = 0; f[i] == -1; i ++);
   cout<<f[i ++];
   for (; f[i] != -1; i ++)
   {
      cout<<" "<<f[i];
   }
   cout<<endl;
}
int main()
{
    int t = 0;
    while (1)
    {
       cin>>first;
       if (first == -1) {break;}
       cout<<"Case "<<++ t<<":"<<endl;
       solve();
       cout<<endl;
    }
    return 0;
}
