#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node*left;
    Node*right;

    Node(int d):data(d),left(NULL),right(NULL){}
};
unordered_map<int,vector<int> > verticalMap;

void verticalPrint(Node*root,int d=0){
    if(root==NULL){
        return;
    }
    verticalMap[d].push_back(root->data);
    verticalPrint(root->left,d-1);
    verticalPrint(root->right,d+1);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    root->left->right = new Node(5);
    root->left->right->right = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int min_key = -2;
    int max_key = 2;
    verticalPrint(root);

    for(int keys=min_key;keys<=max_key;keys++){
        auto it = verticalMap[keys].begin();
        while(it!=verticalMap[keys].end()){
            cout<< *it <<" ";

        it++;
        }
        cout<<endl;
    }

return 0;
}
