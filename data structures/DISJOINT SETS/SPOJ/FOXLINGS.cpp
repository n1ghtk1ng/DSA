#include<bits/stdc++.h>
using namespace std;
int ans;

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
if(!m[d1])
makeset(d1,m);
if(!m[d2])
makeset(d2,m);

Node*node1=m[d1];
Node*node2=m[d2];

Node*parent1=findset(node1);
Node*parent2=findset(node2);
if(parent1==parent2)
    return;

int r1=parent1->rank;

int r2=parent2->rank;


if(parent1->rank>=parent2->rank){
    parent1->rank=r1+r2;
    parent2->parent=parent1;
}
else{
    parent2->rank=r1+r2;
    parent1->parent=parent2;
}
ans--;

}



int main(){
int n,q,n1,n2;
cin>>n>>q;
unordered_map<int,Node*>m;


ans=n;

while(q--){
cin>>n1>>n2;
unionset(n1,n2,m);

}
cout<<ans;
return 0;
}
