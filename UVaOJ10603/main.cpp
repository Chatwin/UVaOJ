#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int volume[3], state[3], minVolume, d, d1;
bool flag, vis[205][205][205];

void ssearch(int tot) {
    for (int i = 0; i < 3; i ++) {
        if (state[i] && state[i] == d) {
            d1 = d;
            if (!flag) minVolume = tot;
            else if (tot < minVolume) minVolume = tot;
            flag = true;
        } else if (!flag && state[i] && state[i] < d){
            if (d - state[i] < d1) {
                d1 = d - state[i];
                minVolume = tot;
            } else if (d - state[i] == d1 && tot < minVolume) {
                minVolume = tot;
            }
        }
    }
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {\
            int add;
            int tem_i = state[i], tem_j = state[j];
            if (i != j && state[i] && state[j] != volume[j]) {
                if (state[i] >= volume[j] - state[j]) {
                    add = volume[j] - state[j];
                    state[i] -= add;
                    state[j] = volume[j];
                } else {
                    state[j] += state[i];
                    add = state[i];
                    state[i] = 0;
                }
            }
            if (!vis[state[0]][state[1]][state[2]]) {
                vis[state[0]][state[1]][state[2]] = true;
                ssearch(tot + add);
                vis[state[0]][state[1]][state[2]] = false;
            }
            state[i] = tem_i;
            state[j] = tem_j;
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d%d", &volume[0], &volume[1], &volume[2], &d);
        state[0] = 0;
        state[1] = 0;
        state[2] = volume[2];
        memset(vis, false, sizeof(vis));
        vis[0][0][volume[2]] = true;
        minVolume = d1 = 1000000;
        ssearch(0);
        if (flag) {
            printf("%d %d\n", minVolume, d1);
        } else {
            printf("%d %d\n", minVolume, d - d1);
        }
    }
    return 0;
}
