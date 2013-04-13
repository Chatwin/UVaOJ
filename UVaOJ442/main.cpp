#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <stack>
using namespace std;

typedef struct
{
   int r, c;
}Matrix;
Matrix m[26];
void slove (string st)
{
   stack<char> sc;
   stack<Matrix> sm;
   stringstream ss(st);
   char ch;
   Matrix a, b, c;
   int sum = 0;
   while (ss>>ch)
   {
      if (ch == ')')
      {
         a = sm.top();
         sm.pop();
         b = sm.top();
         sm.pop();
         if (b.c != a.r)
         {
            cout<<"error"<<endl;
            return;
         }
         sum += b.r * b.c * a.c;
         c.r = b.r;
         c.c = a.c;
         sm.push(c);
         sc.pop();
      }
      else if (ch == '(')
      {
         sc.push(ch);
      }
      else
      {
         a = m[ch - 'A'];
         sm.push(a);
      }
   }
   cout<<sum<<endl;
}
int main()
{
    int n;
    char c;
    cin>>n;
    for (int i = 0; i < n; i ++)
    {
       cin>>c;
       cin>>m[c - 'A'].r>>m[c - 'A'].c;
    }
    string st;
    getline(cin, st);
    while (getline(cin, st))
    {
       slove(st);
    }
    return 0;
}
