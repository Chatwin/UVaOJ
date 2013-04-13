#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

char disk[205][205];
char ourTree[200000];
int line[205];
int r;

inline bool IsNode(char c)
{
    return isprint(c) && c != '|' && c != '-' && c != ' ' && c != '#';
}

void ConvertTree(int row, int col, int &idx)
{
    ourTree[idx++] = disk[row][col];
    ourTree[idx++] = '(';
    if(row + 1 < r && col < line[row + 1] && disk[row + 1][col] == '|')
    {
        int rr = row + 2;
        int left = col, right = col;
        for( ; left > 0 && disk[rr][left - 1] == '-'; --left);
        for( ; right < line[rr] - 1 && disk[rr][right + 1] == '-'; ++right);
        for(int i = left; i <= right; ++i)
        {
            if(i < line[rr + 1] && IsNode(disk[rr + 1][i]))
            ConvertTree(rr + 1, i, idx);
        }
    }
    ourTree[idx++] = ')';
}

int main()
{
    int ca;
    scanf("%d", &ca);
    getchar();
    while(ca--)
    {
        r = 0;
        memset(disk, 0, sizeof(disk)); //注意每轮开始时清空数组。如果去掉该句，会wa.
        while(gets(disk[r]) && disk[r][0] != '#')
        {
            line[r] = strlen(disk[r]);
            ++r;
        }
        int idx = 0;
        ourTree[idx++] = '(';
        for(int i = 0; i < line[0]; ++i)
        {
            if(IsNode(disk[0][i]))
            ConvertTree(0, i, idx);
        }
        ourTree[idx++] = ')';
        ourTree[idx++] = '\0';
        printf("%s\n", ourTree);
    }
    return 0;
}
