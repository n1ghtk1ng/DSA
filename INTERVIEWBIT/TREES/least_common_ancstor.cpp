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

bool xa;
bool xb;
node* fun(node*root,int a,int b){
    if(root==NULL)
        return NULL;

    if(root->data==a || root->data==b){
        if(root->data==a){
            xa=true;
        }
        else{
            xb=true;
        }
        return root;
    }
    node*x1=fun(root->left,a,b);
    node*x2=fun(root->right,a,b);

    if(x1 && x2){
        return root;
    }
    if(x1){
        return x1;
    }
    if(x2){
        return x2;
    }
    return NULL;

}
bool findnode(node*root,int d){
    if(root==NULL)
    return false;

    if(root->data==d || findnode(root->left,d) || findnode(root->right,d))
    return true;

    return false;
}
int lca(node* A, int B, int C) {
    xa=false;
    xb=false;
    node*lca=fun(A,B,C);
//    cout<<"lca = "<<lca->data<<endl;
//    cout<<"xa = "<<xa<<" xb = "<<xb<<endl;
    if(lca==NULL)
    return -1;

    if(xb==true && xa==true){
        return lca->data;
    }
    else if(xb==true){
        if(findnode(lca,B))
        return lca->data;
    }
    else if(xa==true){
        if(findnode(lca,C)){
            return lca->data;
        }

    }
    return -1;


}




int main(){

int arr[]={1,2,3,4,5,6,7};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
//traversal(root);
//cout<<endl;
//iterative_inorder(root);
cout<<lca(root,2,8);
    return 0;
}


