#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Tree
{
   char value;
   string name;
   Tree *left, *right;
};

int n;
int pos;
string name[1024];
char ans[1024];

inline Tree *NewNode(string sname)
{
   Tree *root;
   root = new Tree;
   root->value = '0';
   root->name = sname;
   root->left = NULL;
   root->right = NULL;

   return root;
}

Tree *BuildTree(string name[], int cur, string terminal)
{
   if (cur == n)
   {
      Tree *u;
      u = NewNode(name[cur]);
      u->value = terminal[pos ++];

      return u;
   }
   else
   {
 //     Tree *p = (Tree *)malloc(sizeof(Tree));
      Tree *p;
      p = NewNode(name[cur]);
      p->left = BuildTree(name, cur + 1, terminal);
      p->right = BuildTree(name, cur + 1, terminal);

      return p;
   }
}

char dfs(Tree *root, string str)
{
   Tree *u;
   u = root;
   int length = str.length();
   for (int i = 0; i < length; i ++)
   {
      if (str[i] == '0')
      {
         u = u->left;
      }
      else
      {
         u = u->right;
      }
   }

   return u->value;
}
int main()
{
    int count = 0;
    while (cin>>n)
    {
       if (n == 0) {break;}
       for (int i = 0; i < n; i ++)
       {
          cin>>name[i];
       }
       string terminal;
       cin>>terminal;
       pos = 0;
       Tree *root = (Tree *)malloc(sizeof(Tree));
       root = BuildTree(name, 0, terminal);
       int k;
       cin>>k;
       for(int i = 0; i < k; i ++)
       {
            string temp;
            cin>>temp;
            ans[i] = dfs(root, temp);
       }
       cout<<"S-Tree #"<<++count<<":"<<endl;
       for (int i = 0; i < k; i ++)
       {
          cout<<ans[i];
       }
       cout<<endl<<endl;
    }

    return 0;
}
