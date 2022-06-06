#include<bits/stdc++.h>
using namespace std;

stack<int>s;
int mini;
//MinStack() {
//    while(!s.empty())
//    s.pop();
//
//    mini=INT_MAX;
//}

void push(int x) {
    if(s.empty()){
        s.push(x);
        mini=x;
    }
    else{
        if(x>mini){
            s.push(x);
        }
        else{
            s.push(2*x-mini);
            mini=x;
        }
    }
}

int top() {
    if(s.empty())
    return -1;

    int t=s.top();
    // here assumption is that the element inserted into stak is minimum if it is less than mini
    // that is why we push 2*newmin - currmin (not newmin-currmin )e.g. -4 in stack, -6 to push
    // 2*newmin - currmin will always be less than newmin
    if(t<mini)
    return mini;
    else
    return t;
}
void pop() {
    if(!s.empty()){
        int t=s.top();
        s.pop();

        if(t<mini){
            mini=2*mini-t;
        }
    }

}



int getMin() {
    if(s.empty())
    return -1;
//    cout<<"mini = "<<mini<<endl;
    return mini;
}



int main(){

push(10);
push(9);
cout<<getMin()<<" ";
push(8);
cout<<getMin()<<" ";
push(7);
cout<<getMin()<<" ";
push(6);
cout<<getMin()<<" ";

pop();
cout<<getMin()<<" ";
pop();
cout<<getMin()<<" ";
pop();
cout<<getMin()<<" ";
pop();
cout<<getMin()<<" ";
pop();
cout<<getMin()<<" ";

return 0;
}
