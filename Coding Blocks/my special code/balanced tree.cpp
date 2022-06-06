#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T> * left;
    Node<T> * right;
    Node(T d):data(d),left(NULL),right(NULL){}
};
typedef pair<bool, int> bi;

bi isBalanced(Node<int>* root){
   //complete your function here
bi p;
if(root==NULL)
{
    p.first=true;
    p.second=0;
    return p;
}

bi p1=isBalanced(root->left);
bi p2=isBalanced(root->right);
    if(p1.first && p2.first && p1.second-p2.second<=1)
    {
       p.first=true;
        p.second=max(p1.second,p2.second);
        return p;
    }


}
