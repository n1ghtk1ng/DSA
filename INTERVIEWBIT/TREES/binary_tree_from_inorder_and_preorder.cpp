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
map<int,int>m;
node* fun(node*root,int i,int j,vector<int> &A, vector<int> &B){
    if(i>j)
        return NULL;
    if(i==j){
        node*temp=new node(A[i]);
        return temp;
    }

    int min_index=i;
    for(int k=i;k<=j;k++){
        if(m[A[k]]<m[A[min_index]]){
            min_index=k;
        }
    }
    //cout<<"maxindex = "<<max_index<<endl;
    root=new node(A[min_index]);
    //cout<<"root->data = "<<root->data<<endl;
    root->left=fun(root->left,i,min_index-1,A,B);
    root->right=fun(root->right,min_index+1,j,A,B);
    return root;


}
node* buildTree(vector<int> &A, vector<int> &B) {
    node*root=NULL;


    for(int i=0;i<B.size();i++){
        m[B[i]]=i;
    }

    root=fun(root,0,A.size()-1,A,B);
    return root;

}



int main(){

int arr[]={1,2,3,4,5,6,7};
node*root=NULL;
for(int i=0;i<7;i++){
    root=buildtree(arr[i],root);
}
traversal(root);
vector<int>A={4,2,5,1,6,3,7};
vector<int>B={1,2,4,5,3,6,7};
cout<<endl;
node*root2=buildTree(A,B);
traversal(root2);

    return 0;
}


