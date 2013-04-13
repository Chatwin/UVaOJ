#include<stdio.h>
#include<string.h>
#define MAXD 1000010
int size, wl[MAXD], wr[MAXD], dl[MAXD], dr[MAXD], d[MAXD], ok;
int dfs()
{
    int k;
    ++ size;
    k = size;
    scanf("%d%d%d%d", &wl[k], &dl[k], &wr[k], &dr[k]);
    if(wl[k] == 0)
        wl[k] = dfs();
    if(wr[k] == 0)
        wr[k] = dfs();
    if(wl[k] * dl[k] != wr[k] * dr[k])
        ok = 0;
    return wl[k] + wr[k];
}
void solve()
{
    size = 0;
    ok = 1;
    dfs();
    if(ok)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        if(tt)
            printf("\n");
        solve();
    }
    return 0;
}
