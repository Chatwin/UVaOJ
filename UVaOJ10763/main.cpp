#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 500005;
int arr[MAXN];
void init_arr() {
    for (int i = 0; i < MAXN; i ++) {
        arr[i] = i;
    }
}
void swap_arr (int a, int b) {
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}
bool isOk() {
    for (int i = 0; i < MAXN; i ++) {
        if (arr[i] != i) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF) {
        getchar();
        if (n == 0) break;
        init_arr();
        for (int i = 0; i < n; i ++) {
            scanf("%d%d", &a, &b);
            swap_arr(a, b);
        }
        if (isOk()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
