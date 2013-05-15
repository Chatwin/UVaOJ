#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 705;
struct Point {
    int x, y;
}point[MAXN];
int nIndex;
char str[10000];
void init_input() {
    nIndex = 0;
    while (gets(str)) {
        if (! str[0]) break;
        sscanf(str, "%d%d", &point[nIndex].x, &point[nIndex].y);
        nIndex ++;
    }
}
inline bool is_lined(const int x1, const int y1, const int x2, const int y2, const int x3, const int y3) {
    return (x2 - x1) * (y3 - y2) - (x3 - x2) * (y2 - y1) == 0;
}
void solve() {
    int maxNum = 2;
    for (int i = 0; i < nIndex; i ++) {
        for (int j = i + 1; j < nIndex; j ++) {
            int cnt = 2;
            for (int k = j + 1; k < nIndex; k ++) {
                if (is_lined(point[i].x, point[i].y, point[j].x, point[j].y, point[k].x, point[k].y)) {
                    cnt ++;
                }
            }
            if (cnt > maxNum) {
                maxNum = cnt;
            }
        }
    }
    printf("%d\n", maxNum);
}
int main() {
    int T;
    scanf("%d%*c", &T);
    gets(str);
    while (T --) {
        init_input();
        if (nIndex == 1) {
            printf("1\n");
        } else if (nIndex == 2){
            printf("2\n");
        } else {
            solve();
        }
        if (T) {
            printf("\n");
        }
    }
    return 0;
}
