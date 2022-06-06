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


traversal(t->left);
cout<<t->data<<" ";
traversal(t->right);
}

void iterative_inorder(node*root){

stack<node*>s;
node*curr=root;

while(1){

if(curr!=NULL){
    s.push(curr);
    curr=curr->left;
}
else{
    if(s.empty()){
        break;
    }
    node*temp=s.top();
    s.pop();
    cout<<temp->data<<" ";
    curr=temp->right;
}
}

}

node* fun(node* A){

    if(A->left==NULL && A->right==NULL)
    return A;

    node*l=NULL;
    node*r=NULL;
    if(A->left)
        l=fun(A->left);
    if(A->right)
        r=fun(A->right);
    node*t=A->right;
    if(l!=NULL){
        A->right=A->left;
        l->right=t;
    }


    if(r!=NULL)
    return r;
    else
    return l;

}

int main(){

int arr[]={3,5,4,7,6};
node*root=NULL;
for(int i=0;i<5;i++){
    root=buildtree(arr[i],root);
}
traversal(root);
cout<<endl;
iterative_inorder(root);
cout<<endl;
fun(root);
while(root){
    cout<<root->data<<" ";
    root=root->right;
}
    return 0;
}

