#include<bits/stdc++.h>
using namespace std;

void insertatbottom(stack<int>&s,int d)
{
    if(s.empty())
    {
        s.push(d);
         return ;
    }

    int t=s.top();
    s.pop();
    insertatbottom(s,d);
    s.push(t);

}

void reversestack(stack<int>&s)
{
    if(s.empty())
        return ;

    int d=s.top();
    s.pop();
    reversestack(s);
    insertatbottom(s,d);

}
int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reversestack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }


}
