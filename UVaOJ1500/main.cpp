#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int dp[55][55000];
int a[55];
int DP(int a,int b) {
    if(dp[a][b]!=-1) return dp[a][b];
    if(b==1) return dp[a][b]=DP(a+1,0);//只剩一个单独的一，加入其它1中
    dp[a][b]=0;
    if(a>=1&&!DP(a-1,b))//直接去掉一个1
        dp[a][b]=1;
    if(a>=1&&b&&!DP(a-1,b+1))//将一个1合到其它数中
        dp[a][b]=1;
    if(a>=2&&((b&&!DP(a-2,b+3))||(b==0&&!DP(a-2,2))))//将2个1并起来
        dp[a][b]=1;
    if(b>=2&&!DP(a,b-1))//减小一
        dp[a][b]=1;
    return dp[a][b];
}
int main() {
    memset(dp,-1,sizeof(dp));
    int t,test=1,n,i,j,k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(j=0,k=0,i=0; i<n; i++) {
            scanf("%d",&a[i]);

            if(a[i]==1) j++;
            else k+=a[i]+1;
        }
        if(k) k--;
        DP(j,k);
        printf("Case #%d: ",test++);
        if(dp[j][k]) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}
