#include<iostream>
#include"stackusingqueue.h"
using namespace std;

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
