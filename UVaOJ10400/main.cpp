#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int ADD = 32000;
int arr[120], p, target;
char route[120];
bool flag, vis[102][32002 * 2 + 2];
inline bool isOk(int m, int cur) {
    return (m >= -32000 && m <= 32000 && !vis[cur][m + ADD]);
}
void dfs(int cur, int sum) {
    if (flag) return;
    if (cur == p) {
        if (sum == target) flag = true;
        return;
    }
    if (flag) return;
    for (int i = 0; i < 4; i ++) {
        if (i == 0 && isOk(sum + arr[cur], cur)) {
            vis[cur][sum + arr[cur] + ADD] = true;
            route[cur - 1] = '+';
            dfs(cur + 1, sum + arr[cur]);
        } else if (i == 1 && isOk(sum - arr[cur], cur)){
            vis[cur][sum - arr[cur] + ADD] = true;
            route[cur - 1] = '-';
            dfs(cur + 1, sum - arr[cur]);
        } else if (i == 2 && isOk(sum * arr[cur], cur)){
            vis[cur][sum * arr[cur] + ADD] = true;
            route[cur - 1] = '*';
            dfs(cur + 1, sum * arr[cur]);
        } else if (i == 3 && arr[cur] != 0 && isOk(sum / arr[cur], cur)){
            vis[cur][sum / arr[cur] + ADD] = true;
            route[cur - 1] = '/';
            dfs(cur + 1, sum / arr[cur]);
        }
        if (flag) return;
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &p);
        for (int i = 0; i < p; i ++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &target);
        memset(vis, false, sizeof(vis));
        vis[0][arr[0] + ADD] = true;
        flag = false;
        dfs(1, arr[0]);
        if (flag) {
            printf("%d", arr[0]);
            for (int i = 1; i < p; i ++) {
                printf("%c%d", route[i - 1], arr[i]);
            }
            printf("=%d\n", target);
        } else {
            printf("NO EXPRESSION\n");
        }
    }
    return 0;
}
