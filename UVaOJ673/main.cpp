#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n;
string str;
enum Parentheses
{
   BRACKET,
   PARENTHESIS,
};
stack<Parentheses> parentheses;
bool isYes;
int main()
{
    cin>>n;
    cin.get();
    while (n --)
    {
       while (! parentheses.empty())
       {
          parentheses.pop();
       }
       getline(cin, str);
       isYes = true;
       for (unsigned int i = 0; i < str.length(); i++)
       {
          if (str[i] == '(')
          {
             parentheses.push(PARENTHESIS);
          }
          else if (str[i] == '[')
          {
             parentheses.push(BRACKET);
          }
          else if (str[i] == ')')
          {
             if (parentheses.empty() || parentheses.top() != PARENTHESIS)
             {
                isYes = false;
                break;
             }
             else
             {
                parentheses.pop();
             }
          }
          else if (str[i] == ']')
          {
             if (parentheses.empty() || parentheses.top() != BRACKET)
             {
                isYes = false;
                break;
             }
             else
             {
                parentheses.pop();
             }
          }
       }
       if (! parentheses.empty())
       {
          isYes = false;
       }
       if (isYes)
       {
          cout<<"Yes"<<endl;
       }
       else
       {
          cout<<"No"<<endl;
       }
    }
    return 0;
}
