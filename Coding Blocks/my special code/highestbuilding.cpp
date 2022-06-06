#include<bits/stdc++.h>
using namespace std;

int findsmallerelementcount(stack<int>&s,int x,int c=0)
{
    if(s.empty())
    {
        return 1;
    }
    if(s.top()<x  )
    {
        c++;
    }
    int y=s.top();
    s.pop();
    c+=findsmallerelementcount(s,x);
    s.push(y);
    return c;

}
void printans(stack<int>&s)
{
    if(s.empty())
    return;

    int x=s.top();
    s.pop();
    printans(s);

    cout<<findsmallerelementcount(s,x)<<" ";
    s.push(x);

}

int main(){

int n,d;
stack<int>s;

cin>>n;


for(int i=0;i<n;i++)
{
    cin>>d;
    s.push(d);
}
printans(s);

}
