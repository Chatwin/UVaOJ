#include <iostream>
#include <cstring>
#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXC = 200;

char str[MAXC];
deque<int> que;
vector<char> var;
int val[26];

void Filter()
{
   int pos = 0;
   for (unsigned int i = 0; i < strlen(str); i ++)
   {
      if (str[i] != ' ')
      {
         str[pos ++] = str[i];
      }
   }
   str[pos] = 0;
}

inline bool havePreFix(int i)
{
   if ((str[i - 1] == '+' && str[i - 2] == '+') || (str[i - 1] == '-' && str[i - 2] == '-'))
   {
      return true;
   }
   else
   {
      return false;
   }
}
inline bool haveLastFix(int i)
{
   if ((str[i + 1] == '+' && str[i + 2] == '+') || (str[i + 1] == '-' && str[i + 2] == '-'))
   {
      return true;
   }
   else
   {
      return false;
   }
}
void PreProsess()
{
   while (! que.empty())
   {
      que.pop_back();
   }
   var.clear();
   for (unsigned int i = 0; i < strlen(str); i ++)
   {
      if (str[i] >= 'a' && str[i] <= 'z')
      {
         var.push_back(str[i]);
         if (i >= 2 && havePreFix(i))
         {
            if(str[i - 1] == '+')
            {
               ++ val[str[i] - 'a'];
            }
            else
            {
               -- val[str[i] - 'a'];
            }
            int n = val[str[i] - 'a'];
            que.push_back(n);
            str[i - 1] = str[i - 2] = ' ';
         }
         else if (i <= strlen(str) - 3 && haveLastFix(i))
         {
            int n = val[str[i] - 'a'];
            que.push_back(n);
            if (str[i + 1] == '+')
            {
               val[str[i] - 'a'] ++;
            }
            else
            {
               val[str[i] - 'a'] --;
            }
            str[i + 1] = str[i + 2] = ' ';
         }
         else
         {
            int n = val[str[i] - 'a'];
            que.push_back(n);
         }
      }
   }
}
int GetSum()
{
   for (unsigned int i = 0; i < strlen(str); i ++)
   {
      if (str[i] == '+' || str[i] == '-')
      {
         int a = que.front();
         que.pop_front();
         int b = que.front();
         que.pop_front();
         if (str[i] == '+')
         {
            que.push_front(a + b);
         }
         else
         {
            que.push_front(a - b);
         }
      }
   }
   return que.front();
}
void solve()
{
   for (int i =0; i < 26; i ++)
   {
      val[i] = i + 1;
   }
   Filter();
   PreProsess();
   int sum = GetSum();
   cout<<"    value = "<<sum<<endl;
   sort(var.begin(), var.begin() + var.size());
   for (unsigned int i = 0; i < var.size(); i ++)
   {
      cout<<"    "<<var[i]<<" = "<<val[var[i] - 'a']<<endl;
   }
}
int main()
{
    while (gets(str))
    {
       cout<<"Expression: "<<str<<endl;
       solve();
    }
    return 0;
}
