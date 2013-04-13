#include <iostream>
#include <cstring>
using namespace std;

int G[210][210], vis[201];

void dfs(int i, int n) {
    vis[i] = 1;
    for (int j = 0; j < n; j ++) {
        if (! vis[j] && G[i][j]) {
            dfs(j, n);
        }
    }
}
int main() {
    int n, r;
    while (cin>>n>>r) {
        memset(G, 0, sizeof(G));
        memset(vis, 0, sizeof(vis));
        int u, v;
        for (int i = 0; i < r; i ++) {
            cin>>u>>v;
            G[u][v] = G[v][u] = 1;
            vis[u] ++;
            vis[v] ++;
        }
        int count = 0;
        for (int i = 0; i < n ; i ++) {
            if (vis[i] % 2 == 1) {
                count ++;
                break;
            }
        }
        memset(vis, 0, sizeof(vis));
        if (count || r < 2) {
            cout<<"Not Possible"<<endl;
            continue;
        } else {
            dfs(0, n);
            bool flag = true;
            for (int i = 0; i < n; i ++) {
                if (vis[i] == 0) {
                    flag = false;
                }
            }
            if (flag == true) {
                cout<<"Possible"<<endl;
            } else {
                cout<<"Not Possible"<<endl;
            }
        }
    }

    return 0;
}
