#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Tree
{
   char data;
   Tree *child[4];
}Tree;
Tree tree[20000];
int n, pos1, pos2, sum;
char str1[100001], str2[100001];
inline Tree *NewNode()
{
   tree[n].data = 0;
   for (int i = 0; i < 4; i ++)
   {
      tree[n].child[i] = NULL;
   }

   return &tree[n ++];
}
Tree *BuildTree(Tree *root, int &pos, char *str)
{
   ++pos;
   if (pos == (int)strlen(str)) return NULL;
   root = NewNode();
   root->data = str[pos];
   if (str[pos] == 'p')
   {
      for (int i = 0; i < 4; i ++)
      {
         if (root->child[i] == NULL)
         {
            root->child[i] = BuildTree(root->child[i], pos, str);
         }
      }
   }

   return root;
}

void dfs(Tree *root1, Tree *root2, int level)
{
   if (root1 == NULL && root2 == NULL) {return;}
   if (!root1)
   {
      if (root2->data == 'f')
      {
         sum += 1024>>(2 * level);
         return;
      }
      for (int i = 0; i < 4; i ++)
      {
         dfs(root1, root2->child[i], level + 1);
      }
      return;
   }
   if (!root2)
   {
      if (root1->data == 'f')
      {
         sum += 1024>>(2 * level);
         return;
      }
      for (int i = 0; i < 4; i ++)
      {
         dfs(root1->child[i], root2, level + 1);
      }
      return;
   }
   if (root1->data == 'f' || root2->data == 'f')
   {
      sum += 1024>>(2 * level);
      return;
   }
   for (int i = 0; i < 4; i ++)
   {
      dfs(root1->child[i], root2->child[i], level + 1);
   }
}
void Solve()
{
   Tree *root1, *root2;
   pos1 = -1;
   pos2 = -1;
   n = 0;
   root1 = root2 = (Tree *)malloc(sizeof(Tree));
   root1 = BuildTree(root1, pos1, str1);
   root2 = BuildTree(root2, pos2, str2);
   sum = 0;
   dfs(root1, root2, 0);
   cout<<"There are "<<sum<<" black pixels."<<endl;
}

int main()
{
    int T;
    cin>>T;
    while (T --)
    {
       cin>>str1;
       getchar();
       cin>>str2;
       getchar();
       Solve();
    }
    return 0;
}
