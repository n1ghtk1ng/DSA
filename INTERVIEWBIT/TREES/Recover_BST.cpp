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

void fun(node**prev,node**a,node**b,node**c,node*root){

if(root){
    cout<<"hi "<<root->data<<endl;
    fun(prev,a,b,c,root->left);

    if(*prev!=NULL && (*prev)->data>root->data){
        if(a==NULL){
            *a=*prev;
            *b=root;
        }
        else{
            *c=root;
        }
    }
    *prev=root;

    fun(prev,a,b,c,root->right);
}

}

vector<int>recoverTree(node* A) {
    node*prev=NULL;
    node*a=NULL;
    node*b=NULL;
    node*c=NULL;

    fun(&prev,&a,&b,&c,A);
    cout<<"hi"<<endl;
    vector<int>ans;
    if(c==NULL){
        ans.push_back(min(a->data,b->data));
        ans.push_back(max(a->data,b->data));
    }
    else{
        ans.push_back(c->data);
        ans.push_back(a->data);
    }
    return ans;

}

int main(){

int arr[]={5,2,7,1,3,6,8};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
root->left->data=7;
root->right->data=2;
//traversal(root);
//cout<<endl;
//iterative_inorder(root);
vector<int>v=recoverTree(root);

for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
}

    return 0;
}


