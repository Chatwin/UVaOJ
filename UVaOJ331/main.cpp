#include <iostream>
#include <cstring>
using namespace std;

int a[5], target[5], num, n, ans;

void dfs(int cur, int p[]) {
    if (cur == num) {
        if (memcmp(p, target, sizeof(target)) == 0) {
            ans ++;
        }
        return;
    }
    int q[5];
    for (int i = 0; i < n - 1; i ++) {
        memcpy(q, p, sizeof(q));
        int k = q[i];
        q[i] = q[i + 1];
        q[i + 1] = k;
        dfs(cur + 1, q);
    }
}
int main()
{
    int t = 0;
    while (1) {
        cin>>n;
        if (n == 0) break;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i ++) {
            cin>>a[i];
        }
        memcpy(target, a, sizeof(a));
        num = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = n - 1; j > i; j --) {
                if (target[j] < target[j - 1]) {
                    int k = target[j];
                    target[j] = target[j - 1];
                    target[j - 1] = k;
                    num ++;
                }
            }
        }
        if (num == 0) {
            cout<<"There are 0 swap maps for input data set "<<++ t<<"."<<endl;
            continue;
        }
        ans = 0;
        dfs(0, a);
        cout<<"There are "<<ans<<" swap maps for input data set "<<++ t<<"."<<endl;
    }
    return 0;
}
