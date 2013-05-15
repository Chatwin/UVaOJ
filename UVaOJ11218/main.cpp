#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int group[82][4], ans, n;
bool occur[10], vis[82];
void ssearch(int cur, int tot) {
    if (cur >= 3) {
        if (tot > ans) {
            ans = tot;
            return;
        }
    }
    for (int i = 0; i < n; i ++) {
        if (! vis[i]) {
            if (occur[group[i][0]] || occur[group[i][1]] || occur[group[i][2]])
                continue;
            occur[group[i][0]] = occur[group[i][1]] = occur[group[i][2]] = true;
            vis[i] = true;
            ssearch(cur + 1, tot + group[i][3]);
            occur[group[i][0]] = occur[group[i][1]] = occur[group[i][2]] = false;
            vis[i] = false;
        }
    }
}
int main() {
    int cas = 1;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        for (int i = 0; i < n; i ++) {
            scanf("%d%d%d%d", &group[i][0], &group[i][1], &group[i][2], &group[i][3]);
        }
        ans = -1;
        memset(occur, false, sizeof(occur));
        memset(vis, false, sizeof(vis));
        ssearch(0, 0);
        printf("Case %d: %d\n", cas ++, ans);
    }
    return 0;
}
