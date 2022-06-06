#ifndef QUEUE_H
#define QUEUE_H

class Queue{
    int *arr;
    int max_size;
    int current_size;
    int front;
    int rear;

public:
    Queue(){
        max_size = 4;
        current_size = 0;
        arr = new int[max_size];
        front =0 ;
        rear = max_size-1;
    }
    Queue(int init_size){
        max_size = init_size;
        current_size = 0;
        arr = new int[max_size];
        front =0 ;
        rear = max_size-1;
    }
    void push(int data){
        if(current_size<max_size){
            rear = (rear+1)%max_size;
            arr[rear] = data;
            current_size++;
        }

    }
    void pop(){
        if(current_size>0){
            front = (front+1)%max_size;
            current_size--;
        }
    }
    int getFront(){
        return arr[front];
    }
    bool isEmpty(){
        return current_size==0?true:false;
    }
    bool isFull(){
        return current_size==max_size?true:false;
    }
    ~Queue(){
        if(arr!=NULL){
            delete arr;
            arr = NULL;
        }
    }



};
#endif // QUEUE_H
