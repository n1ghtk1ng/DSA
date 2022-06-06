#include<bits/stdc++.h>
using namespace std;
//  Definition for binary tree
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };



pair<ListNode*,ListNode*>mid(ListNode*A){
    ListNode*fast=A->next;
    ListNode*slow=A;
    ListNode*prev=NULL;
    while(fast){
        fast=fast->next;

        if(fast){
            prev=slow;
            fast=fast->next;
            slow=slow->next;
        }
    }
    return make_pair(prev,slow);
}

TreeNode*sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
if(A==NULL)
return NULL;

pair<ListNode*,ListNode*>p=mid(A);
ListNode*head1=NULL;
if(p.first){
    head1=A;
    p.first->next=NULL;
}

ListNode*head2=p.second->next;
p.second->next=NULL;

TreeNode*root=new TreeNode(p.second->val);

root->left=sortedListToBST(head1);
root->right=sortedListToBST(head2);

return root;
}

void inorder(TreeNode*root){
if(root==NULL){
    return;
}
inorder(root->left);
cout<<root->val<<" ";
inorder(root->right);

}

int main(){

ListNode*head=new ListNode(1);
ListNode*t1=new ListNode(2);
//ListNode*t2=new ListNode(3);
//ListNode*t3=new ListNode(4);
head->next=t1;
//t1->next=t2;
//t2->next=t3;


TreeNode*root=sortedListToBST(head);
inorder(root);

return 0;
}
