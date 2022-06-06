#ifndef STACK_H
#define STACK_H
#include<queue>
using namespace std;
class stack
{
public:
    queue<int>q1;
    queue<int>q2;

    void push(int d)
    {
        if(q1.empty() && q2.empty())
        {
            q1.push(d);
        }
        else if(!q1.empty() && q2.empty())\
        {
            q1.push(d);
        }
        else
        {
            q2.push(d);
        }
    }
    void pop()
    {
        if(!q1.empty() && q2.empty())
        {
            while(!q1.empty())
            {
               q2.push(q1.front());
               q1.pop();
            }
            q2.pop();
        }
        else if(q1.empty() && !q2.empty())
        {
            while(!q2.empty())
            {
               q1.push(q2.front());
               q2.pop();
            }
            q1.pop();
        }
    }

    int top()
    {
        if(!q1.empty() && q2.empty())
        {
            while(!q1.empty())
            {
               q2.push(q1.front());
               q1.pop();
            }
            return q2.front();
        }
        else if(q1.empty() && !q2.empty())
        {
            while(!q2.empty())
            {
               q1.push(q2.front());
               q2.pop();
            }
            return q1.front();
        }
    }
    bool empty()
    {
        if(q1.empty() && q2.empty())
            return true;
        else
            return false;
    }


};

#endif // STACK_H
