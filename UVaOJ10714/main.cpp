/*
 *  UVa: 10714  Ants
 *  Result: Accept
 *  Time: 0.072s
 *  Author: D_Double
 */
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline int max(int a,int b){ return a>b?a:b; }
inline int min(int a,int b){ return a<b?a:b; }

int main(){
    int nCase, len, n, dist;
    scanf("%d",&nCase);
    while(nCase--){
        scanf("%d%d",&len, &n);
        int minLen = -100, maxLen = -100;
        for(int i=0; i<n; ++i){
            scanf("%d",&dist);
            maxLen = max(maxLen, max(dist, len-dist));
            minLen = max(minLen, min(dist, len-dist));
        }
        printf("%d %d\n", minLen, maxLen);
    }
    return 0;
}
