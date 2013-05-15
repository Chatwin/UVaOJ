#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define N 10000
char a[N];
int main() {
    //freopen("abc.txt","r",stdin);
    int n;

    while(gets(a)!=NULL) {
        n=strlen(a);
        int found,count=0;

        for(int i=0; i<n; i++) {
            if(isalpha(a[i])) found=1;
            else {
                if(found) count++;

                found =0;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
