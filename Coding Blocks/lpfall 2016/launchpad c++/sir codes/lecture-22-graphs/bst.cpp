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
///--------------BINARY SEARCH TREES
BTNode* insertInTree(BTNode* root,int d){
    if(root==NULL){
        root = new BTNode(d);
        return root;
    }
    if(root->data <= d){
        root->right = insertInTree(root->right,d);
    }
    else{
        root->left = insertInTree(root->left,d);
    }
    return root;
}
BTNode* takeInput(){
    int d;
    cin>>d;
    BTNode* root = NULL;
    while(d!=-1){
        root = insertInTree(root,d);
        cin>>d;
    }
    return root;
}
void preOrderPrint(BTNode*root){
    if(root==NULL){
        return ;
    }
    cout<< root->data <<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
void inorderPrint(BTNode* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
void postOrderPrint(BTNode*root){
    if(root==NULL){
        return;
    }
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";
}
BTNode*search(BTNode*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    else if(root->data < key){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
void printRange(BTNode*root,int k1,int k2){


}
//---------------------Tree to Linked List
class Pair{
public:
    BTNode* head;
    BTNode* tail;
};

Pair convertToLL(BTNode* root){
    Pair p;
    if(root->left==NULL && root->right==NULL){
        p.head = root;
        p.tail = root;
        return p;
    }
    else if(root->left!=NULL && root->right==NULL){
            Pair leftLL = convertToLL(root->left);
            leftLL.tail->right = root;

            p.head = leftLL.head;
            p.tail = root;
            return p;
    }
    else if(root->right!=NULL && root->left==NULL){
            Pair rightLL = convertToLL(root->right);
            root->right = rightLL.head;

            p.head = root;
            p.tail = rightLL.tail;
            return p;

    }
    else{
        Pair leftLL = convertToLL(root->left);
        Pair rightLL = convertToLL(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        p.head = leftLL.head;
        p.tail = rightLL.tail;
        return p;
    }
}

bool isBST(BTNode* root,int minV= INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    bool isLeftBST = isBST(root->left,minV,root->data);
    bool isRightBST = isBST(root->right,root->data,maxV);

    if(root->data >minV && root->data < maxV && isLeftBST && isRightBST){
        return true;
    }
    else{
        return false;
    }
}
BTNode* buildTree(int a[],int s,int e){
    if(s>e){
        return NULL;
    }
    else{
        int mid = (s+e)/2;
        BTNode* root = new BTNode(a[mid]);
        root->left = buildTree(a,s,mid-1);
        root->right = buildTree(a,mid+1,e);
        return root;
    }
}


int main(){
/*
BTNode*root = takeInput();
printLevelOrder(root);
cout<<endl;
preOrderPrint(root);
cout<<endl;
inorderPrint(root);
cout<<endl;
postOrderPrint(root);
*/
cout<<endl;
/*
Pair ll = convertToLL(root);
BTNode*temp = ll.head;
while(temp!=NULL){
    cout<< temp->data <<"-->";
    temp = temp->right;
}
cout<<endl;
*/
int a[] = {1,2,3,4,5,6,7};
BTNode* tree = buildTree(a,0,6);
printLevelOrder(tree);

if(isBST(tree)){
    cout<<"It's a BST"<<endl;
}
else{
    cout<<"Not a BST"<<endl;
}

return 0;
}
