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
TreeNode* levelOrderInput(){
    int d,c;
    queue<TreeNode*> q;

    cout<<"Enter root data ";
    cin>>d;
    TreeNode* root = new TreeNode(d);
    q.push(root);

    while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            cout<<"Enter the children count of "<<f->data<<" : ";
            cin>>c;
            f->children_count = c;
            f->children = new TreeNode*[c];

            for(int i=0;i<c;i++){
                    cout<<"Enter data for "<<i<<"th child of "<<f->data<<"  : ";
                    cin>>d;
                    f->children[i] = new TreeNode(d);
                    q.push(f->children[i]);

            }
    }

    return root;
}
int height(TreeNode* root){
    ///Base Case
        if(root==NULL){
            return 0;
        }


    ///Recursive Case
        int H = 0;
        for(int i=0;i<root->children_count;i++){
            int child_height = height(root->children[i]);
            if(child_height>H){
                H = child_height;
            }
        }
        return H+1;

}
TreeNode*largestNode(TreeNode*root){
    ///Base Case
        if(root==NULL){
            return NULL;
        }

    ///Recursive Case
        TreeNode* ans =root;

        for(int i=0;i<root->children_count;i++){
            TreeNode*ChildNode = largestNode(root->children[i]);
            if(ChildNode->data > ans->data){
                ans = ChildNode;
            }
        }
        return ans;
}
void levelOrderPrint(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* f = q.front();

        if(f==NULL){

                cout<< endl;
                q.pop();

                if(!q.empty()){
                    q.push(NULL);
                }
        }
        else{
            cout<< f->data<<" ";
            q.pop();

            for(int i=0;i< f->children_count;i++){
                q.push(f->children[i]);
            }
        }
    }
}
void printAtK(TreeNode*root,int k,int c=0){
    if(root==NULL){
        return;
    }
    if(c==k){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children_count;i++){
        printAtK(root->children[i],k,c+1);
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
    //TreeNode*root = buildTree();
    TreeNode*root = levelOrderInput();

    printTree(root);
    levelOrderPrint(root);
    cout<<"Height of Tree is "<<height(root)<<endl;



return 0;
}
