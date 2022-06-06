#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode** children;
    int children_count;

    TreeNode(int d){
        data = d;
        children_count = 0;
        children = NULL;
    }
    TreeNode(int d,int c){
        data = d;
        children_count = c;
        children = new TreeNode*[c];
    }
};
TreeNode* buildTree(){

    int d,c;
    cout<<"Enter the data & children count ";
    cin>>d>>c;

    TreeNode* root = new TreeNode(d,c);

    for(int i=0;i<c;i++){
        root->children[i] = buildTree();
    }
    return root;
}
void printTree(TreeNode* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" -> ";
    for(int i=0;i<root->children_count;i++){
        cout<< root->children[i]->data<<" , ";
    }
    cout<<endl;

    for(int i=0;i<root->children_count;i++){
        //cout<< root->children[i]->data<<" , ";
        printTree(root->children[i]);
    }
}
void levelOrderPrint(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* f = q.front();
        cout<< f->data<<" ";
        q.pop();

        for(int i=0;i< f->children_count;i++){
            q.push(f->children[i]);
        }
    }
}

int main(){
    /*
    TreeNode * root = new TreeNode(1,2);
    root->children[0] = new TreeNode(2);
    root->children[1] = new TreeNode(3);

    cout<< root->data <<endl;
    cout<< root->children[0]->data;
    cout<< root->children[1]->data <<endl;
    */
    TreeNode*root = buildTree();
    printTree(root);
    levelOrderPrint(root);


return 0;
}
