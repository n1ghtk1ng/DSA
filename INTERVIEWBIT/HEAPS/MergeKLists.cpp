#include<bits/stdc++.h>
using namespace std;

class mycomp{
  public:
    bool operator()(int a,int b){
        return a>b;
    }
};


int main(){

priority_queue<int,vector<int>,mycomp>pq;
pq.push(1);
pq.push(2);
pq.push(3);
pq.push(4);

while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
}



return 0;
}
