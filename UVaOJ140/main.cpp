#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MAXN 50
using namespace std;
int edge[MAXN], order[MAXN], minOrder[MAXN];
int G[MAXN][MAXN],loc[MAXN], minVal, cnt;
char str[20000];
bool vis[50], occur[30];

void read_in(){

    memset(occur, 0, sizeof(occur));
    memset(G, 0, sizeof(G));

    int len = strlen(str);
    str[len] = ';';
    str[len+1] = '\0';

    int i=0;

    while(i<(int)strlen(str)){
        int u = str[i] - 'A';
        occur[u] = true;
        ++i; ++i;
        while(str[i]!=';'){
            int v = str[i]-'A';
            occur[v] = true;
            ++G[u][v];
            ++i;
        }
        ++i;
    }
    cnt = 0;
    for(int i=0; i<28; ++i) if(occur[i]){
        edge[cnt++] = i;
    }
}

int counter(){
  	int totalMax = -999;
    for(int i=0; i<cnt; ++i){
        int maxVal = -999;
        for(int j=0; j<cnt; ++j)if(G[edge[order[i]]][edge[j]]){
           int pos = loc[edge[j]];
            if(abs(pos-i) > maxVal) maxVal=abs(pos-i);
        }
        if(maxVal > totalMax) totalMax = maxVal;
    }
    return totalMax;
}

void search(int cur){
    if(minVal==1) return;
    for(int i=0; i<cnt; ++i)if(!vis[i]){
        vis[i] = true;
        order[cur] = i;
        loc[edge[i]] = cur;
        search(cur+1);
        vis[i] = false;
    }
    if(cur==cnt){
        int totalMax = counter();

        if(totalMax < minVal) {
            minVal = totalMax;
            memcpy(minOrder, order, sizeof(order));
        }
    }
}


int main(){
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    while(gets(str)){
        if(str[0]=='#') break;

        read_in();

        minVal = 9999999;
        memset(vis, 0, sizeof(vis));
        search(0);

        for(int i=0; i<cnt; ++i) printf("%c ",edge[minOrder[i]]+'A');
        printf("-> %d\n", minVal);
    }
    return 0;
}
