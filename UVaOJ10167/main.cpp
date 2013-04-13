#include <iostream>

using namespace std;

typedef struct coordinate
{
   int x, y;
}coordinate;
coordinate cd[102];
int n;

void cut()
{
   for (int i = -500; i <= 500; i ++)
   {
      for (int j = -500; j <= 500; j ++)
      {
         int upon = 0, down = 0;
         if (i == 0 && j == 0) {continue;}
         for (int x = 0; x < 2 * n; x ++)
         {
            if (cd[x].x * i + cd[x].y * j > 0)
            {
               upon ++;
            }
            else if (cd[x].x * i + cd[x].y * j < 0)
            {
               down ++;
            }
            else
            {
               break;
            }
            if (upon == n && down == n)
            {
               cout<<i<<" "<<j<<endl;
               return;
            }
         }
      }
   }
}
int main()
{
    while (cin>>n)
    {
       if (n == 0)
       {
          break;
       }
       for (int i = 0; i < 2 * n; i ++)
       {
          cin>>cd[i].x>>cd[i].y;
       }
       cut();
    }

    return 0;
}
