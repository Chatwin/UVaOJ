#include<cstdio>
#include<algorithm>
using namespace std;
const int kMaxn(3657);

bool d[kMaxn];

int main()
{
    /*
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    //*/

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,p;
        scanf("%d%d",&n,&p);
        fill(d,d+kMaxn,false);
        for(int i=1;i<=p;i++)
        {
            int h;
            scanf("%d",&h);
            int j(0),k(6);
            while(j<=n)
            {
                j+=h;
                k=(k+h)%7;
                if(k!=5 && k!=6)
                    d[j]=true;
            }
        }
        int ans(0);
        for(int i=1;i<=n;i++)
            if(d[i])
                ans++;
        printf("%d\n",ans);
    }

    return 0;
}
