#include <iostream>
#include <cstdio>
using namespace std;
struct Node
{
   Node *pred;
   int num;
   Node *rear;
};
int n, k, m;
int num_people;
Node *head;
Node *tail;
Node *official_1;
Node *official_2;
void MakeList()
{
   Node *p = new Node;
   head = p;
   for (int i = 0; i < n - 1; i ++)
   {
      p->num = i + 1;
      p->rear = new Node;
      p->rear->pred = p;
      p = p->rear;
   }
   tail = p;
   tail->num = n;
   tail->rear = head;
   head->pred = tail;
}
void Countoff(Node *&p, int num, bool is_reverse)
{
   while (num --)
   {
      p = is_reverse ? p->pred : p->rear;
   }
}
void Delete(Node *&p, bool is_reverse)
{
   p->pred->rear = p->rear;
   p->rear->pred = p->pred;

   if (is_reverse && official_2 == official_1)
   {
      official_1 = official_1->rear;
   }
   Node *temp = is_reverse ? p->pred : p->rear;
   delete p;
   p = temp;
}
int main()
{
    while(cin>>n>>k>>m)
    {
       if (!n && !k && !m)
       {
          break;
       }
       MakeList();
       official_1 = head;
       official_2 = tail;
       num_people = n;
       while (num_people)
       {
          Countoff(official_1, k - 1, false);
          Countoff(official_2, m - 1, true);
          if (official_1 != official_2)
          {
             printf("%3d%3d", official_1->num, official_2->num);
             if (num_people != 2)
             {
                cout<<",";
             }
             else
             {
                cout<<endl;
             }
             Delete(official_1, false);
             Delete(official_2, true);
             num_people -= 2;
          }
          else
          {
             printf("%3d", official_1->num);
             if (num_people != 1)
             {
                cout<<",";
             }
             else
             {
                cout<<endl;
             }
             official_2 = official_2->pred;
             Delete(official_1, false);
             num_people --;
          }
       }
    }
    return 0;
}
