#include <iostream>
#include <cstdio>
using namespace std;

long long N, L, R, b[64];
int a[64];
void init_arr() {
    b[0] = 1;
    for (int i = 1; i <= 32; i ++) {
        b[i] = b[i - 1] * 2;
    }
}
void solve() {
    for (int i = 0; i < 32; i ++) {
        a[i] = N % 2;
        N /= 2;
    }
    long long x, y, ans = 0;
    for (int i = 31; i >= 0; i --) {
        if(a[i] == 0) {
            x = ans + b[i];
            y = ans + b[i + 1] - 1;
            if (x <= R && y >= L) {
                ans += b[i];
            }
        } else {
            x = ans;
            y = ans + b[i] - 1;
            if (y < L) {
                ans += b[i];
            }
        }
    }
    printf("%lld\n", ans);
}
int main() {
    init_arr();
    while (scanf("%lld%lld%lld", &N, &L, &R) == 3) {
        solve();
    }
    return 0;
}
