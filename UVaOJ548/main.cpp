#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int M = 10000000;
vector<int> a,b;
int X= M;
int out = 0;
int k = 0;
//定义二叉树
typedef struct treenode
{
    int num;
    struct treenode* lchild;
    struct treenode* rchild;
}tree;
tree * creattree(vector<int> & aa, vector<int> & bb , int n)
{
    if(n == 0) return NULL;
    tree *p;
    p = new tree;
    p->num = bb[n-1];
    //左子树后序 左子树中序 右子树后序 右子树中序
    vector<int> lrev, lmid, rrev,rmid;
    int m = 0;
    for(int i = 0; i < n; i++)
    {
        if(aa[i] == p->num)
        {
            m = i;
            break;
        }
    }
    int j = 0;
    for(int i = 0; i < m; i++)
    lmid.push_back(aa[i]);
    for(int i = m +1; i < n; i++ )
    rmid.push_back(aa[i]);
    for(int i = 0; i < m; i++)
    lrev.push_back(bb[i]);
    for(int i = m; i < n -1; i++)
    rrev.push_back(bb[i]);
    p->lchild = creattree(lmid,lrev,m);
    p->rchild = creattree(rmid,rrev,n - m - 1);
    return p;
}
void searchtree(tree * p, int value)
{
    if(p != NULL)
    {
        if((p->lchild == NULL) && (p->rchild == NULL))
        {
            value = p->num + value;
            if(value < X)
            {
                X = value;
                out = p->num;
            }
            if(value == X)
            {
                if(out > p->num)
                out  = p->num;
            }
        }
        if(p->lchild != NULL ) searchtree(p->lchild,p->num + value);
        if(p->rchild != NULL ) searchtree(p->rchild,p->num + value);
    }
}
//  处理读入数据 有vector存储
void chuli(string str1,string str2)
{
       istringstream in(str1);
        int i = 0;
        int  num;
    //  中序
        while(!in.eof())
        {
            in >> num;
            a.push_back(num);
        }
        i = 0;
        istringstream is(str2);
        // 后序
        while(!is.eof())
        {
            is >> num;
            b.push_back(num);
        }
        k = a.size();
}
int main()
{
    string str1,str2;
    while(getline(cin,str1))
    {
        k = 0;
        getline(cin ,str2);
        out = 0;
        X = M;
        chuli(str1,str2);
        tree * p = new tree;
        p =  creattree(a,b,k);
        searchtree(p,0);
        cout << out << endl;
        a.clear();
        b.clear();
    }
    return 0;
}
