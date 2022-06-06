#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }

};

node* buildtree(int d,node* n){

if(n==NULL){
    node*temp=new node(d);
    return temp;
}
if(n->data<d){
    n->right=buildtree(d,n->right);
}
else{
    n->left=buildtree(d,n->left);
}
return n;
}
void traversal(node*t){
if(t==NULL)
    return;

cout<<t->data<<" ";
traversal(t->left);
traversal(t->right);
}

void iterative_preorder(node*root){

stack<node*>s;
s.push(root);

while(!s.empty()){
node*n=s.top();
s.pop();

cout<<n->data<<" ";
if(n->right)
    s.push(n->right);
if(n->left)
    s.push(n->left);

}

}

int main(){

int arr[]={1,2,3,4,5,6,7};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
traversal(root);
cout<<endl;
iterative_preorder(root);
    return 0;
}
