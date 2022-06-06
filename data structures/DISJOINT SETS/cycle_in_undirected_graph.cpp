#include<bits/stdc++.h>
using namespace std;

vector<int>v[100];
bool visited[10][10];



class Node{
public:
int data;
Node* parent;
int rank;

Node(int d){
    data=d;
    rank=0;
}

};
unordered_map<int,Node*>m;

///creating individual elements set

void makeset(int d){
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


Node* findset(int n){
Node* node=m[n];
return findset(node);
}



/// union in the set
bool unionset(int d1,int d2){
Node*node1=m[d1];
Node*node2=m[d2];

Node*parent1=findset(node1);
Node*parent2=findset(node2);
if(parent1==parent2)
    return true;
if(parent1->rank>=parent2->rank){
    parent1->rank=(parent1->rank==parent2->rank)?(parent1->rank+1):(parent1->rank);
    parent2->parent=parent1;
}
else{
    parent1->parent=parent2;
}
return false;
}



int main(){

v[0].push_back(1);
v[1].push_back(0);
v[1].push_back(2);
v[2].push_back(1);
v[2].push_back(0);
v[0].push_back(2);

for(int i=0;i<=3;i++){
    makeset(i);
}

for(int i=0;i<=3;i++){
    for(int j=0;j<v[i].size();j++){
        visited[i][j]=false;
    }
}

int flag=0;
for(int i=0;i<=3;i++){
    for(int j=0;j<v[i].size();j++){

        if(visited[i][v[i][j]]==false){

            if(unionset(i,v[i][j])==true){
                flag=1;
                break;
            }
            visited[i][v[i][j]]=true;
            visited[v[i][j]][i]=true;
        }
    }

    if(flag==1)
        break;
}
if(flag==1){
    cout<<"CYCLE FOUND"<<endl;
}
else if(flag==0){
    cout<<"NO CYCLE FOUND"<<endl;
}

return 0;
}
