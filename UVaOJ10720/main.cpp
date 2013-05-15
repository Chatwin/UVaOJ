#include<iostream>
#include<algorithm>
#include<cstdio>
#define MAXN 10005
using namespace std;

int arr[MAXN],n;

bool Havel_Hakimi(){
    for(int i=0; i<n-1; ++i){
        sort(arr+i,arr+n,greater<int>());
        if(i+arr[i] >= n) return false;
        for(int j=i+1; j<=i+arr[i]; ++j){
            --arr[j];
            if(arr[j] < 0) return false;
        }
    }
    if(arr[n-1]!=0) return false;
    return true;
}

int main(){
    while(scanf("%d",&n)&&n){
        int sum=0;
        bool flag=true;
        for(int i=0; i<n; ++i){
            scanf("%d",&arr[i]);
            if(arr[i]>n-1) flag=false;
            sum += arr[i];
        }
        if(sum%2!=0) flag=false;
        if(sum==0 || flag&&Havel_Hakimi()) printf("Possible\n");
        else printf("Not possible\n");
    }
    return 0;
}
