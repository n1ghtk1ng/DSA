#include<bits/stdc++.h>
using namespace std;

class Node{
public:
string data;
Node* parent;
int rank;

Node(string d){
    data=d;
    rank=1;
}

};

///creating individual elements set

void makeset(string d,unordered_map<string,Node*>&m){
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
int unionset(string d1,string d2,unordered_map<string,Node*>&m){
Node*node1=m[d1];
Node*node2=m[d2];

Node*parent1=findset(node1);
Node*parent2=findset(node2);

if(parent1==parent2){
    return parent1->rank;
}
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
return r1+r2;
}




int main(){
int t;

cin>>t;

while(t--){
unordered_map<string,Node*>m;

int n;
cin>>n;
string a,b;

for(int i=0;i<n;i++){
    cin>>a>>b;
    if(!m[a]){
        makeset(a,m);
    }
    if(!m[b]){
        makeset(b,m);
    }
    cout<<unionset(a,b,m)<<endl;
}


}
return 0;
}
