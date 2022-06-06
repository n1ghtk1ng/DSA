#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include<vector>
using namespace std;

class Priority_Queue{
    vector<int> v;
    int index;
    int current_size;

    void heapify(int i){
        int left = 2*i;
        int right = 2*i  + 1;
        int min_i = i;

        if(left<=current_size && v[left]<v[min_i]){
            min_i = left;
        }
        if(right<=current_size && v[right]<v[min_i]){
            min_i = right;
        }
        if(min_i!=i){
            swap(v[min_i],v[i]);
            heapify(min_i);
        }


    }

public:
    Priority_Queue(){
        index=1;
        v.push_back(-100000);
        current_size = 0;
    }
    void push(int d){
        v.push_back(d);
        index++;
        current_size++;

        int i = index - 1;
        while(i>1){
            int parent = i/2;
            if( v[parent] > v[i]){
                swap(v[parent],v[i]);
                i = parent;
            }
            else{
                break;
            }
        }
    }
        void pop(){

            swap(v[1],v[index-1]);
            v.pop_back();
            current_size--;
            index--;
            heapify(1);
        }

        int getMin(){
            if(current_size>0){
                return v[1];
            }
            return -100000;
        }
        bool isEmpty(){
            return current_size==0?true:false;
        }



};
#endif // PRIORITY_QUEUE_H
