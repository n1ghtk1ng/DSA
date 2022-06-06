#include<iostream>
#include "Node.h"
#include "Stack.h"
#include "Book.h"
using namespace std;



int main(){
    Stack<int> s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }

    while(!s.isEmpty()){
        cout<< s.top()<<endl;
        s.pop();
    }

    Stack<char> sc;
    sc.push('a');
    sc.push('b');
    sc.push('c');

    while(!sc.isEmpty()){
        cout<< sc.top();
        sc.pop();
    }
    Stack<string> ss;
    ss.push("Coding");
    ss.push("Blocks");
    cout<<ss.top();

    Book b1("C++",100);
    Book b2("Java",200);

    Stack<Book> sb;
    sb.push(b1);
    sb.push(b2);

    while(!sb.isEmpty()){
        sb.top().print();
        sb.pop();

    }


return 0;
}
