#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int arr[1010];
vector<int> vt;
vector<int> vt2;
int main() {
    int n, m, q, cas = 1;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        vt.clear();
        for (int i = 0; i < n; i ++) {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n ; j ++) {
                vt.push_back(arr[i] + arr[j]);
            }
        }
        sort(vt.begin(), vt.end());
        vt2.clear();
        vt2.push_back(vt[0]);
        for (int i = 1; i < vt.size(); i ++) {
            if (vt[i] != vt[i - 1]) {
                vt2.push_back(vt[i]);
            }
        }
        printf("Case %d:\n", cas ++);
        scanf("%d", &m);
        for (int i = 0; i < m; i ++) {
            scanf("%d", &q);
            vector<int>::iterator it;
            it = lower_bound(vt2.begin(), vt2.end(), q);
            if (*it == q) {
                printf("Closest sum to %d is %d.\n", q, q);
            } else {
                int min = *it;
                if (it != vt2.begin() && abs(*(it - 1) - q) < abs(min - q)) {
                    min = *(it - 1);
                }
                printf("Closest sum to %d is %d.\n", q, min);
            }
        }
    }
    return 0;
}
