#include<iostream>
#include "Queue.h"
#include "QueueLL.h"
using namespace std;


int main(){
    Queue q1;
    QueueLL q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    q.pop();
    q.push(6);
    while(!q.isEmpty()){
        cout<< q.getFront();
        q.pop();
    }





}
