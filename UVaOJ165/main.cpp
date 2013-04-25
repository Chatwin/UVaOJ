#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200;
int h, k;
int ans[MAXN], maxStampVal, stampVal[MAXN], maxVal[MAXN];
bool occur[MAXN];
void dfs(int cur, int n, int sum) {
    if (cur >= h) {
        occur[sum] = true;
        return;
    }
    occur[sum] = true;
    for (int i = 0; i <= n; i ++) {
        dfs(cur + 1, n, sum + stampVal[i]);
    }
}
void dsearch(int cur) {
    if (cur >= k) {
        if (maxVal[cur - 1] > maxStampVal) {
            maxStampVal = maxVal[cur - 1];
            memcpy(ans, stampVal, sizeof(stampVal));
        }
        return;
    }
    for (int i = stampVal[cur - 1] + 1; i <= maxVal[cur - 1] + 1; i ++) {
        memset(occur, false, sizeof(occur));
        stampVal[cur] = i;
        dfs(0, cur, 0);
        int num = 0, j = 1;
        while (occur[j ++]) num ++;
        maxVal[cur] = num;
        dsearch(cur + 1);
    }
}
int main(){
    while (scanf("%d%d", &h, &k) != EOF) {
        if (h + k == 0) break;
        stampVal[0] = 1;
        maxVal[0] = h;
        maxStampVal = -1;
        dsearch(1);
        for (int i = 0; i < k; i ++) {
            printf("%3d", ans[i]);
        }
        printf(" ->%3d\n", maxStampVal);
    }
    return 0;
}
