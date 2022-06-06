#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class BTNode{
public:
    int data;
    BTNode* left;
    BTNode* right;
    BTNode(int d):data(d),left(NULL),right(NULL){}
};

BTNode* insertInTree(BTNode*root,int d){
    if(root==NULL){
        root = new BTNode(d);
        return root;
    }
    if(root->data > d ){
        root->left = insertInTree(root->left,d);
    }
    else{
        root->right = insertInTree(root->right,d);
    }
    return root;
}

BTNode* takeInput(){
    int d;
    cin>>d;
    BTNode* root=NULL;
    while(d!=-1){
            root = insertInTree(root,d);
            cin>>d;
    }
    return root;
}

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
BTNode* search(BTNode*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
bool areIdentical(BTNode*root1,BTNode*root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL) ){
        return false;
    }
    if(root1->data==root2->data && areIdentical(root1->left,root2->left)&&areIdentical(root1->right,root2->right)){
        return true;
    }
    else{
        return false;
    }
}
///------------------------Tree Traversals
void printPreorder(BTNode*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void inorderPrint(BTNode*root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<< root->data<<" ";
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
//------------Tree to linked list
class Pair{
public:
    BTNode*head;
    BTNode*tail;
};

Pair convertToLL(BTNode*root){
    Pair p;
    ///Base Case
    if(root->left==NULL && root->right==NULL){
            p.head = root;
            p.tail = root;
            return p;
    }
    else if(root->left!=NULL && root->right==NULL){
        Pair LeftLL = convertToLL(root->left);
        LeftLL.tail->right = root;

        p.head = LeftLL.head;
        p.tail = root;
        return p;
    }
    else if(root->left==NULL && root->right!=NULL){
            Pair RightLL = convertToLL(root->right);
            root->right = RightLL.head;

            p.head = root;
            p.tail = RightLL.tail;
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
bool isBST(BTNode*root, int minV = INT_MIN,int maxV = INT_MAX){
    if(root==NULL){
        return true;
    }
    bool isLeftBST = isBST(root->left,minV,root->data);
    bool isRightBST = isBST(root->right,root->data,maxV);

    if(root->data  <= maxV && root->data >minV && isLeftBST && isRightBST){
        return true;
    }
    else{
        return false;
    }
}

int main(){
BTNode* root = takeInput();
printLevelOrder(root);
cout<<endl;
printPreorder(root);
cout<<endl;
inorderPrint(root);
cout<<endl;
postOrderPrint(root);
cout<<endl;


Pair ll = convertToLL(root);
BTNode*temp = ll.head;
while(temp!=NULL){
    cout<< temp->data <<"-->" ;
    temp = temp->right;
}

if(isBST(root)){
    cout<<"YES It's a BST";
}
else{
    cout<<"Not a BST ";
}
return 0;
}
