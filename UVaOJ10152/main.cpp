#include <iostream>
#include <string>
using namespace std;
int k, n;
string OriginalString[210];
string DesireString[210];

int main()
{
    cin>>k;
    while(k --)
    {
       cin>>n;
       cin.ignore();
       for (int i = 0; i < n; i ++)
       {
          getline(cin, OriginalString[i]);
       }
       for (int i = 0; i < n; i ++)
       {
          getline(cin, DesireString[i]);
       }
       int i, j;
       for (i = j = n - 1; i >= 0; i --)
       {
          if (OriginalString[i] == DesireString[j])
          {
             j --;
          }
       }
       for (; j >= 0; j --)
       {
          cout<<DesireString[j]<<endl;
       }
       cout<<endl;
    }
    return 0;
}
