#include<bits/stdc++.h>
using namespace std;

string fun(int n){

if(n==1){
    return "1";
}

queue<int>q;
int parent[n];
int val[n];

for(int i=0;i<=n;i++){
    parent[i]=-1;
}
q.push(1);
parent[1]=0;

while(!q.empty()){

    int t=q.front();
    q.pop();

    if(t==0){

        stack<int>s;
        while(parent[t]){
            s.push(val[t]);
            t=parent[t];
        }
        s.push(1);
        string ans="";
        while(!s.empty()){
            ans+=char('0'+s.top());
            s.pop();
        }
        return ans;
    }

    int a=(t*10)%n;
    int b=(t*10+1)%n;

    if(parent[a]==-1){
        q.push(a);
        parent[a]=t;
        val[a]=0;
    }
    if(parent[b]==-1){
        q.push(b);
        parent[b]=t;
        val[b]=1;
    }
}

}


int main(){

int n;
cin>>n;


cout<<fun(n);


return 0;
}
