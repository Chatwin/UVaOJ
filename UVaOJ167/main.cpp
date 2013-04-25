#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int r[8][8], d[8], ans;
bool vis[3][20];
void dfs(int depth) {
    if (depth >= 8) {
        int t = 0;
        for (int i = 0; i < 8; i ++) {
            t += r[i][d[i]];
        }
        ans = max(ans, t);
        return;
    } else {
        for (int i = 0; i < 8; i ++) {
            if (!vis[0][i] && !vis[1][depth + i] && !vis[2][depth - i + 8 - 1]) {
                d[depth] = i;
                vis[0][i] = vis[1][depth + i] = vis[2][depth - i + 8 - 1] = true;
                dfs(depth + 1);
                vis[0][i] = vis[1][depth + i] = vis[2][depth - i + 8 - 1] = false;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T --) {
        for (int i = 0; i < 8; i ++) {
            for (int j = 0; j < 8; j ++) {
                cin>>r[i][j];
            }
        }
        ans = 0;
        memset(d, 0, sizeof(d));
        memset(vis, false, sizeof(vis));
        dfs(0);
        printf("%5d\n", ans);
    }
    return 0;
}
