#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int LIMITS = 100;
struct Node
{
   Node *pred;
   int val;
   Node *rear;
};

int n;
int a, b;
char commond[100];
char first_word[100];
char second_word[100];
Node *head[LIMITS];
Node *block[LIMITS];
int pos[LIMITS];

void Init()
{
   for (int i = 0; i < n; i ++)
   {
      head[i] = new Node;
      block[i] = new Node;
      head[i]->pred = NULL;
      head[i]->val = -1;
      head[i]->rear = block[i];
      block[i]->pred = head[i];
      block[i]->val = i;
      block[i]->rear = NULL;
      pos[i] = i;
   }
}
void ReturnOriginalPos(Node *p)
{
   if (p == NULL)
   {
      return;
   }
   ReturnOriginalPos(p->rear);
   p->pred = head[p->val];
   p->rear = NULL;
   head[p->val]->rear = p;
   pos[p->val] = p->val;
}
void Connect(Node *a, Node *b)
{
   a->pred->rear = NULL;
   a->pred = b;
   b->rear = a;
   pos[a->val] = pos[b->val];
}
void MoveAOntoB(Node *a, Node *b)
{
   ReturnOriginalPos(a->rear);
   ReturnOriginalPos(b->rear);
   a->rear = NULL;
   Connect(a, b);
}
void MoveAOverB(Node *a, Node *b)
{
   ReturnOriginalPos(a->rear);
   a->rear = NULL;
   Node *b_tail = b;
   while (b_tail->rear != NULL)
   {
      b_tail = b_tail->rear;
   }
   Connect(a, b_tail);
}
void PileAOntoB(Node *a, Node *b)
{
   ReturnOriginalPos(b->rear);
   Connect(a, b);
   Node *p = a->rear;
   while (p != NULL)
   {
      pos[p->val] = pos[b->val];
      p = p->rear;
   }
}
void PileAOverB(Node *a, Node *b)
{
   Node *b_tail = b;
   while (b_tail->rear != NULL)
   {
      b_tail = b_tail->rear;
   }
   Connect(a, b_tail);
   Node *p = a->rear;
   while (p != NULL)
   {
      pos[p->val] = pos[b->val];
      p = p->rear;
   }
}
void Output()
{
   for (int i = 0; i < n; i ++)
   {
      cout<<i<<":";
      Node *p = head[i]->rear;
      while (p != NULL)
      {
         cout<<" "<<p->val;
         p = p->rear;
      }
      cout<<endl;
   }
}
int main()
{
    while (cin>>n)
    {
       getchar();
       Init();
       while (cin>>first_word)
       {
          if (strcmp(first_word, "quit") == 0)
          {
             break;
          }
//          cin>>commond;
//          sscanf(commond, "%d%s%d", &a, second_word, &b);
          cin>>a>>second_word>>b;
          if (pos[a] != pos[b])
          {
             if (strcmp(first_word, "move") == 0)
             {
                if (strcmp(second_word, "onto") == 0)
                {
                   MoveAOntoB(block[a], block[b]);
                }
                if (strcmp(second_word, "over") == 0)
                {
                   MoveAOverB(block[a], block[b]);
                }
             }
             if (strcmp(first_word, "pile") == 0)
             {
                if (strcmp(second_word, "onto") == 0)
                {
                   PileAOntoB(block[a], block[b]);
                }
                if (strcmp(second_word, "over") == 0)
                {
                   PileAOverB(block[a], block[b]);
                }
             }
          }
       }
       Output();
       for (int i = 0; i < n; i++)
       {
          delete head[i];
          delete block[i];
       }
    }

    return 0;
}
