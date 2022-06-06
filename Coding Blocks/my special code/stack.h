#ifndef STACK_H
#define STACK_H
#include "node.h"

template<typename T>

class stack
{
public:
    node<T>*head;
    node<T>*tail;
    int size;
    stack()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    void push(T d)
    {
        if(head==NULL)
        {
            head=tail=new node<T>(d);
            size++;
        }

        else
        {
            node<T>*t=new node<T>(d);
            t->next=head;
            head=t;
            size++;
        }
    }
    void pop()
    {
        node<T>*t=head;
        head=t->next;
        delete t;
        size--;
    }
    T top()
    {
        return head->data;
    }

    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size>0?false:true;
    }

    ~stack()
    {
        node<T>*t=head;
        while(head)
        {
            head=head->next;
            delete head;
            t=head;
        }

    }

};

#endif // STACK_H
