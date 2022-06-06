#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node*prev;

    Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

Node*head=NULL;
Node*tail=NULL;

void pushFront(int data){
    Node*temp=new Node(data);

    if(head==NULL){
        head=tail=temp;
        return;
    }
    head->prev=temp;
    temp->next=head;
    head=temp;
}
void pushBack(int data){
    Node*temp=new Node(data);
    if(head==NULL){
        head=tail=temp;
        return;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
void pop(Node*t){
if(head==NULL)
    return;

if(t->next==NULL){
    return;
}
Node*prev=t->prev;
Node*next=t->next;

if(prev==NULL){
    head=next;
    tail->next=t;
    t->next=NULL;
    tail=t;
}

else{
//    cout<<prev->data<<endl;
    prev->next=next;
    tail->next=t;
    t->next=NULL;
    tail=t;
}

}


int main(){

pushFront(3);
pushFront(2);
pushFront(1);
//pushBack(4);
Node*temp=head;
Node*te=head;
while(te){
    cout<<te->data<<" ";
    te=te->next;
}
cout<<endl;
//temp=temp->next;
cout<<temp->data<<endl;
pop(temp);
Node*t=head;
while(t){
    cout<<t->data<<" ";
    t=t->next;
}

return 0;
}
