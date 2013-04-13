#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int M = 55;
int n,flag,cnt,colournum,b;
int mapp[M][M];
int num[M];
bool visit[M];
//�ж��Ƿ��ܹ���ŷ��ͨ· ��һ������ܹ�����ĵ�ĸ����� cnt ��ʾ
void dfs(int  a)
{
    visit[a] = true;
    cnt++;
    for(int i = 0; i < 51; i++)
    {
        if(!visit[i] && mapp[a][i])
        dfs(i);
    }
    return ;
}
void euler( int a)
{
    for(int i = 1; i < 51; i++)
    {
        if(mapp[a][i])
        {
            mapp[a][i]--;
            mapp[i][a]--;
            euler(i);
            cout << i << ' ' << a << endl;
        }
    }
    return ;
}
int main()
{
    int ncase;
    cin >> ncase;
    for(int j = 0; j < ncase; j++)
    {
        if(j) cout << endl;
        memset(mapp,0,sizeof(mapp));
        memset(num,0,sizeof(num));
        memset(visit,false,sizeof(visit));
        flag = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int x,y;
            cin >> x >> y;
            mapp[x][y]++;
            mapp[y][x]++;
            num[x]++;
            num[y]++;
        }
        colournum = 0;
        //�жϵ�Ķ����Ƿ������  ������ͼ�е�ĸ���
        for(int i = 1; i < 51; i++)
        {
            if(num[i])  {colournum++; b = i;}
            if(num[i]%2) { flag = 1; break;}
        }
        cnt = 0;
        cout << "Case #" << j+1 << endl;
        if(!flag)
        {
            dfs(b);
            // ���һ��ͨ·���ܱ������еĵ� ��϶�������ŷ����·
            if(cnt != colournum)
            cout << "some beads may be lost" << endl;
            else
            euler(b);
        }
        else
        cout << "some beads may be lost" << endl;

    }
    return 0;
}
