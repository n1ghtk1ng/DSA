#include<iostream>
#include "hashtable.h"
using namespace std;

class Student{
public:
    char *name;
    int money;
    Student(){
        name = new char[2];
        name[0] ='\0';
        money = -1;
    }
    Student(char *n,int m){
        name = new char[strlen(n)+1];
        strcpy(name,n);
        money =m;
    }

};
int main(){

    hashTable<Student> ht;
    Student s1("Prateek",50);
    Student s2("Karan",40);
    Student s3("Vibhav",60);
    Student s4("Mayank",80);
    Student s5("CB",2000);

    ht.insert(s1.name,s1);
    ht.insert(s2.name,s2);
    ht.insert(s3.name,s3);
    ht.insert(s4.name,s4);

    char n[100];
    cin>>n;

    Student s = ht.find(n);

    if(s.money==-1){
        cout<<" Not Found"<<endl;
    }
    else{
        cout<< "Found !";
        cout<<s.name<<endl;
        cout<<s.money<<endl;
    }

    cout<<"Printing the hashTable "<<endl;
    ht.print();

    ht.insert(s5.name,s5);
    cout<<endl;

    ht.print();

return 0;
}
