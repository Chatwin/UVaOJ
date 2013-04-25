#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 100;
int arr[MAXN], ans[MAXN];
double x[MAXN], y[MAXN];
double dis (double x1, double y1, double x2, double y2) {
    return pow((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), 0.5);
}
//暴力枚举
/*
int main() {
    int n, cas = 0;
    while (cin>>n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i ++) {
            cin>>x[i]>>y[i];
            arr[i] = i;
        }
        double min = 2147483645;
        do {
            double sum = 0;
            bool flag = false;
            for (int i = 1; i < n; i ++) {
                double t = dis(x[arr[i]], y[arr[i]], x[arr[i - 1]], y[arr[i - 1]]);
                sum += t;
                if (sum > min) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            if (sum < min) {
                min = sum;
                memcpy(ans, arr, sizeof(arr));
            }
        }while (next_permutation(arr, arr + n));
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<++ cas<<endl;
        for (int i = 0; i < n - 1; i ++) {
            cout<<"Cable requirement to connect ("<<(int)x[ans[i]]<<","<<(int)y[ans[i]]<<") to ("<<
                (int)x[ans[i + 1]]<<","<<(int)y[ans[i + 1]]<<") is "<<setiosflags(ios::fixed)<<setprecision(2)
                <<dis(x[ans[i + 1]], y[ans[i + 1]], x[ans[i]], y[ans[i]]) + 16<<" feet."<<endl;
        }
        cout<<"Number of feet of cable required is "<<setiosflags(ios::fixed)<<setprecision(2)<<min + (n - 1) * 16<<"."<<endl;
    }
    return 0;
}
*/

//回溯法
double minSum ;
bool vis[MAXN];
void dfs(int n, int cur, double sum) {
    if (cur == n) {
        if (sum < minSum) {
            minSum = sum;
            memcpy(ans, arr, sizeof(arr));
        }
        return;
    }
    if (sum >= minSum) {
        return;
    }
    for (int i = 0; i < n; i ++) {
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        arr[cur] = i;
        if (cur == 0) {
            dfs(n, cur + 1, 0);
        } else {
            double t = dis(x[arr[cur]], y[arr[cur]], x[arr[cur - 1]], y[arr[cur - 1]]);
            dfs(n, cur + 1, sum + t + 16);
        }
        vis[i] = false;
    }
}
int main() {
    int n, cas = 0;
    while (cin>>n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i ++) {
            cin>>x[i]>>y[i];
            arr[i] = i;
        }
        minSum = 2147483645;
        memset(vis, false, sizeof(vis));
        dfs(n, 0, 0);
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<++ cas<<endl;
        for (int i = 0; i < n - 1; i ++) {
            cout<<"Cable requirement to connect ("<<(int)x[ans[i]]<<","<<(int)y[ans[i]]<<") to ("<<
                (int)x[ans[i + 1]]<<","<<(int)y[ans[i + 1]]<<") is "<<setiosflags(ios::fixed)<<setprecision(2)
                <<dis(x[ans[i + 1]], y[ans[i + 1]], x[ans[i]], y[ans[i]]) + 16<<" feet."<<endl;
        }
        cout<<"Number of feet of cable required is "<<setiosflags(ios::fixed)<<setprecision(2)<<minSum<<"."<<endl;
    }
}
