#include<iostream>
#include<queue>
using namespace std;

class BTNode{
public:
    int data;
    BTNode*left;
    BTNode*right;

    BTNode(int d)
    {
        data = d;
        left = right = NULL;
    }
};

BTNode* takeInputLevelOrder(){
    int d;
    cout<<"Enter the data for root Node";
    cin>>d;

    queue<BTNode*> q;
    BTNode* root = new BTNode(d);
    q.push(root);

    while(!q.empty()){
        BTNode* f =  q.front();
        q.pop();
        cout<<"Enter children of "<<f->data<<endl;
        int d1,d2;
        cin>>d1>>d2;
        if(d1!=-1){
            f->left = new BTNode(d1);
            q.push(f->left);
        }
        if(d2!=-1){
            f->right = new BTNode(d2);
            q.push(f->right);
        }

    }
    return root;
}
int count(BTNode*root){
    if(root==NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}
int height(BTNode* root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left,right);
}
int diameter(BTNode* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1,max(option2,option3));
}
class hdPair{
public:
    int height;
    int diameter;
};

hdPair diameterFast(BTNode* root){
    hdPair p;
    if(root==NULL){
        p.height =0;
        p.diameter = 0;
        return p;
    }
    ///Recursive Case
    hdPair left = diameterFast(root->left);
    hdPair right = diameterFast(root->right);

    p.height = max(left.height,right.height)+1;
    int option1 = left.height + right.height;
    int option2 = left.diameter;
    int option3 = right.diameter;

    p.diameter = max(option1,max(option2,option3));
    return p;
}


void printLevelOrder(BTNode*root){

    queue<BTNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        BTNode*f = q.front();
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
void mirror(BTNode* root){
    if(root==NULL){
        return ;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}




int main(){
    BTNode*root = takeInputLevelOrder();
    printLevelOrder(root);
    mirror(root);
    printLevelOrder(root);
    cout<<"Height of Tree is "<<height(root)<<endl;
    cout<<"Diameter of Tree is "<<diameter(root)<<endl;

return 0;
}
