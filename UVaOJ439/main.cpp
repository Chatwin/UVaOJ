#include <stdio.h>
#include <string.h>
#include <queue>
#define MAX 70
using namespace std;
bool vis[70];
int START,END;
char s[10];
struct node
{int num,r,c,k;};
queue<struct node> q;

void BFS()
{
    int i,k,R[9],C[9];
    struct node tmp;

    while(!q.empty()) q.pop();
    tmp.num=START; tmp.k=0;
    tmp.r = ((START%8)==0) ? (START/8) : (START/8+1) ;
    tmp.c = ((START%8)==0) ? 8 : START%8 ;
    q.push(tmp);   //初始化把起点入队
    if(tmp.num==END) q.pop();
    while(!q.empty())  //这个判断可以省去
    {
        tmp=q.front(); q.pop(); //出队一个元素
        k=tmp.k;
        R[1]=tmp.r-2;  C[1]=tmp.c-1;
        R[2]=tmp.r-2;  C[2]=tmp.c+1;
        R[3]=tmp.r-1;  C[3]=tmp.c+2;
        R[4]=tmp.r+1;  C[4]=tmp.c+2;
        R[5]=tmp.r+2;  C[5]=tmp.c+1;
        R[6]=tmp.r+2;  C[6]=tmp.c-1;
        R[7]=tmp.r+1;  C[7]=tmp.c-2;
        R[8]=tmp.r-1;  C[8]=tmp.c-2;

        for(i=1; i<=8; i++)
        {
            if(R[i]>=1 && R[i]<=8 && C[i]>=1 && C[i]<=8)
            {
                tmp.r=R[i]; tmp.c=C[i]; tmp.k=k+1;
                tmp.num=(tmp.r-1)*8+tmp.c;
                q.push(tmp);   //入队
                if(tmp.num==END)  break;
            }
        }

        if(i<=8)  break;

    }
    printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],tmp.k);

    return ;

}
int main()
{
    int r,c;
    while(gets(s))
    {
        c=s[0]-'a'+1;  r=s[1]-'0';
        START=8*(r-1)+c;
        c=s[3]-'a'+1;  r=s[4]-'0';
        END=8*(r-1)+c;

        BFS();
    }
    return 0;
}
