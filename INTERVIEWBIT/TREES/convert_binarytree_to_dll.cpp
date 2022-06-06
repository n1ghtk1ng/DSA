//Given a Balanced Binary Search Tree (BST), write a function isTripletPresent()
// that returns true if there is a triplet in given BST with sum equals to 0, otherwise returns false.
// Expected time complexity is O(n^2) and only O(Logn) extra space can be used.
// You can modify given Binary Search Tree.
// Note that height of a Balanced BST is always O(Logn)

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

void convert(node*root,node**head,node**tail){

    if(root==NULL)
        return;

    if(root->left){
        convert(root->left,head,tail);
    }
    //--------------//
    root->left=*tail;
    if(*tail){
        (*tail)->right=root;
    }
    else{
        *head=root;
    }
    *tail=root;
    //---------------//

    if(root->right){
        convert(root->right,head,tail);
    }


}


int main(){

int arr[]={5,2,8,1,3,6,9};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
//traversal(root);
//cout<<endl;
//iterative_inorder(root);

node*head=NULL;
node*tail=NULL;
convert(root,&head,&tail);
node*temp=head;
while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->right;
}

    return 0;
}


