#include<algorithm>
#include<cstdio>
using namespace std;
const int kMaxk(27);

int n,m,k,ans,b[kMaxk],e[kMaxk],p[kMaxk],cnt[kMaxk];
bool used[kMaxk];

void dfs(int s,int now)
{
    ans=max(ans,now);
    for(int i=s+1;i<=k;i++)
    {
        used[i]=true;
        bool success(true);
        for(int j=b[i];j<e[i];j++)
        {
            cnt[j]+=p[i];
            if(cnt[j]>n)
                success=false;
        }
        if(success)
            dfs(i,now+(e[i]-b[i])*p[i]);
        used[i]=false;
        for(int j=b[i];j<e[i];j++)
            cnt[j]-=p[i];
    }
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&k)==3 && (n || m || k))
    {
        for(int i=1;i<=k;i++)
            scanf("%d%d%d",&b[i],&e[i],&p[i]);

        ans=0;
        dfs(0,0);

        printf("%d\n",ans);
    }

    return 0;
}
