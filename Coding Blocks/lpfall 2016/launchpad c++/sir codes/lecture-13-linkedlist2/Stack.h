#ifndef STACK_H
#define STACK_H


#include "Node.h"
template <typename T>
class Stack{

    Node<T>*head;
    int size;
public:
    Stack(){
        head=NULL;
        size =0;
    }
    void push(T d){
        Node<T>*n = new Node<T>(d);
        n->next = head;
        head =n;
        size++;
    }
    void pop(){
        if(size>0){
            Node<T>* n = head;
            head = head->next;
            delete n;
            size--;
        }
    }
    T top(){
        return head->data;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size>0?false:true;
    }
    ~Stack(){
            Node<T>*temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
    }
};

#endif // STACK_H

