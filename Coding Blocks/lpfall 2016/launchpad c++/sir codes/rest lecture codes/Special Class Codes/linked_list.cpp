#include<iostream>
using namespace std;


///This just defines the structure of each node
struct Node{
    int data;
    Node*next;
};
///Actual Functions
Node* createNode(int d){
    Node *n = new Node;
    n->data = d;
    n->next = NULL;
    return n;
}
//--------------Take Input
Node* takeInput(){

    int data;
    Node* head=NULL;

    cin>>data;
    while(data!=-1){
        if(head==NULL){
            Node* n = createNode(data);
            head = n;
        }
        else{
            Node* n = createNode(data);
            n->next = head;
            head = n;
        }
        cin>>data;
    }
    return head;
}
void insertAtEnd(Node *head,int data){
    while(head->next!=NULL){
        head = head->next;
    }
    head->next= createNode(data);
    return;
}
void insertAtFront(Node*&head,int data){
    if(head==NULL){
        head = createNode(data);
    }
    else{
        Node *n = createNode(data);
        n->next = head;
        head = n;
    }

}
void  insertInMiddle(Node *&head,int data,int pos){
    if(pos==0){
        insertAtFront(head,data);
    }
    else{
        Node*temp = head;
        int count=0;
        while(count<pos-1){
            temp = temp->next;
            count++;
        }
        Node *n = createNode(data);
        n->next = temp->next;
        temp->next =n;
    }


}
void print(Node *head){

    while(head!=NULL){
        cout<<head->data<<" -->";
        head = head->next;
    }
    cout<<endl;

}


int main(){
    Node*head = NULL;
    head = takeInput();
    insertAtEnd(head,100);
    insertInMiddle(head,200,3);
    print(head);
return 0;
}

