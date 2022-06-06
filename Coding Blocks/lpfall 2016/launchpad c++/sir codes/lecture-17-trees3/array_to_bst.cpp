#include<iostream>
#include<queue>
using namespace std;

class BTNode{
public:
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int d):data(d),left(NULL),right(NULL){}
};
void printLevelOrder(BTNode* root){
    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BTNode* f = q.front();
        if(f==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< f->data <<" ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

BTNode* makeBSTFromArray(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    else{
        int m = (s+e)/2;
        BTNode*root = new BTNode(a[m]);
        root->left = makeBSTFromArray(a,s,m-1);
        root->right =makeBSTFromArray(a,m+1,e);
        return root;
    }
}



int main(){
    int a[] = {1,2,3,4,5,6,7};
    BTNode*root = makeBSTFromArray(a,0,6);
    printLevelOrder(root);


}
