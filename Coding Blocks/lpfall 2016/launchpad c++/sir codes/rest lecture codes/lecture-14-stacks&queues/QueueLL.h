#ifndef QUEUE_LL_H
#define QUEUE_LL_H

class Node{
public:
    int data;
    Node * next;
    Node(int d):data(d),next(NULL){}
};

class QueueLL{
    Node*head;
    Node*tail;
    int current_size;

public:
    QueueLL(){
        head= tail =NULL;
        current_size =0;
    }
    void push(int d){
        if(head==NULL){
            head =tail = new Node(d);
        }
        else{
            tail->next = new Node(d);
            tail = tail->next;
        }
        current_size++;
    }
    void pop(){
        if(current_size>0){
        Node*temp = head;
        head = head->next;
        delete temp;
        current_size--;
        }
    }
    int getFront(){
        return head->data;
    }
    bool isEmpty(){
        return head==NULL?true:false;
    }
    ~QueueLL(){

    }
};



#endif // QUEUE_LL_H
