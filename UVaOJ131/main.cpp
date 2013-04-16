#include<stdio.h>
#include<string.h>
char *b="A23456789TJQK";
char *c="CDHS";
char ans[][20]={"straight-flush","four-of-a-kind","full-house","flush",
"straight","three-of-a-kind","two-pairs","one-pair","highest-card"};
char a[15][5];
int face[15],suit[15][5];
int search()
{
    int i,j,k,f,n,first;

    for(first=0;!face[first];first++);

    for(i=first;i<13;i++)
        if(face[i])
        {
            for(j=i,n=0;j<13&&face[j];j++)
                n++;
            if(n==5||(n==4&&j==13&&face[0]))
            {
                for(k=0;k<4;k++)
                    if(suit[first][k])
                        break;
                for(f=first+1;f<13;f++)
                    if(face[f]&&suit[f][k]!=suit[first][k])
                        break;
                if(f==13)
                    return 0;
            }
        }

    for(i=first;i<13;i++)
        if(face[i]==4)
            return 1;

    for(i=first;i<13;i++)
        if(face[i]==3)
        {
            for(j=first;j<13;j++)
                if(face[j]==2)
                    return 2;
            break;
        }

    for(k=0;k<4;k++)
    {
        for(i=first;i<13;i++)
            if(face[i]>1||(face[i]&&!suit[i][k]))
                break;
        if(i==13)
            return 3;
    }

    for(i=first;i<13;i++)
        if(face[i])
        {
            for(n=0,j=i;j<13&&face[j];j++)
                n++;
            if(n==5||(n==4&&j==13&&face[0]))
                return 4;
        }

    for(i=first;i<13;i++)
        if(face[i]==3)
            return 5;

    for(i=first;i<13;i++)
        if(face[i]==2)
            for(j=i+1;j<13;j++)
                if(face[j]==2)
                    return 6;


    for(i=first;i<13;i++)
        if(face[i]==2)
            return 7;

    return 8;
}
int main()
{
    int i,j,k,f,n,num,min;
    while(scanf("%s",a[0])!=EOF)
    {
        for(i=1;i<10;i++)
            scanf("%s",a[i]);
        min=10;
        for(i=0;i<(1<<5);i++)
        {
            memset(face,0,sizeof(face));
            memset(suit,0,sizeof(suit));
            num=0;
            for(j=0;j<5;j++)
                if(i&(1<<j))
                {
                    num++;
                    f=strchr(b,a[j][0])-b;
                    face[f]++;
                    k=strchr(c,a[j][1])-c;
                    suit[f][k]++;
                }
            for(j=5;j<10-num;j++)
            {
                f=strchr(b,a[j][0])-b;
                face[f]++;
                k=strchr(c,a[j][1])-c;
                suit[f][k]++;
            }
            n=search();
            if(n<min)
                min=n;
        }
        printf("Hand: ");
        for(i=0;i<5;i++)
            printf("%s ",a[i]);
        printf("Deck: ");
        for(;i<10;i++)
            printf("%s ",a[i]);
        printf("Best hand: ");
        printf("%s\n",ans[min]);
    }
    return 0;
}
