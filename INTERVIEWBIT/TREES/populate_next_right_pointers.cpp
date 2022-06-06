#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node* next;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
        next=NULL;
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

node*temp=t;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;
traversal(t->left);
//traversal(t->right);

//cout<<t->data<<" ";
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
node*getnext(node*root){

node*temp=root->next;

while(temp!=NULL){
    if(temp->left)
        return temp->left;
    if(temp->right){
        return temp->right;
    }
    temp=temp->next;
}
return NULL;
}


void connect(node* A) {

if(A==NULL){
    return;
}
A->next=NULL;

while(A!=NULL){

    node*parent=A;

    while(parent!=NULL){
        if(parent->left){
            if(parent->right){
                parent->left->next=parent->right;
            }
            else{
                parent->left->next=getnext(parent);
            }
        }
        if(parent->right){
            parent->right->next=getnext(parent);
        }
        parent=parent->next;
    }
    if(A->left){
        A=A->left;
    }
    else if(A->right){
        A=A->right;
    }
    else{
        A=getnext(A);
    }

}

}



int main(){

int arr[]={5,2,7,1,3,6,8};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}

//cout<<endl;
//iterative_postorder(root);
connect(root);
traversal(root);
    return 0;
}








