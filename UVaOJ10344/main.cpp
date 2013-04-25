#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long a[6], t[6];
bool vis[6], can;

void dfs2(int depth, long nowsum) {
    if (can) return;
    if (depth > 5) {
        if (nowsum == 23) {
            can = true;
        }
        return;
    }
    dfs2(depth + 1, nowsum + t[depth]);
    dfs2(depth + 1, nowsum - t[depth]);
    dfs2(depth + 1, nowsum * t[depth]);
}
void dfs1(int depth) {
    if (can) return;
    if (depth > 5) {
        dfs2(2, t[1]);
        return;
    }
    for (int i = 1; i <= 5; i ++) {
        if (!vis[i]) {
            vis[i] = true;
            t[depth] = a[i];
            dfs1(depth + 1);
            vis[i] = false;
        }
    }
}
int main() {
    while (scanf("%ld%ld%ld%ld%ld", &a[1], &a[2], &a[3], &a[4], &a[5]) == 5) {
        long sum = 0;
        for (int i = 1; i <= 5; i ++) {
            sum += a[i];
        }
        if (sum == 0) {
            break;
        }
        memset(t, 0, sizeof(t));
        memset(vis, false, sizeof(vis));
        can = false;
        dfs1(1);
        if (can) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
