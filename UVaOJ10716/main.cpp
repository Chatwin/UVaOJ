#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 8005

using namespace std;

char str[MAXN];
int vis[MAXN];

inline void swap(int &a,int &b){ int t=a; a=b; b=t; }

bool isPossible(){
    memset(vis, 0, sizeof(vis));
    for(int i=0; str[i] ; ++i)
        ++vis[str[i]-'a'];
    int odd=0;
    for(int i=0; i<26; ++i){
        if(vis[i]%2)++odd;
        if(odd>1) return false;
    }
    return true;
}

int solve(){
    int len=strlen(str), cnt=0;
    int left=0, right=len-1;
    while(left<right){
        // 先找到距离两端最短的那个字母
        int minFirst=left, minLast=right, maxDist=MAXN+100;
        memset(vis, 0, sizeof(vis));
        for(int i=left; i<right; ++i)if(!vis[i]){
            vis[i]=true;
            int lastOccur=i,  j;
            for(j=i+1; j<=right; ++j)if(str[j]==str[i]){
                vis[j]=true;
                lastOccur=j;
            }
            if(i-left+right-lastOccur<maxDist){
                minFirst=i, minLast=lastOccur;
                maxDist=i-left+right-lastOccur;
            }
        }
        // 找到之后开始交换移动
        for(int i=minFirst; i>left; --i){
            swap(str[i], str[i-1]);
            ++cnt;
        }
        for(int i=minLast; i<right; ++i){
            swap(str[i], str[i+1]);
            ++cnt;
        }
        // 向内收缩
        ++left;
        --right;
    }
    return cnt;
}
int main(){

    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        if(isPossible()){
            int ans=solve();
            printf("%d\n", ans);
        }
        else
            puts("Impossible");
    }
    return 0;
}

