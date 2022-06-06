#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s1,int data){
    if(s1.empty()){
        s1.push(data);
        return;
    }
    int top = s1.top();
    s1.pop();
    insertAtBottom(s1,data);
    s1.push(top);
}

void ReverseStack(stack<int> &s){
    if(s.empty()==true){
        return;
    }

    int data = s.top();
    s.pop();
    /// Reverse the chota Stack
    ReverseStack(s);

    ///Insert the topmost element at bottom
    insertAtBottom(s,data);
}

int main(){
stack<int> s;
for(int i=1;i<=5;i++){
    s.push(i);
}

ReverseStack(s);

while(!s.empty()){
    cout<< s.top()<<endl;
    s.pop();

}


return 0;
}


