#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 51;
bool cmp(const string a, const string b) {
    return a + b > b + a;
}
int main() {
    int n;
    string str[MAXN];
    while (scanf("%d", &n) != EOF && n) {
        for (int i = 0; i < n; i ++) {
            cin>>str[i];
        }
        sort (str, str + n, cmp);
        for (int i = 0; i < n; i ++) {
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
