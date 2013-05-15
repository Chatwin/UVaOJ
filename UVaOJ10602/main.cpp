/*
 * UVa: 10602 - Editor Nottoobad
 * Result: Accept
 * Time: 0.020s
 * Author: D_Double
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#define MAXN 120
using namespace std;

struct Node{
    int no;
    char word[110];
    friend bool operator < (const Node &a, const Node &b){
        return a.no < b.no;
    }
}arr[MAXN];


int main(){
    int T, N;
    char str[110];
    scanf("%d", &T);
    while(T--){
        scanf("%d",&N);
        for(int i=0; i<N; ++i){
            scanf("%s",arr[i].word);
            arr[i].no = -1;
        }
        arr[0].no = 1;
        int ans=strlen(arr[0].word);
        int rank=1, last=0;

        while(rank < N){
            int t=-1, cnt=0;
            for(int i=0; i<N; ++i)if(arr[i].no==-1){
                if(t==-1){
                    t=i;
                    if(arr[i].word[0]==arr[last].word[0]){
                        for(int j=0; j<strlen(arr[i].word)&&j<strlen(arr[last].word); ++j){
                            if(arr[i].word[j]!=arr[last].word[j]) break;
                            else ++cnt;
                        }
                    }
                }
                else{
                    int tmp=0;
                    for(int j=0; j<strlen(arr[i].word)&&j<strlen(arr[last].word); ++j){
                        if(arr[i].word[j]!=arr[last].word[j]) break;
                        else ++tmp;
                    }
                    if(tmp > cnt){
                        t=i; cnt=tmp;
                    }
                }
            }
            ans += (strlen(arr[t].word) - cnt);
            arr[t].no = rank++;
            last = t;
        }
        sort(arr, arr+N);
        printf("%d\n", ans);
        for(int i=0; i<N; ++i)
            puts(arr[i].word);
    }
    return 0;
}
