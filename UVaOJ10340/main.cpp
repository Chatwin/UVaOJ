#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1000010;
int main() {
    char s[MAXN], t[MAXN];
    int i, j;
    while (scanf("%s%s", s, t) != EOF) {
        for (i = 0, j = 0; t[i] != '\0' && s[j] != '\0'; i ++) {
            if (t[i] == s[j]) j ++;
        }
        if (s[j] == '\0') {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
