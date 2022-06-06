#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d):data(d),next(NULL){}
};

Node* takeInput(){
    int data;
    Node* head=NULL;

    cin>>data;
    while(data!=-1){
        Node* n = new Node(data);
        n->next = head;
        head = n;

        cin>>data;
    }
    return head;
}
int getSize(Node *head){
    int count=0;
    while(head){
        count++;
        head= head->next;
    }
    return count;
}

void bubbleSort(Node *&head){

    int n = getSize(head);

    for(int i=0;i<n;i++){
        Node* current = head;
        Node*prev = NULL;
        while(current!=NULL&&current->next!=NULL){
            if(current->data> current->next->data){
                if(prev==NULL){
                    Node *N = current->next;
                    current->next = N->next;
                    N->next = current;
                    head = N;
                    prev = N;

                }
                else{
                    Node* N = current->next;
                    prev->next = N;
                    current->next = N->next;
                    N->next = current;
                    prev = N;
                }
            }
            else{
                prev = current;
                current = current->next;

            }

        }
    }
}

void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node* findMid(Node*head){

    if(head==NULL||head->next==NULL){
            return head;
    }
    Node*fast = head->next;
    Node * slow =head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *a,Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node *newHead;
    if(a->data < b->data){
        newHead = a;
        newHead->next = merge(a->next,b);
    }
    else{
        newHead = b;
        newHead->next = merge(a,b->next);
    }
    return newHead;
}
Node *mergeSort(Node*head){

    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Break into two parts from mid
    Node* mid = findMid(head);
    Node*a = head;
    Node*b = mid->next;
    mid->next = NULL;
    ///Recursively sort two parts
    a = mergeSort(a);
    b = mergeSort(b);
    ///Merge two parts and return new head
    Node* newHead = merge(a,b);
    return newHead;
}
void reverse(Node*&head){
    Node*prev = NULL;
    Node*current = head;
    Node*N;
    while(current!=NULL){
        ///Save the next Node
        N = current->next;

        ///Pointer Change for current's next
        current->next = prev;

        ///Update Prev and current for next iteration
        prev = current;
        current = N;
    }
    head = prev;

}

int main(){
Node *head1 = NULL;
head1 = takeInput();
print(head1);
//bubbleSort(head1);
head1= mergeSort(head1);
reverse(head1);
print(head1);

return 0;
}
