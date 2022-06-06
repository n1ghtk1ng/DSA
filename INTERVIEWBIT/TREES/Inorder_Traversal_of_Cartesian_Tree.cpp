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

node*fun(node*root,auto x,auto y){

if(x>=y)
    return NULL;

int maxi=INT_MIN;
auto idx=x;
for(auto it=x;it!=y;it++){
    if(*it>maxi){
        maxi=*it;
        idx=it;
    }

}

root=new node(maxi);

root->left=fun(root->left,x,idx);
root->right=fun(root->right,idx+1,y);

return root;

}


node*buildTree(vector<int> &A) {
    node*root=NULL;

    root=fun(root,A.begin(),A.end());
cout<<root->data<<endl;
cout<<root->left->data<<endl;
cout<<root->right->data<<endl;
    return root;

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

int main(){

int arr[]={1,2,3,4,5,6,7};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
vector<int>v={2,3,1,5,4};
node*root2=buildTree(v);
traversal(root2);
    return 0;
}


