#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "hashnode.h"
#include<cstring>
template<typename V>
class hashTable{

    int tableSize;
    int currentSize;
    hashNode<V> **buckets;

    int hashFn(char *key){
        int ans = 0;
        int currentPower = 1;
        int L = strlen(key);
        for(int i=0;i<L;i++){
            ans += currentPower*key[L-i-1];
            currentPower *= 37;
            currentPower %= tableSize;
            ans %= tableSize;
        }
        return ans%tableSize;

    }
    void rehash(){
        cout<<"In Rehash " <<endl;
        int oldTableSize = tableSize;
        hashNode<V>** oldBuckets = buckets;
        currentSize = 0;
        tableSize *= 2;
        buckets = new hashNode<V>*[tableSize];
        for(int i=0;i<tableSize;i++){
            buckets[i] = NULL;
        }
        for(int i=0;i<oldTableSize;i++){

            hashNode<V>* temp = oldBuckets[i];
            while(temp!=NULL){
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldBuckets[i]!=NULL){
                delete oldBuckets[i];
            }
        }
        delete [] oldBuckets;
    }
public:
    hashTable(){
        tableSize = 7;
        currentSize = 0;
        buckets = new hashNode<V>*[tableSize];
        for(int i=0;i<tableSize;i++){
            buckets[i] = NULL;
        }
    }
    void insert(char *key, V value){
        int hashIndex = hashFn(key);
        currentSize++;
        hashNode<V> *node = new hashNode<V>(key,value);
        node->next = buckets[hashIndex];
        buckets[hashIndex] = node;

        float load_factor = float(currentSize)/tableSize;
        if(load_factor>0.7){
            cout<<"Load factor is "<<load_factor<<endl;
            rehash();
        }
    }
    V find(char *key){
        int hashIndex = hashFn(key);
        hashNode<V> *head = buckets[hashIndex];
        while(head!=NULL){
            if(strcmp(key,head->key)==0){
                return head->value;
            }
            head = head->next;
        }
        V v;
        return v;
    }
    void print(){

        for(int i=0;i<tableSize;i++){
            cout<<"Bucket "<<i <<"->";
            if(buckets[i]!=NULL){
                hashNode<V>* head= buckets[i];
                while(head!=NULL){
                        cout<<head->key<<"-> ";
                        cout<<head->value;
                        head = head->next;
                }
            }
            cout<<endl;
        }
    }
    void remove(char *key){
    ///HomeWork

    }
    ~hashTable(){
        for(int i=0;i<tableSize;i++){
            if(buckets[i]!=NULL){
                delete buckets[i];
            }
        }
        delete [] buckets;
    }
};


#endif // HASH_TABLE_H
