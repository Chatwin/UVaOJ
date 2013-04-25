#include <iostream>
#include <cstring>
using namespace std;

int v[26][26], vis[26][26], tot;
struct Point {
    int x, y;
}po[26];
void dfs(int n, int x, int y, int cur) {
    int flag = 0;
    vis[x][y] = vis[y][x] = 1;
    for (int i = 0; i < n; i ++) {
        if (v[y][i] && !vis[y][i]) {
            flag = 1;
            dfs(n, y, i, cur + 1);
        }
    }
    vis[x][y] = vis[y][x] = 0;
    if (! flag) {
        if (cur + 1 > tot) {
            tot = cur + 1;
        }
    }
}
int main()
{
    int n, m;
    while (cin>>n>>m) {
        if (n == 0 && m == 0) {
            break;
        }
        tot = 0;
        memset(v, 0, sizeof(v));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i ++) {
            cin>>po[i].x>>po[i].y;
            v[po[i].x][po[i].y] = 1;
            v[po[i].y][po[i].x] = 1;
        }
        for (int i = 0; i < m; i ++) {
            dfs(n, po[i].x, po[i].y, 0);
            dfs(n, po[i].y, po[i].x, 0);
        }
        cout<<tot<<endl;
    }
    return 0;
}
