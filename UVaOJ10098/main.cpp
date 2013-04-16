#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
int main()
{
    int n;
    char p[11];
    cin>>n;
    while (n --) {
        cin>>p;
        sort(p, p + strlen(p));
        do {
            for (int i = 0; i < (int)strlen(p); i ++) {
                cout<<p[i];
            }
            cout<<endl;
        } while (next_permutation(p, p + strlen(p)));
        cout<<endl;
    }
    return 0;
}
*/
void print_permutation(int n, char P[], char A[], int cur)  {
    int i, j;
    if (cur == n) {
        for (int i = 0; i < n; i ++) {
            cout<<A[i];
        }
        cout<<endl;
    } else {
        for (i = 0; i < n; i ++) {
            if (! i || P[i] != P[i - 1]){
                int c1 = 0, c2 = 0;
                for (j = 0; j < cur; j ++) {
                    if (A[j] == P[i]) {
                        c1 ++;
                    }
                }
                for (j = 0; j < n; j ++) {
                    if (P[i] == P[j]) {
                        c2 ++;
                    }
                }
                if (c1 < c2) {
                    A[cur] = P[i];
                    print_permutation(n, P, A, cur + 1);
                }
            }
        }
    }
}
int main() {
    int n, cur;
    char P[11];
    char A[11];
    cin>>n;
    while (n --) {
        cin>>P;
        cur = 0;
        sort(P, P + strlen(P));
        print_permutation(strlen(P), P,  A, cur);
        cout<<endl;
    }
    return 0;
}
