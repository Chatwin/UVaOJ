#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[1000002];
long long solve(long long x)
{
    return ((x-1)*(x-2)/2-(x-1)+x/2)/2;
}
int main()
{
    int n;
    f[1]=0;f[2]=0;
    for(int i=3;i<=1000000;i++)
        f[i]=f[i-1]+solve(i);
    while(scanf("%d",&n),n>=3)
    {
        printf("%ld\n",f[n]);
    }
    return 0;
}
