#include <iostream>

using namespace std;
int CycleLength(int x){
   int num = 1;
   while(x != 1) {
      if(x % 2 != 0) {
         x = 3*x+1;
      } else {
         x /= 2;
      }
      num ++;
   }
   return num;
}

int main() {
    int x, y;
    while((cin>>x>>y)){
      int max = 0;
      int j = x < y? x : y;
      int k = x > y? x : y;
      for (int i = j; i <= k; i ++){
         int n = CycleLength(i);
         if (max < n){
            max = n;
         }
      }
      cout<<x<<' '<<y<<' '<<max<<endl;
    }
    return 0;
}
