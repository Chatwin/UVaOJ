#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAXN 102
using namespace std;
int M,N,L;
struct Node{
    char name[20];
    int A, B;
    int cost;
    friend bool operator < (const Node&a, const Node&b){
        if(a.cost!=b.cost)
            return a.cost < b.cost;
        return strcmp(a.name,b.name) < 0;
    }
}arr[MAXN];

inline void input(){
    char str[200];
    scanf("%d%d%d",&N,&M,&L);
    for(int i=0; i<L; ++i){
        scanf("%s",str);
        int j;
        for(j=0; str[j]!=':'; ++j)
            arr[i].name[j]=str[j];
        arr[i].name[j]='\0';
        sscanf(str+j+1, "%d,%d",&arr[i].A,&arr[i].B);
        arr[i].cost=0;
    }
}

inline void greedy(){
    for(int i=0; i<L; ++i){
        int left=N;
        int A=arr[i].A, B=arr[i].B;
        int half=(left+1)/2;
        while(left-half>=M && B<=half*A){
            arr[i].cost += B;
            left -= half;
            half=(left+1)/2;
        }
        if(left>M)arr[i].cost += (left-M)*A;
    }
}
int main(){
    int T, cas=1;
    scanf("%d",&T);
    while(T--){
        input();
        greedy();
        sort(arr, arr+L);
        printf("Case %d\n",cas++);
        for(int i=0; i<L; ++i){
             printf("%s %d\n",arr[i].name, arr[i].cost);
        }
    }
    return 0;
}
