#include <iostream>
#include<cstdio>
#include<cstring>
#include<cctype>

using namespace std;

char b[1000];
double stack[10000];
int main() {
    int i,k,t,head,top;
    double d,min,max,temp;
    char flag;
    scanf("%d",&t);
    while(t--) {
        scanf("%s",b);
        k=strlen(b);
        head=top=0;
        min=0.0;
        b[k]='+';
        for(i=0;i<=k;i++)
            if(!isdigit(b[i])) {
                flag=b[i];
                b[i]='\0';
                sscanf(&b[head],"%lf",&d);
                b[i]=flag;
                stack[top++]=d;
                if(flag=='+') {
                    temp=1.0;
                    while(top) {
                        top--;
                        temp*=stack[top];
                    }
                    min+=temp;
                }
                head=i+1;
            }
        temp=0.0;
        head=0;
        max=1.0;
        b[k]='*';
        for(i=0;i<=k;i++)
            if(!isdigit(b[i])) {
                flag=b[i];
                b[i]='\0';
                sscanf(&b[head],"%lf",&d);
                temp+=d;
                if(flag=='*') {
                    max*=temp;
                    temp=0.0;
                }
                head=i+1;
            }
        printf("The maximum and minimum are %.0f and %.0f.\n",max,min);
    }
    return 0;
}
