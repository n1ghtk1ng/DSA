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
traversal(t->right);

cout<<t->data<<" ";
}

void iterative_postorder(node*root){

stack<node*>s;
node*curr=root;

while(!s.empty() || curr!=NULL){

if(curr!=NULL){
    s.push(curr);
    curr=curr->left;
}
else{
    node*temp=s.top()->right;
    if(temp!=NULL){
        curr=temp;
    }
    else{
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        while(!s.empty() && s.top()->right==temp ){
            temp=s.top();
            cout<<temp->data<<" ";
            s.pop();
        }
    }

}
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
iterative_postorder(root);
    return 0;
}


