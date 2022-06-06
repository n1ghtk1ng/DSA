#include<iostream>
#include "priority_queue.h"
using namespace std;


int main(){

Priority_Queue q;
q.push(5);
q.push(15);
q.push(13);
q.push(17);
q.push(3);
q.push(31);

while(!q.isEmpty()){
    cout<< q.getMin()<<endl;
    q.pop();
}



return 0;
}
