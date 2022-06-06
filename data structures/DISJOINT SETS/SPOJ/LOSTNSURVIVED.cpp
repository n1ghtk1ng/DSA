#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>cnt;
set<int>cn;

class Node{

public:
int data;
Node* parent;
int rank;

Node(int d){
    data=d;
    rank=1;
}

};

///creating individual elements set

void makeset(int d,unordered_map<int,Node*>&m){
Node *n=new Node(d);
n->parent=n;
m[d]=n;
}

/// finding parent in the set
Node* findset(Node*node){
if(node->parent==node){
    return node;
}
node->parent=findset(node->parent);
return node->parent;
}


/// union in the set
void unionset(int d1,int d2,unordered_map<int,Node*>&m){
Node*node1=m[d1];
Node*node2=m[d2];

Node*parent1=findset(node1);
Node*parent2=findset(node2);
if(parent1==parent2)
    return;

int r1=parent1->rank;
int r2=parent2->rank;

cnt[r1]--;
if(cnt[r1]==0){
    cn.erase(r1);
}
cnt[r2]--;
if(cnt[r2]==0){
    cn.erase(r2);
}
if(parent1->rank>=parent2->rank){
    parent1->rank=r1+r2;
    parent2->parent=parent1;
}
else{
    parent2->rank=r1+r2;
    parent1->parent=parent2;
}
if(cnt[r1+r2]==0){
    cnt[r1+r2]++;
    cn.insert(r1+r2);
}
else{
    cnt[r1+r2]++;
}
}



int main(){
int n,q,n1,n2;
cin>>n>>q;
unordered_map<int,Node*>m;

for(int i=1;i<=n;i++){
    makeset(i,m);
}
cnt[1]=n;
cn.insert(1);

while(q--){
cin>>n1>>n2;
unionset(n1,n2,m);

int ans=*cn.rbegin()-*cn.begin();

cout<<ans<<endl;
}

return 0;
}
