#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T, n, h;
    int a[20];
    cin>>T;
    cin.ignore();
    while (T --) {
//        cin.ignore();
        cin>>n>>h;
        for (int i = 0; i < n; i ++) {
            if (i < n - h) {
                a[i] = 0;
            } else {
                a[i] = 1;
            }
        }
        do {
            for (int i = 0; i < n; i ++) {
                cout<<a[i];
            }
            cout<<endl;
        } while(next_permutation(a, a + n));
        if (T > 0) {
            cout<<endl;
        }
    }
    return 0;
}
