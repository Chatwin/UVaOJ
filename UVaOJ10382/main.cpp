#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 10005;
int n, nIndex;
double l, w;
struct Node {
    double left, right;
    friend bool operator < (const Node &a, const Node &b) {
        return a.left < b.left;
    }
}arr[MAXN];
int main() {
    double p, r;
    while (scanf("%d%lf%lf", &n, &l, &w) != EOF) {
        nIndex = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%lf%lf", &p, &r);
            if (r < w / 2) continue;
            double t = sqrt(r * r - w * w / 4.0);
            arr[nIndex].left = p - t;
            arr[nIndex].right = p + t;
            nIndex ++;
        }
        sort(arr, arr + nIndex);
        int cnt = 0;
        double left = 0, right = 0;
        bool flag = false;
        if (arr[0].left <= 0) {
            int i = 0;
            while (i < nIndex) {
                int j = i;
                while (j < nIndex && left >= arr[j].left) {
                    if (arr[j].right > right) {
                        right = arr[j].right;
                    }
                    j ++;
                }
                if (j == i) break;
                cnt ++;
                i = j;
                left = right;
                if (left >= l) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            printf("%d\n", cnt);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}
