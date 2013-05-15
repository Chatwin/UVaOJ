#include <iostream>
#include <cstdio>
using namespace std;

int init[10005], tar[10005];
void ST(int l, int h) {
    int t = l;
    if (l == h) return;
    for (int i = l; i <= h; i +=2) {
        tar[t ++] = init[i];
    }
    for (int i = l + 1; i <= h; i += 2) {
        tar[t ++] = init[i];
    }
    for (int i = l; i <= h; i ++) {
        init[i] = tar[i];
    }
    ST(l, (l + h) / 2);
    ST((l + h) / 2 + 1, h);
}
int main()
{
    int T;
    while (scanf("%d", &T) != EOF && T) {
        for (int i = 0; i < T; i ++) {
            init[i] = i;
        }
        ST(0, T - 1);
        printf("%d: %d", T, tar[0]);
        for (int i = 1; i < T; i ++) {
            printf(" %d", tar[i]);
        }
        printf("\n");
    }
    return 0;
}
