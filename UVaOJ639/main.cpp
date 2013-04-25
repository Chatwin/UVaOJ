#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MAXN 6
using namespace std;
char map[MAXN][MAXN];
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int maxNum, n;
bool vis[MAXN][MAXN];


// 判断那个点是否有冲突
inline bool isConflict(int row, int col){
    for(int i=0; i<4; ++i){
        int dx = row+dir[i][0];
        int dy = col+dir[i][1];
        while(dx>=0 && dx<n && dy>=0 && dy<n){
            if(map[dx][dy]=='X') break;
            if(vis[dx][dy]) return true;
            dx += dir[i][0];
            dy += dir[i][1];
        }
    }
    return false;
}

void dfs(int x, int y, int num){
    for(int i=x; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(!vis[i][j] && map[i][j]=='.' && !isConflict(i, j)){
                vis[i][j] = true;
                dfs(i, j, num+1);
                vis[i][j] = false; // 回溯
            }
        }
    }
    if(num > maxNum) maxNum = num;
}

int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    while(~scanf("%d", &n) && n){
        for(int i=0; i<n; ++i){
            scanf("%s", map[i]);
        }
        maxNum = -2147483645;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0, 0);
        printf("%d\n", maxNum);
    }
    return 0;
}
