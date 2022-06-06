#ifndef HASH_NODE_H
#define HASH_NODE_H
#include<cstring>
using namespace std;

template <typename V>
class hashNode{
public:
    char *key;
    V value;
    hashNode<V>* next;

    hashNode(char *key,V value){
        this->key = new char[strlen(key)+1];
        strcpy(this->key,key);
        this->value = value;
        next = NULL;
    }
    ~hashNode(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        delete [] key;
    }
};

#endif // HASH_NODE_H
