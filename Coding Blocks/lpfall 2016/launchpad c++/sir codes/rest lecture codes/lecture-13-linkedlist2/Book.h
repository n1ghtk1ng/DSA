#include<iostream>
#include<cstring>
using namespace std;

class Book{
public:
    char name[20];
    int price;

    Book(char *n,int p){
        strcpy(name,n);
        price = p;
    }
    void print(){
        cout<<"Book Name is "<<name<<endl;
        cout<<"Price : "<<price<<endl <<endl;
    }

};
