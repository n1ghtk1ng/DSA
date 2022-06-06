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


stack<node*>s;

void push_in_stack(node*root){
    while(root){
        s.push(root);
        root=root->left;
    }
}

node* BSTIterator(node *root) {
    push_in_stack(root);

}
bool hasnext(){
return s.empty()==true?false:true;
}

int next() {
    node*temp=s.top();
    s.pop();

    int val=temp->data;
    push_in_stack(temp->right);
    return val;
}


int main(){

int arr[]={1,2,3,4,5,6,7};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
//traversal(root);
cout<<endl;
BSTIterator(root);
while(hasnext()){
    cout<<next()<<endl;
}

    return 0;
}

