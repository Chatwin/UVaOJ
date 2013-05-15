#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Point {
    int x, y;
}point[100010];
bool cmp(const Point &a, const Point &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    } else {
        return a.y > b.y;
    }
}
int ans[100010];
int main()
{
    int T, M;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &M);
        int nIndex = 0;
        while (scanf("%d%d", &point[nIndex].x, &point[nIndex].y) != EOF) {
            if (point[nIndex].x == 0 && point[nIndex].y == 0) break;
            if (point[nIndex].y > 0) nIndex ++;
        }
        sort(point, point + nIndex, cmp);
        int cur = 0;
        int N = -1;
        if (point[0].x > 0) {
            printf("0\n");
            if (T) {
                printf("\n");
            }
            continue;
        }
        bool flag = false;
        for (int i = 0; i < nIndex; i ++) {
            if (point[i].x <= cur) {
                if (N == -1) ans[++ N] = i;
                else if (point[i].y > point[ans[N]].y) ans[N] = i;
            } else {
                cur = point[ans[N]].y;
                ans[++ N] = i;
            }
            if (point[ans[N]].y >= M) {
                flag = true;
                break;
            }
        }
        if(flag){
            printf("%d\n", N+1);
            for(int i = 0; i <= N; ++ i)
                printf("%d %d\n", point[ans[i]].x, point[ans[i]].y);
        } else{
            printf("0\n");
        }
        if(T) printf("\n");
    }
    return 0;
}
