#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, Q;
    int s[10000], q[10000];
    int cas = 0;
    while (cin>>N>>Q) {
        if (N == 0 && Q == 0) {
            break;
        }
        for (int i = 1; i <= N; i ++) {
            cin>>s[i];
        }
        for (int i = 1; i <= Q; i ++) {
            cin>>q[i];
        }
        sort(s + 1, s + N + 1);
        cout<<"CASE# "<<++ cas<<":"<<endl;
        for (int i = 1; i <= Q; i ++) {
            bool flag = false;
            for (int j = 1; j <= N; j ++) {
                if (s[j] == q[i]) {
                    flag = true;
                    cout<<q[i]<<" found at "<<j<<endl;
                    break;
                }
            }
            if (flag == false) {
                cout<<q[i]<<" not found"<<endl;
            }
        }
    }
    return 0;
}
