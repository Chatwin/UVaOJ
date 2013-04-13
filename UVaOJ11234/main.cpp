#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct Tree
{
   char value;
   Tree *left;
   Tree *right;
}Tree;

char s[10001];
Tree * Build_Tree(char c, Tree *left, Tree *right)
{
   Tree *father;
   father = (Tree *)malloc(sizeof(Tree));
   father->value = c;
   father->left = left;
   father->right = right;

   return father;
}
int main()
{
    int T;
    cin>>T;
    stack<Tree *>st;
    while (T --)
    {
       cin>>s;
       int length = strlen(s);
       for (int i = 0; i < length; i ++)
       {
          if (s[i] >= 'a' && s[i] <= 'z')
          {
             Tree *tree;
             tree = (Tree *)malloc(sizeof(Tree));
             tree->value = s[i];
             tree->left = tree->right = NULL;
             st.push(tree);
          }
          else
          {
             Tree *Father;
             Tree *Left, *Right;
             Right = st.top();
             st.pop();
             Left = st.top();
             st.pop();
             Father = Build_Tree(s[i], Left, Right);
             st.push(Father);
          }
       }
       queue<Tree *>qt;
       int k = 0;
       Tree *t;
       qt.push(st.top());
       while (! qt.empty())
       {
          t = qt.front();
          qt.pop();
          s[k ++] = t->value;
          if (t->left)
          {
             qt.push(t->left);
          }
          if (t->right)
          {
             qt.push(t->right);
          }
       }
       for (k = k - 1; k >= 0; k --)
       {
          cout<<s[k];
       }
       cout<<endl;
    }
    return 0;
}
