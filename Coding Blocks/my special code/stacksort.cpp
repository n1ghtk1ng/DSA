#include<bits/stdc++.h>
using namespace std;
void insertsortedly(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    if(s.top() > x)
    {
        s.push(x);
        return;
    }
    int t=s.top();
    s.pop();
    insertsortedly(s,x);
    s.push(t);

}

void sortstack(stack<int>&s)
{
    if(s.empty())
        return;

    int top=s.top();
    s.pop();
    sortstack(s);
    insertsortedly(s,top);

}


int main()
{
    stack<int>s;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        s.push(d);
    }
    sortstack(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }



}
