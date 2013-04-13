#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10000;
int G[MAXN][MAXN], in[MAXN], out[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int i = 0; i < MAXN; i ++) {
        if (G[u][i] && ! vis[i]) {
            dfs(i);
        }
    }
}
int main() {
    int T;
    cin>>T;
    while (T --) {
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        char str[1005];
        int N;
        cin>>N;
        for (int i =0; i < N; i ++) {
            cin>>str;
            G[str[0] - 'a'][str[strlen(str) - 1] - 'a'] ++;
            out[str[0] - 'a'] ++;
            in[str[strlen(str) - 1] - 'a'] ++;
        }
        bool flag = true;
        int num1 = 0, num2 = 0;
        for (int i = 0; i < MAXN; i ++) {
            if (! flag) break;
            if (in[i] != out[i]) {
                if (in[i] == out[i] + 1) {
                    num1 ++;
                }
                else if (out[i] == in[i] + 1) {
                    num2 ++;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (num1 && num2 && num1 + num2 > 2) {flag = false;}
        if (flag) {
            memset(vis, false , sizeof(vis));
            for (int i = 0; i < MAXN; i ++) {
                if (out[i]) {
                    dfs(i);
                    break;
                }
            }
            bool flag1 = true;
            for (int i = 0; i < MAXN; i ++) {
                if (in[i] && !vis[i]) {
                    flag1 = false;
                    break;
                }
                if (out[i] && !vis[i]) {
                    flag1 = false;
                    break;
                }
            }
            if (flag1) {
                cout<<"Ordering is possible.\n";
            } else {
                cout<<"The door cannot be opened.\n";
            }
        } else {
            cout<<"The door cannot be opened.\n";
        }
    }
    return 0;
}
