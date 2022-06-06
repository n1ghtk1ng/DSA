#include<iostream>
#include<cstring>
#include"node.h"
#include"stack.h"
#include"book.h"
using namespace std;


int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    while(!s.isempty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    book b1("c++",100);
    book b2("java",200);
    book b3("python",300);
    book b4("javascript",150);

     stack<book>sb;
     sb.push(b1);
     sb.push(b2);
     sb.push(b3);
     sb.push(b4);
     while(!sb.isempty())
     {
         sb.top().print();
         sb.pop();
     }

}
