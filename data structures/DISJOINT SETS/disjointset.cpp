#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


class Node{
public:
ll data;
Node* parent;
int rank;

Node(ll d){
    data=d;
    rank=0;
}

};
unordered_map<ll,Node*>m;

///creating individual elements set

void makeset(ll d){
Node *n=new Node(d);
n->parent=n;
m[d]=n;
}


/// finding parent in the set
Node* findset(Node*node){
if(node->parent==node){
    return node;
}
node->parent=findset(node->parent);///here path compression takes place
return node->parent;
}


Node* findset(ll n){
Node* node=m[n];
return findset(node);
}



/// union in the set
void unionset(ll d1,ll d2){
Node*node1=m[d1];
Node*node2=m[d2];

Node*parent1=findset(node1);
Node*parent2=findset(node2);
if(parent1->rank>=parent2->rank){
    parent1->rank=(parent1->rank==parent2->rank)?(parent1->rank+1):(parent1->rank);
    parent2->parent=parent1;
}
else{
    parent1->parent=parent2;
}

}



int main(){
makeset(1);
makeset(2);
makeset(3);
makeset(4);
makeset(5);
makeset(6);
makeset(7);

unionset(1,2);
unionset(2,3);
unionset(4,5);
unionset(6,7);
unionset(5,6);
unionset(3,7);

cout<<findset(1)->data<<endl;
cout<<findset(2)->data<<endl;
cout<<findset(3)->data<<endl;
cout<<findset(4)->data<<endl;
return 0;
}
