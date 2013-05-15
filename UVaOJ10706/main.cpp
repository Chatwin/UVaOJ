#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 2147483647
using namespace std;
int K;
long long int sum[100000];
char b[1000000];
int pan(int x) {
    int n = 0;
    while(x) {
        x /= 10;
        n ++;
    }
    return n;
}
void init() {
    int i,j,a;
    K = sqrt(MAX) + 1;
    j=1;
    for(i=1; i<=K; i++) {
        sprintf(&b[j],"%d",i);
        while(isdigit(b[j]))
            j++;
    }
    a=sum[0]=0;
    for(i=1;i<=K;i++) {
        a+=pan(i);
        sum[i]=sum[i-1];
        sum[i]+=a;
    }
}
int main() {
    int k,num,t,min,mid,max;
    init();
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&num);
        min=0;
        max=K;
        while(1) {
            mid=(min+max)/2;
            if(mid==min)
                break;
            if(sum[mid]>=num)
                max=mid;
            else
                min=mid;
        }
        k=num-sum[mid];
        printf("%c\n",b[k]);
    }
    return 0;
}
