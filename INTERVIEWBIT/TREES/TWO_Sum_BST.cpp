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


bool twosum(node*root,int sum){

if(root==NULL)
    return false;

bool a=false,b=false;
int val1,val2;
stack<node*>x;
stack<node*>y;

node*curr1=root;
node*curr2=root;

while(1){

    while(a==false){
        if(curr1){
            x.push(curr1);
            curr1=curr1->left;
        }
        else{
            if(x.empty()){
                a=true;
            }
            else{
                node*temp=x.top();
                x.pop();
                val1=temp->data;
                curr1=temp->right;
                a=true;
            }
        }
    }

    while(b==false){
        if(curr2){
            y.push(curr2);
            curr2=curr2->right;
        }
        else{
            if(y.empty()){
                b=true;
            }
            else{
                node*temp=y.top();
                y.pop();
                val2=temp->data;
                curr2=temp->left;
                b=true;
            }

        }
    }

    if(val1!=val2 && val1+val2==sum)
        return true;
    else if(val1+val2<sum){
        a=false;
    }
    else if(val1+val2>sum){
        b=false;
    }

    if(val1>=val2)
        return false;


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
iterative_inorder(root);

if(twosum(root,3)){
    cout<<"yahoo"<<endl;
}
    return 0;
}


