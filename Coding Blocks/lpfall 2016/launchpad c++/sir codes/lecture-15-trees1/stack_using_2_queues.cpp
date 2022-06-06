#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Stack{
    queue<T> q1;
    queue<T> q2;
public:
    void push(T data){
        if(q1.empty()&&q2.empty()){
                q1.push(data);
        }
        else if(!q1.empty()&&q2.empty()){
            q1.push(data);
        }
        else{
            q2.push(data);
        }

    }
    void pop(){
        if(!q1.empty() && q2.empty()){
                while(q1.size()>1){
                    T data = q1.front();
                    q1.pop();
                    q2.push(data);
                }
                q1.pop();

        }
        else{
                while(q2.size()>1){
                     T data = q2.front();
                     q2.pop();
                     q1.push(data);
                }
                q2.pop();
        }

    }
    T top(){

        if(!q1.empty() && q2.empty()){
                while(q1.size()>1){
                    T data = q1.front();
                    q1.pop();
                    q2.push(data);
                }
                T top = q1.front();
                q1.pop();
                q2.push(top);
                return top;

        }
        else{
                while(q2.size()>1){
                     T data = q2.front();
                     q2.pop();
                     q1.push(data);
                }
                T top = q2.front();
                q2.pop();
                q1.push(top);
                return top;
        }
    }
    bool isEmpty(){
        return q1.empty()&&q2.empty();
    }

};



int main(){
    Stack<int> s;
    for(int i=0;i<5;i++){
        s.push(i);
    }
    while(!s.isEmpty()){
        cout<< s.top()<<endl;
        s.pop();
    }
return 0;
}
